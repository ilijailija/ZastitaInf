/********************************************************************************
** Form generated from reading UI file 'mainWindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW2_H
#define UI_MAINWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qfiledialog.h>
#include <qboxlayout.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QPushButton *pushButtonDT;
    QPushButton *pushButtonA52;
    QPushButton *pushButtonCFB;
    QLabel *labelSelectAlgorithm;
    QPushButton *buttonFSW;
    QPushButton *buttonManual;
    QPushButton *buttonSend;
    QPushButton *buttonRecieve;
    QPushButton *settingsButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(483, 350);
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 50, 461, 161));
        pushButtonDT = new QPushButton(groupBox);
        pushButtonDT->setObjectName("pushButtonDT");
        pushButtonDT->setGeometry(QRect(10, 10, 441, 41));
        pushButtonA52 = new QPushButton(groupBox);
        pushButtonA52->setObjectName("pushButtonA52");
        pushButtonA52->setGeometry(QRect(10, 60, 441, 41));
        pushButtonCFB = new QPushButton(groupBox);
        pushButtonCFB->setObjectName("pushButtonCFB");
        pushButtonCFB->setGeometry(QRect(10, 110, 441, 41));
        labelSelectAlgorithm = new QLabel(centralwidget);
        labelSelectAlgorithm->setObjectName("labelSelectAlgorithm");
        labelSelectAlgorithm->setGeometry(QRect(20, 10, 471, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(14);
        labelSelectAlgorithm->setFont(font1);
        buttonFSW = new QPushButton(centralwidget);
        buttonFSW->setObjectName("buttonFSW");
        buttonFSW->setGeometry(QRect(50, 230, 181, 41));
        buttonManual = new QPushButton(centralwidget);
        buttonManual->setObjectName("buttonManual");
        buttonManual->setGeometry(QRect(250, 230, 181, 41));
        buttonSend = new QPushButton(centralwidget);
        buttonSend->setObjectName("buttonSend");
        buttonSend->setGeometry(QRect(50, 280, 181, 41));
        buttonRecieve = new QPushButton(centralwidget);
        buttonRecieve->setObjectName("buttonRecieve");
        buttonRecieve->setGeometry(QRect(250, 280, 181, 41));
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");
        settingsButton->setGeometry(QRect(360, 10, 101, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(11);
        settingsButton->setFont(font2);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        pushButtonDT->setText(QCoreApplication::translate("MainWindow", "Double Transposition", nullptr));
        pushButtonA52->setText(QCoreApplication::translate("MainWindow", "A5/2", nullptr));
        pushButtonCFB->setText(QCoreApplication::translate("MainWindow", "Ciphertext Feedback", nullptr));
        labelSelectAlgorithm->setText(QCoreApplication::translate("MainWindow", "Select Algorithm:", nullptr));
        buttonFSW->setText(QCoreApplication::translate("MainWindow", "Turn FSW on", nullptr));
        buttonManual->setText(QCoreApplication::translate("MainWindow", "Select file manually", nullptr));
        buttonSend->setText(QCoreApplication::translate("MainWindow", "Send file", nullptr));
        buttonRecieve->setText(QCoreApplication::translate("MainWindow", "Recieve file", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW2_H
