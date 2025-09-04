#include "CfbDialog.h"
CfbDialog::CfbDialog(QWidget* parent)
	:QDialog(parent){
	ui.setupUi(this);
	connect(ui.saveButton, &QPushButton::clicked, this, &CfbDialog::onSaveClicked);
}
CfbDialog::~CfbDialog(){}

void CfbDialog::onSaveClicked() {
    QString frameText = ui.framLineEdit->text().trimmed();
    if (frameText.isEmpty()) {
        QMessageBox::warning(this, "Error", "Frame field empty.");
        ui.framLineEdit->setFocus();
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
    QString ivText = ui.ivLineEdit->text().trimmed();

    if (ivText.isEmpty()) {
        QMessageBox::warning(this, "Error", "IV field empty.");
        ui.ivLineEdit->setFocus();
        return;
    }

    QStringList ivParts = ivText.split(",", Qt::SkipEmptyParts);


    for (int i = 0; i < ivParts.size(); ++i) {
        QString part = ivParts[i].trimmed();

        bool ok = false;
        uint value = 0;

        if (part.startsWith("0x", Qt::CaseInsensitive)) {
            value = part.toUInt(&ok, 16);
        }
        else {
            value = part.toUInt(&ok, 10);
        }

        if (!ok || value > 0xFF) {
            QMessageBox::warning(this, "Error", QString("IV value #%1 invalid").arg(i + 1));
            return;
        }

        initVector.push_back(static_cast<uint8_t>(value));
            }

    accept();
}