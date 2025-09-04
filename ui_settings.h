/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppSettings
{
public:
    QLabel *targetDirLabel;
    QPlainTextEdit *targetPathTextEdit;
    QPushButton *SelectTargetButton;
    QLabel *outputDirLabel;
    QPushButton *selectOutputButton;
    QPlainTextEdit *plainTextEdit;
    QPushButton *saveButton;

    void setupUi(QWidget *AppSettings)
    {
        if (AppSettings->objectName().isEmpty())
            AppSettings->setObjectName("AppSettings");
        AppSettings->resize(317, 212);
        targetDirLabel = new QLabel(AppSettings);
        targetDirLabel->setObjectName("targetDirLabel");
        targetDirLabel->setGeometry(QRect(10, 10, 191, 31));
        QFont font;
        font.setPointSize(14);
        targetDirLabel->setFont(font);
        targetPathTextEdit = new QPlainTextEdit(AppSettings);
        targetPathTextEdit->setObjectName("targetPathTextEdit");
        targetPathTextEdit->setGeometry(QRect(10, 50, 291, 31));
        SelectTargetButton = new QPushButton(AppSettings);
        SelectTargetButton->setObjectName("SelectTargetButton");
        SelectTargetButton->setGeometry(QRect(210, 10, 91, 31));
        QFont font1;
        font1.setPointSize(10);
        SelectTargetButton->setFont(font1);
        outputDirLabel = new QLabel(AppSettings);
        outputDirLabel->setObjectName("outputDirLabel");
        outputDirLabel->setGeometry(QRect(10, 80, 211, 41));
        outputDirLabel->setFont(font);
        selectOutputButton = new QPushButton(AppSettings);
        selectOutputButton->setObjectName("selectOutputButton");
        selectOutputButton->setGeometry(QRect(210, 90, 91, 31));
        selectOutputButton->setFont(font1);
        plainTextEdit = new QPlainTextEdit(AppSettings);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(10, 130, 291, 31));
        saveButton = new QPushButton(AppSettings);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(210, 170, 91, 31));
        QFont font2;
        font2.setPointSize(11);
        saveButton->setFont(font2);

        retranslateUi(AppSettings);

        QMetaObject::connectSlotsByName(AppSettings);
    } // setupUi

    void retranslateUi(QWidget *AppSettings)
    {
        AppSettings->setWindowTitle(QCoreApplication::translate("AppSettings", "Settings", nullptr));
        targetDirLabel->setText(QCoreApplication::translate("AppSettings", "Select target directory:", nullptr));
        SelectTargetButton->setText(QCoreApplication::translate("AppSettings", "Select", nullptr));
        outputDirLabel->setText(QCoreApplication::translate("AppSettings", "Select output directory:", nullptr));
        selectOutputButton->setText(QCoreApplication::translate("AppSettings", "Select", nullptr));
        saveButton->setText(QCoreApplication::translate("AppSettings", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppSettings: public Ui_AppSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
