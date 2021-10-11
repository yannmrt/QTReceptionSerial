#include "QTReceptionSerial.h"

QTReceptionSerial::QTReceptionSerial(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// On instancie le Port S�rie
	port = new QSerialPort(this);
	QObject::connect(port, SIGNAL(readyRead()), this, SLOT(onSerialPortReadyRead()));
		port->setPortName("COM1");
		port->open(QIODevice::ReadWrite);
		port->setBaudRate(QSerialPort::Baud9600);
		port->setDataBits(QSerialPort::DataBits::Data8);
		port->setParity(QSerialPort::Parity::NoParity);
		port->setStopBits(QSerialPort::StopBits::OneStop);
		port->setFlowControl(QSerialPort::NoFlowControl);

	// On instancie la base de donn�e
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("192.168.64.201");
		db.setUserName("superuser");
		db.setPassword("superuser");
		db.setDatabaseName("TP1");

	// On v�rifie que la bdd est connect�e
	/*if (db.open()) {
		qDebug() << "bdd ok";
	} else {
		qDebug() << "bdd no";
	}*/
}

void QTReceptionSerial::onSerialPortReadyRead() 
{
	// On lit tout ce que le port s�rie re�ois
	QByteArray receiveTrame = port->readAll();

	// On met les donn�es dans la variable trame
	trame = trame + receiveTrame.toStdString().c_str();

	// On va v�rifier que la trame n'est pas vide
	if (trame.size() > 0) {

		// On lance la fonction decodeTrame(const QString trame) qui nous decode la trame
		decodeTrame(trame);
	}
}

void QTReceptionSerial::decodeTrame(const QString trame) {

	// Decodage de la trame
	QString horodatage;
	unsigned int heure, minute;
	double seconde;

	// d�coupe la trame avec le d�limiteur ',' et r�cup�re le deuxi�me champ
	horodatage = trame.section(',', 1, 1);

	// d�coupe une chaine � partir d'une position et un nombre de caract�res
	heure = horodatage.mid(0, 2).toInt();
	minute = horodatage.mid(2, 2).toInt();
	seconde = horodatage.mid(4, 2).toDouble();

	// On passe les valeurs dans des variables
	QString latitude;
	latitude = trame.section(',', 2, 2);

	QString longitude;
	longitude = trame.section(',', 4, 4);

	horodatage = QString::number(heure) + ":" + QString::number(minute)
		+ ":" + QString::number(seconde);

	// On affiche les donn�es
	qDebug() << "latitude : " << latitude;
	qDebug() << "longitude : " << longitude;
	qDebug() << "Horodatage : " << horodatage;

	// On va lancer inclure les donn�es en base de donn�e
	addTrameDb(latitude, longitude, horodatage);
}

void QTReceptionSerial::addTrameDb(const QString latitude, const QString longitude, const QString horodatage) 
{
	// On va v�rifier que les donn�es ne sont pas vides
	if (latitude.size() > 0, longitude.size() > 0, horodatage.size() > 0) {

		// On initialise le query bdd
		QSqlDatabase db = QSqlDatabase::database();
		QSqlQuery query(db);

		// On d�finie des valeurs de tests
		QString name = "nametest";
		QString idBoat = "1";

		QString requete = "INSERT INTO gps (latitude, longitude, horodatage, name, idBoat) VALUES ('" + latitude + "', '" + longitude + "', '" + horodatage + "', '" + name + "', '" + idBoat + "')";
		query.exec(requete);

	}
}
