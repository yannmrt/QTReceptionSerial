#include <QtWidgets/QMainWindow>
#include "ui_QTReceptionSerial.h"

#include <qDebug>

// On inclus les d�pendances n�cessaires au port s�rie
#include <QSerialPort>
#include <QSerialPortInfo>

// On inclus les d�pendances pour SQL
#include <QtSql/QtSql>
#include <QSqlQuery>
#include <QtSql>


#include <iostream>


class QTReceptionSerial : public QMainWindow
{
    Q_OBJECT

public:
    QTReceptionSerial(QWidget *parent = Q_NULLPTR);

private:
    Ui::QTReceptionSerialClass ui;

	// On instancie le pointeur pour le port s�rie
	QSerialPort *port;

	// On instancie les pointeurs pour la base de donn�es
	QSqlDatabase *db;
	QSqlQuery *query;

	// on instancie la variable trame utilis�e dans la classe reception
	QString trame;

private slots:
	void onSerialPortReadyRead();
	void decodeTrame(const QString trame);
	void addTrameDb(const QString latitude, const QString longitude, const QString horodatage);
};
