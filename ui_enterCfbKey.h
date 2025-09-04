/********************************************************************************
** Form generated from reading UI file 'enterCfbKey.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERCFBKEY_H
#define UI_ENTERCFBKEY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <qmessagebox.h>

QT_BEGIN_NAMESPACE

class Ui_enterCfbDialog
{
public:
    QLabel *IvLabel;
    QLineEdit *ivLineEdit;
    QLabel *helpLabel;
    QLabel *frameLabel;
    QLineEdit *framLineEdit;
    QLabel *keysLabel;
    QLineEdit *keyLineEdit_1;
    QLineEdit *keyLineEdit_2;
    QLineEdit *keyLineEdit_3;
    QLineEdit *keyLineEdit_4;
    QLineEdit *keyLineEdit_5;
    QLineEdit *keyLineEdit_6;
    QLineEdit *keyLineEdit_7;
    QLineEdit *keyLineEdit_8;
    QPushButton *saveButton;

    void setupUi(QDialog *enterCfbDialog)
    {
        if (enterCfbDialog->objectName().isEmpty())
            enterCfbDialog->setObjectName("enterCfbDialog");
        enterCfbDialog->resize(452, 279);
        IvLabel = new QLabel(enterCfbDialog);
        IvLabel->setObjectName("IvLabel");
        IvLabel->setGeometry(QRect(10, 10, 221, 21));
        QFont font;
        font.setPointSize(14);
        IvLabel->setFont(font);
        ivLineEdit = new QLineEdit(enterCfbDialog);
        ivLineEdit->setObjectName("ivLineEdit");
        ivLineEdit->setGeometry(QRect(10, 60, 431, 22));
        helpLabel = new QLabel(enterCfbDialog);
        helpLabel->setObjectName("helpLabel");
        helpLabel->setGeometry(QRect(10, 40, 381, 16));
        QFont font1;
        font1.setPointSize(10);
        helpLabel->setFont(font1);
        frameLabel = new QLabel(enterCfbDialog);
        frameLabel->setObjectName("frameLabel");
        frameLabel->setGeometry(QRect(10, 90, 111, 21));
        frameLabel->setFont(font);
        framLineEdit = new QLineEdit(enterCfbDialog);
        framLineEdit->setObjectName("framLineEdit");
        framLineEdit->setGeometry(QRect(10, 120, 101, 22));
        keysLabel = new QLabel(enterCfbDialog);
        keysLabel->setObjectName("keysLabel");
        keysLabel->setGeometry(QRect(10, 150, 101, 31));
        keysLabel->setFont(font);
        keyLineEdit_1 = new QLineEdit(enterCfbDialog);
        keyLineEdit_1->setObjectName("keyLineEdit_1");
        keyLineEdit_1->setGeometry(QRect(10, 180, 101, 22));
        keyLineEdit_2 = new QLineEdit(enterCfbDialog);
        keyLineEdit_2->setObjectName("keyLineEdit_2");
        keyLineEdit_2->setGeometry(QRect(120, 180, 101, 22));
        keyLineEdit_3 = new QLineEdit(enterCfbDialog);
        keyLineEdit_3->setObjectName("keyLineEdit_3");
        keyLineEdit_3->setGeometry(QRect(230, 180, 101, 22));
        keyLineEdit_4 = new QLineEdit(enterCfbDialog);
        keyLineEdit_4->setObjectName("keyLineEdit_4");
        keyLineEdit_4->setGeometry(QRect(340, 180, 101, 22));
        keyLineEdit_5 = new QLineEdit(enterCfbDialog);
        keyLineEdit_5->setObjectName("keyLineEdit_5");
        keyLineEdit_5->setGeometry(QRect(10, 210, 101, 22));
        keyLineEdit_6 = new QLineEdit(enterCfbDialog);
        keyLineEdit_6->setObjectName("keyLineEdit_6");
        keyLineEdit_6->setGeometry(QRect(120, 210, 101, 22));
        keyLineEdit_7 = new QLineEdit(enterCfbDialog);
        keyLineEdit_7->setObjectName("keyLineEdit_7");
        keyLineEdit_7->setGeometry(QRect(230, 210, 101, 22));
        keyLineEdit_8 = new QLineEdit(enterCfbDialog);
        keyLineEdit_8->setObjectName("keyLineEdit_8");
        keyLineEdit_8->setGeometry(QRect(340, 210, 101, 22));
        saveButton = new QPushButton(enterCfbDialog);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(340, 240, 101, 31));

        retranslateUi(enterCfbDialog);

        QMetaObject::connectSlotsByName(enterCfbDialog);
    } // setupUi

    void retranslateUi(QDialog *enterCfbDialog)
    {
        enterCfbDialog->setWindowTitle(QCoreApplication::translate("enterCfbDialog", "Enter CFB IV/Key", nullptr));
        IvLabel->setText(QCoreApplication::translate("enterCfbDialog", "Enter Initialization Vector:", nullptr));
        ivLineEdit->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff / 255, 0x11 / 17...", nullptr));
        helpLabel->setText(QCoreApplication::translate("enterCfbDialog", "Either hexadecimal or decimal numbers, separated by a coma(',')", nullptr));
        frameLabel->setText(QCoreApplication::translate("enterCfbDialog", "Enter frame:", nullptr));
        framLineEdit->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0x21", nullptr));
        keysLabel->setText(QCoreApplication::translate("enterCfbDialog", "Enter keys: ", nullptr));
        keyLineEdit_1->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0x00", nullptr));
        keyLineEdit_2->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xfc", nullptr));
        keyLineEdit_3->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        keyLineEdit_4->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        keyLineEdit_5->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        keyLineEdit_6->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        keyLineEdit_7->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        keyLineEdit_8->setPlaceholderText(QCoreApplication::translate("enterCfbDialog", "e.g. 0xff", nullptr));
        saveButton->setText(QCoreApplication::translate("enterCfbDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class enterCfbDialog: public Ui_enterCfbDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERCFBKEY_H
