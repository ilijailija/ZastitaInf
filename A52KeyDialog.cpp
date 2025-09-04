#include "A52KeyDialog.h"
A52KeyDialog::A52KeyDialog(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.saveButton, &QPushButton::clicked, this, &A52KeyDialog::onSaveClicked);
}
A52KeyDialog::~A52KeyDialog(){}

void A52KeyDialog::onSaveClicked() {
    QString frameText = ui.frameLineEdit->text().trimmed();
    if (frameText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Frame field empty.");
        ui.frameLineEdit->setFocus();
        return;
    }
    bool ok;
    uint16_t parsedFrame = frameText.toUShort(&ok, 16); 

    if (!ok || parsedFrame > 0x3FF) { 
        QMessageBox::warning(this, "Error", "Frame value invalid");
        return;
    }

    frame = parsedFrame;

    // Parsiranje key vrednosti
    QLineEdit* keyFields[8] = {
        ui.keyLineEdit_1,
        ui.keyLineEdit_2,
        ui.keyLineEdit_3,
        ui.keyLineEdit_4,
        ui.keyLineEdit_5,
        ui.keyLineEdit_6,
        ui.keyLineEdit_7,
        ui.keyLineEdit_8
    };

    for (int i = 0; i < 8; ++i) {
        QString text = keyFields[i]->text().trimmed();

        if (text.isEmpty()) {
            QMessageBox::warning(this, "Error", QString("Key #%1 empty.").arg(i + 1));
            keyFields[i]->setFocus();
            return;
        }

        bool valid;
        uint val = text.toUInt(&valid, 16);
        if (!valid || val > 0xFF) {
            QMessageBox::warning(this, "Error", QString("Key #%1 invalid").arg(i + 1));
            return;
        }
        key[i] = static_cast<uint8_t>(val);
        
    }

    accept();
}