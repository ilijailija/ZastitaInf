#pragma once
#include <QDialog>
#include <QFileDialog>
#include <QSettings>
#include "ui_settings.h"
#include <iostream>
class SettingsWidget : public QDialog
{
	Q_OBJECT
public:
	explicit SettingsWidget(QWidget* parent = nullptr);
	~SettingsWidget();
private:
	Ui::AppSettings ui;
	void loadSettings();
private slots:
	void selectTargetDirectory();
	void selectOutputDirectory();
	void saveSettings();
};

