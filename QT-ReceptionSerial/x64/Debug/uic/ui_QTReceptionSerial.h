/********************************************************************************
** Form generated from reading UI file 'QTReceptionSerial.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRECEPTIONSERIAL_H
#define UI_QTRECEPTIONSERIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTReceptionSerialClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTReceptionSerialClass)
    {
        if (QTReceptionSerialClass->objectName().isEmpty())
            QTReceptionSerialClass->setObjectName(QString::fromUtf8("QTReceptionSerialClass"));
        QTReceptionSerialClass->resize(600, 400);
        menuBar = new QMenuBar(QTReceptionSerialClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QTReceptionSerialClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTReceptionSerialClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QTReceptionSerialClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTReceptionSerialClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QTReceptionSerialClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTReceptionSerialClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QTReceptionSerialClass->setStatusBar(statusBar);

        retranslateUi(QTReceptionSerialClass);

        QMetaObject::connectSlotsByName(QTReceptionSerialClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTReceptionSerialClass)
    {
        QTReceptionSerialClass->setWindowTitle(QCoreApplication::translate("QTReceptionSerialClass", "QTReceptionSerial", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTReceptionSerialClass: public Ui_QTReceptionSerialClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRECEPTIONSERIAL_H
