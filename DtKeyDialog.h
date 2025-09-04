#pragma once
#include "ui_enterDtKey.h"
#include <qmessagebox.h>
#include <iostream>

class DtKeyDialog : public QDialog
{
	Q_OBJECT
public:
	explicit DtKeyDialog(QWidget* parent = nullptr);
	~DtKeyDialog();
	std::vector<int> getRowKey() const { return rowKey; }
	std::vector<int> getColKey() const { return colKey; }
	bool checkIfValid(std::vector<int> vec);
private:
	Ui::dtEnterKey ui;
	std::vector<int> rowKey;
	std::vector<int> colKey;
	
private slots:
	void onSaveClicked();
};

