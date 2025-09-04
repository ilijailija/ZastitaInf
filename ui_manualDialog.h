/********************************************************************************
** Form generated from reading UI file 'manualDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALDIALOG_H
#define UI_MANUALDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <qfile.h>
#include <qdir.h>

QT_BEGIN_NAMESPACE

class Ui_DialogManual
{
public:
    QLabel *labelSelectedFile;
    QLabel *labelFile;
    QPlainTextEdit *fileContent;
    QPushButton *pushButtonEncrypt;
    QPushButton *pushButtonDecrypt;
    QPushButton *pushButtonCancel;

    void setupUi(QDialog *DialogManual)
    {
        if (DialogManual->objectName().isEmpty())
            DialogManual->setObjectName("DialogManual");
        DialogManual->resize(396, 293);
        labelSelectedFile = new QLabel(DialogManual);
        labelSelectedFile->setObjectName("labelSelectedFile");
        labelSelectedFile->setGeometry(QRect(10, 0, 161, 31));
        QFont font;
        font.setPointSize(14);
        labelSelectedFile->setFont(font);
        labelFile = new QLabel(DialogManual);
        labelFile->setObjectName("labelFile");
        labelFile->setGeometry(QRect(10, 30, 121, 21));
        QFont font1;
        font1.setPointSize(12);
        labelFile->setFont(font1);
        fileContent = new QPlainTextEdit(DialogManual);
        fileContent->setObjectName("fileContent");
        fileContent->setGeometry(QRect(10, 60, 371, 181));
        pushButtonEncrypt = new QPushButton(DialogManual);
        pushButtonEncrypt->setObjectName("pushButtonEncrypt");
        pushButtonEncrypt->setGeometry(QRect(10, 250, 141, 31));
        pushButtonDecrypt = new QPushButton(DialogManual);
        pushButtonDecrypt->setObjectName("pushButtonDecrypt");
        pushButtonDecrypt->setGeometry(QRect(160, 250, 141, 31));
        pushButtonCancel = new QPushButton(DialogManual);
        pushButtonCancel->setObjectName("pushButtonCancel");
        pushButtonCancel->setGeometry(QRect(310, 250, 71, 31));

        retranslateUi(DialogManual);

        QMetaObject::connectSlotsByName(DialogManual);
    } // setupUi

    void retranslateUi(QDialog *DialogManual)
    {
        DialogManual->setWindowTitle(QString());
        labelSelectedFile->setText(QCoreApplication::translate("DialogManual", "Selected File:", nullptr));
        labelFile->setText(QCoreApplication::translate("DialogManual", "xxyyzz", nullptr));
        pushButtonEncrypt->setText(QCoreApplication::translate("DialogManual", "Encrypt", nullptr));
        pushButtonDecrypt->setText(QCoreApplication::translate("DialogManual", "Decrypt", nullptr));
        pushButtonCancel->setText(QCoreApplication::translate("DialogManual", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogManual: public Ui_DialogManual {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALDIALOG_H
