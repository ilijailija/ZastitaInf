#pragma once
#include "ui_enterCfbKey.h"
#include "A52.h"
#include "CFB.h"
class CfbDialog : public QDialog
{
	Q_OBJECT
public:
	explicit CfbDialog(QWidget* parent = nullptr);
	~CfbDialog();
	word getFrame() { return frame; }
	uint8_t* getKey() { return key; }
	vector<uint8_t> getIv(){ return initVector; }
private:
	Ui::enterCfbDialog ui;
	word frame;
	uint8_t key[8];
	vector<uint8_t> initVector;
private slots:
	void onSaveClicked();
};

