#pragma once
#include "ui_enterA52Key.h"
#include "A52.h"

class A52KeyDialog : public QDialog
{
	Q_OBJECT
public:
	explicit A52KeyDialog(QWidget* parent = nullptr);
	~A52KeyDialog();
	word getFrame() { return frame; }
	uint8_t* getKey() { return key; }
private:
	Ui::A52Dialog ui;
	word frame;
	uint8_t key[8];
private slots:
	void onSaveClicked();
};

