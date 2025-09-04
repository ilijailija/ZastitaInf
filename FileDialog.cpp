#include "FileDialog.h"

FileDialog::FileDialog(const QString& filepath,EncryptionStrategy* encAlg, QWidget* parent)
	:filepath(filepath), encAlg(encAlg), QDialog(parent) {
	ui.setupUi(this);

	ui.labelFile->setFixedWidth(500);
	ui.labelFile->setText(filepath);

	ui.fileContent->setReadOnly(true);

	QFile file(filepath);
	if (file.open(QIODevice::ReadOnly)) {
		QByteArray raw = file.readAll();
		fileContent = std::string(raw.constData(), raw.size());
		ui.fileContent->setPlainText(QString::fromLatin1(fileContent));
		file.close();
	}
	else {
		qDebug() << "Cannot open file.";
	}
	connect(ui.pushButtonEncrypt, &QPushButton::clicked, this, &FileDialog::onEncryptClicked);
	connect(ui.pushButtonDecrypt, &QPushButton::clicked, this, &FileDialog::onDecryptClicked);
	connect(ui.pushButtonCancel, &QPushButton::clicked, this, &QDialog::reject);
}
FileDialog::~FileDialog(){}
void FileDialog::onEncryptClicked() {
	
	string msgEncrypted = encAlg->encrypt(fileContent);

	cout << msgEncrypted << endl;

	string filepathStr = filepath.toUtf8().constData();
	string fileName = filepathStr.substr(filepathStr.find_last_of("/\\") + 1);
	QString qFileName = QString::fromUtf8(fileName);

	QString outputFilePath = outputDir + "\\" + qFileName;

	QFile file(outputFilePath);
	if (file.open(QIODevice::WriteOnly)) { 
		file.write(msgEncrypted.data(), msgEncrypted.size());
		file.flush();
		file.close();
		cout << "File saved successfully!" << endl;
	}
	else {
		cerr << "Error: Could not open file for writing!" << endl;
	}
}
void FileDialog::onDecryptClicked() {

	string msgDecrypted = encAlg->decrypt(fileContent);

	string filepathStr = filepath.toUtf8().constData();
	string fileName = filepathStr.substr(filepathStr.find_last_of("/\\") + 1);
	QString qFileName = QString::fromUtf8(fileName);

	QString outputFilePath = outputDir + "\\" + qFileName;

	QFile file(outputFilePath);
	if (file.open(QIODevice::WriteOnly)) {
		file.write(msgDecrypted.data(), msgDecrypted.size());
		file.flush();
		file.close();
		cout << "File decrypted and saved successfully (overwritten)!" << endl;
	}
	else {
		cerr << "Error: Could not open file for writing!" << endl;
	}
}
