#pragma once
#include "ui_mainWindow2.h"
#include <qerrormessage.h>
#include "DoubleTranspositionCipher.h"
#include "A52.h"
#include "A52Wrapper.h"
#include "CFB.h"
#include "CfbDialog.h"
#include "FileSystemWatcher.h"
#include "Client.h"
#include "Server.h"
#include "FileDialog.h"
#include "MD5Alg.cpp"
#include "DtKeyDialog.h"
#include "A52KeyDialog.h"
#include "SettingsWidget.h"



class mainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit mainWindow(QWidget* parent = nullptr);
	~mainWindow();

private:
	Ui::MainWindow ui;
	EncryptionStrategy* encAlg;

	FileSystemWatcher* fsw;


	fs::path targetDir;
	fs::path outputDir;

	void initializeWSA();
	void cleanupWinsock();
private slots:
	void onDtClicked();
	void onA52Clicked();
	void onCfbClicked();
	void onFswClicked();
	void onManualClicked();
	void onSendClicked();
	void onRecieveClicked();
	void onSettingsClicked();
};

