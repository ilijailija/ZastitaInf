/********************************************************************************
** Form generated from reading UI file 'enterA52Key.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERA52KEY_H
#define UI_ENTERA52KEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE

class Ui_A52Dialog
{
public:
    QLabel *frameLabel;
    QLineEdit *frameLineEdit;
    QLabel *keyLabel;
    QLineEdit *keyLineEdit_1;
    QLineEdit *keyLineEdit_2;
    QLineEdit *keyLineEdit_3;
    QLineEdit *keyLineEdit_4;
    QLineEdit *keyLineEdit_5;
    QLineEdit *keyLineEdit_6;
    QLineEdit *keyLineEdit_7;
    QLineEdit *keyLineEdit_8;
    QPushButton *saveButton;

    void setupUi(QDialog *A52Dialog)
    {
        if (A52Dialog->objectName().isEmpty())
            A52Dialog->setObjectName("A52Dialog");
        A52Dialog->resize(451, 208);
        frameLabel = new QLabel(A52Dialog);
        frameLabel->setObjectName("frameLabel");
        frameLabel->setGeometry(QRect(10, 10, 101, 16));
        QFont font;
        font.setPointSize(14);
        frameLabel->setFont(font);
        frameLineEdit = new QLineEdit(A52Dialog);
        frameLineEdit->setObjectName("frameLineEdit");
        frameLineEdit->setGeometry(QRect(10, 40, 101, 22));
        keyLabel = new QLabel(A52Dialog);
        keyLabel->setObjectName("keyLabel");
        keyLabel->setGeometry(QRect(10, 70, 91, 31));
        keyLabel->setFont(font);
        keyLineEdit_1 = new QLineEdit(A52Dialog);
        keyLineEdit_1->setObjectName("keyLineEdit_1");
        keyLineEdit_1->setGeometry(QRect(10, 110, 101, 22));
        keyLineEdit_2 = new QLineEdit(A52Dialog);
        keyLineEdit_2->setObjectName("keyLineEdit_2");
        keyLineEdit_2->setGeometry(QRect(120, 110, 101, 22));
        keyLineEdit_3 = new QLineEdit(A52Dialog);
        keyLineEdit_3->setObjectName("keyLineEdit_3");
        keyLineEdit_3->setGeometry(QRect(230, 110, 101, 22));
        keyLineEdit_4 = new QLineEdit(A52Dialog);
        keyLineEdit_4->setObjectName("keyLineEdit_4");
        keyLineEdit_4->setGeometry(QRect(340, 110, 101, 22));
        keyLineEdit_5 = new QLineEdit(A52Dialog);
        keyLineEdit_5->setObjectName("keyLineEdit_5");
        keyLineEdit_5->setGeometry(QRect(10, 140, 101, 22));
        keyLineEdit_6 = new QLineEdit(A52Dialog);
        keyLineEdit_6->setObjectName("keyLineEdit_6");
        keyLineEdit_6->setGeometry(QRect(120, 140, 101, 22));
        keyLineEdit_7 = new QLineEdit(A52Dialog);
        keyLineEdit_7->setObjectName("keyLineEdit_7");
        keyLineEdit_7->setGeometry(QRect(230, 140, 101, 22));
        keyLineEdit_8 = new QLineEdit(A52Dialog);
        keyLineEdit_8->setObjectName("keyLineEdit_8");
        keyLineEdit_8->setGeometry(QRect(340, 140, 101, 22));
        saveButton = new QPushButton(A52Dialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(340, 170, 101, 31));

        retranslateUi(A52Dialog);

        QMetaObject::connectSlotsByName(A52Dialog);
    } // setupUi

    void retranslateUi(QDialog *A52Dialog)
    {
        A52Dialog->setWindowTitle(QCoreApplication::translate("A52Dialog", "Enter A5/2 key", nullptr));
        frameLabel->setText(QCoreApplication::translate("A52Dialog", "Enter frame:", nullptr));
        frameLineEdit->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0x21", nullptr));
        keyLabel->setText(QCoreApplication::translate("A52Dialog", "Enter keys:", nullptr));
        keyLineEdit_1->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0x00", nullptr));
        keyLineEdit_2->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xfc", nullptr));
        keyLineEdit_3->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        keyLineEdit_4->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        keyLineEdit_5->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        keyLineEdit_6->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        keyLineEdit_7->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        keyLineEdit_8->setPlaceholderText(QCoreApplication::translate("A52Dialog", "e.g. 0xff", nullptr));
        saveButton->setText(QCoreApplication::translate("A52Dialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A52Dialog: public Ui_A52Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERA52KEY_H
