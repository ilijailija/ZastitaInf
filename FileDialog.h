#pragma once
#include "ui_manualDialog.h"
#include "EncryptionStrategy.h"
#include <filesystem>
#include <fstream>
#include <qsettings.h>

class FileDialog : public QDialog
{
	Q_OBJECT
public:
	explicit FileDialog(const QString& filepath,EncryptionStrategy *encAlg, QWidget* parent = nullptr);
	~FileDialog();
private:
	Ui::DialogManual ui;
	EncryptionStrategy *encAlg;
	QString filepath;
	string fileContent;

	QSettings settings;
	QString outputDir = settings.value("outputDirectory", "").toString();
private slots:
	void onEncryptClicked();
	void onDecryptClicked();
};

