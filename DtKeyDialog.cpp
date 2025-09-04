#include "DtKeyDialog.h"

DtKeyDialog::DtKeyDialog(QWidget* parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	ui.rowKeyLineEdit->setPlaceholderText("0..N-1");
	ui.colKeyLineEdit->setPlaceholderText("0..N-1");

	connect(ui.saveButton, &QPushButton::clicked, this, &DtKeyDialog::onSaveClicked);
}
DtKeyDialog::~DtKeyDialog(){}
bool DtKeyDialog::checkIfValid(std::vector<int> vec) {
	int n = vec.size();
	std::vector<bool> seen(n, false);

	for (int num : vec) {
		if (num < 0 || num > n - 1 || seen[num]) {
			return false;
		}
		seen[num] = true;
	}
	return true;
}

void DtKeyDialog::onSaveClicked(){
	rowKey.clear();
	colKey.clear();

	QString rowText = ui.rowKeyLineEdit->text();
	QString colText = ui.colKeyLineEdit->text();

	if (rowText.isEmpty()) {
		QMessageBox::warning(this, "Error", "Row Key empty");
		return;
	}

	if (colText.isEmpty()) {
		QMessageBox::warning(this, "Error", "Row Key empty");
		return;
	}

	QStringList rowParts = rowText.split(',', Qt::SkipEmptyParts);
	QStringList colParts = colText.split(',', Qt::SkipEmptyParts);

	for (QString& part : rowParts) {
		bool valid;
		int num = part.trimmed().toInt(&valid);
		if (!valid) {
			QMessageBox::warning(this, "Error", "Invalid 'Row Key' input!");
			return;
		}
		rowKey.push_back(num);
	}
	if (!checkIfValid(rowKey)) {
		QMessageBox::warning(this, "Error", "Row key isn`t a valid permutation");
		return;
	}

	for (QString& part : colParts) {
		bool valid;
		int num = part.trimmed().toInt(&valid);
		if (!valid) {
			QMessageBox::warning(this, "Error", "Invalid 'Column Key' input!");
			return;
		}
		colKey.push_back(num);
	}
	if (!checkIfValid(colKey)) {
		QMessageBox::warning(this, "Error", "Column key isn`t a valid permutation");
		return;
	}
	accept();
}