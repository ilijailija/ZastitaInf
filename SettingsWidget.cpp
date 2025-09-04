#include "SettingsWidget.h"
SettingsWidget::SettingsWidget(QWidget* parent)
	:QDialog(parent) {
	ui.setupUi(this);
	//setWindowFlags(windowFlags() | Qt::Window);
	loadSettings();

	this->setFixedSize(320, 215);

	connect(ui.SelectTargetButton, &QPushButton::clicked, this, &SettingsWidget::selectTargetDirectory);
	connect(ui.selectOutputButton, &QPushButton::clicked, this, &SettingsWidget::selectOutputDirectory);
	connect(ui.saveButton, &QPushButton::clicked, this, &SettingsWidget::saveSettings);
}
SettingsWidget::~SettingsWidget(){}

void SettingsWidget::selectTargetDirectory() {
	QString dir = QFileDialog::getExistingDirectory(this, "Select target directory", ui.targetPathTextEdit->toPlainText());
	if (!dir.isEmpty()) {
		ui.targetPathTextEdit->setPlainText(dir);
	}
}

void SettingsWidget::selectOutputDirectory() {
	QString dir = QFileDialog::getExistingDirectory(this, "Select output directory", ui.plainTextEdit->toPlainText());
	if (!dir.isEmpty()) {
		ui.plainTextEdit->setPlainText(dir);
	}
}

void SettingsWidget::saveSettings() {
	QSettings settings("Ilija", "CryptographyApp");
	settings.setValue("targetDirectory", ui.targetPathTextEdit->toPlainText());
	settings.setValue("outputDirectory", ui.plainTextEdit->toPlainText());
	settings.sync();
	this->close();
}

void SettingsWidget::loadSettings() {
	QSettings settings;
	QString targetDir = settings.value("targetDirectory", "").toString();
	QString outputDir = settings.value("outputDirectory", "").toString();

	if (!targetDir.isEmpty())
		ui.targetPathTextEdit->setPlainText(targetDir);
	if (!outputDir.isEmpty())
		ui.plainTextEdit->setPlainText(outputDir);
}