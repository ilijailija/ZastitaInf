/********************************************************************************
** Form generated from reading UI file 'enterDtKey.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERDTKEY_H
#define UI_ENTERDTKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dtEnterKey
{
public:
    QLabel *mainLabel;
    QPushButton *saveButton;
    QLabel *rowKeyLabel;
    QLineEdit *rowKeyLineEdit;
    QLabel *colKeyLabel;
    QLineEdit *colKeyLineEdit;

    void setupUi(QDialog *dtEnterKey)
    {
        if (dtEnterKey->objectName().isEmpty())
            dtEnterKey->setObjectName("dtEnterKey");
        dtEnterKey->resize(400, 203);
        mainLabel = new QLabel(dtEnterKey);
        mainLabel->setObjectName("mainLabel");
        mainLabel->setGeometry(QRect(10, 0, 241, 31));
        QFont font;
        font.setPointSize(14);
        mainLabel->setFont(font);
        saveButton = new QPushButton(dtEnterKey);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(290, 160, 75, 24));
        rowKeyLabel = new QLabel(dtEnterKey);
        rowKeyLabel->setObjectName("rowKeyLabel");
        rowKeyLabel->setGeometry(QRect(10, 40, 271, 16));
        QFont font1;
        font1.setPointSize(11);
        rowKeyLabel->setFont(font1);
        rowKeyLabel->setLineWidth(6);
        rowKeyLineEdit = new QLineEdit(dtEnterKey);
        rowKeyLineEdit->setObjectName("rowKeyLineEdit");
        rowKeyLineEdit->setGeometry(QRect(10, 70, 361, 22));
        colKeyLabel = new QLabel(dtEnterKey);
        colKeyLabel->setObjectName("colKeyLabel");
        colKeyLabel->setGeometry(QRect(10, 100, 301, 16));
        colKeyLabel->setFont(font1);
        colKeyLineEdit = new QLineEdit(dtEnterKey);
        colKeyLineEdit->setObjectName("colKeyLineEdit");
        colKeyLineEdit->setGeometry(QRect(10, 120, 361, 22));

        retranslateUi(dtEnterKey);

        QMetaObject::connectSlotsByName(dtEnterKey);
    } // setupUi

    void retranslateUi(QDialog *dtEnterKey)
    {
        dtEnterKey->setWindowTitle(QCoreApplication::translate("dtEnterKey", "Enter key", nullptr));
        mainLabel->setText(QCoreApplication::translate("dtEnterKey", "Double Transposition Key:", nullptr));
        saveButton->setText(QCoreApplication::translate("dtEnterKey", "Save", nullptr));
        rowKeyLabel->setText(QCoreApplication::translate("dtEnterKey", "Enter row keys (separated by a coma/','):", nullptr));
        colKeyLabel->setText(QCoreApplication::translate("dtEnterKey", "Enter column keys (separated by a coma/','):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dtEnterKey: public Ui_dtEnterKey {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERDTKEY_H
