#include "mainWindow.h"
mainWindow::mainWindow(QWidget* parent)
    : QMainWindow(parent),encAlg(nullptr) {
    ui.setupUi(this);  // Inicijalizacija UI-a

    this->setFixedSize(485, 345);

    connect(ui.pushButtonDT, &QPushButton::clicked, this, &mainWindow::onDtClicked);
    connect(ui.pushButtonA52, &QPushButton::clicked, this, &mainWindow::onA52Clicked);
    connect(ui.pushButtonCFB, &QPushButton::clicked, this, &mainWindow::onCfbClicked);
    connect(ui.buttonFSW, &QPushButton::clicked, this, &mainWindow::onFswClicked);
    connect(ui.buttonManual, &QPushButton::clicked, this, &mainWindow::onManualClicked);
    connect(ui.buttonSend, &QPushButton::clicked, this, &mainWindow::onSendClicked);
    connect(ui.buttonRecieve, &QPushButton::clicked, this, &mainWindow::onRecieveClicked);
    connect(ui.settingsButton, &QPushButton::clicked, this, &mainWindow::onSettingsClicked);

    ui.pushButtonDT->setEnabled(false);
    ui.pushButtonA52->setEnabled(false);
    ui.pushButtonCFB->setEnabled(false);

    ui.buttonFSW->setEnabled(false);
    ui.buttonManual->setEnabled(false);
    ui.buttonSend->setEnabled(false);
    ui.buttonRecieve->setEnabled(false);
}

mainWindow::~mainWindow() {}

void mainWindow::onDtClicked() {

    DtKeyDialog* dtDialog = new DtKeyDialog(this);
    if (dtDialog->exec() == QDialog::Accepted) {
        vector<int> rowKey = dtDialog->getRowKey();
        vector<int> colKey = dtDialog->getColKey();

        encAlg = new DoubleTranspositionCipher(rowKey, colKey);
        fsw->setEncryptionStrategy(encAlg);
    }
    else {
        QErrorMessage(this);
    }

    ui.pushButtonDT->setEnabled(false);
    ui.pushButtonA52->setEnabled(true);
    ui.pushButtonCFB->setEnabled(true);

    ui.buttonFSW->setEnabled(true);
    ui.buttonManual->setEnabled(true);
    ui.buttonSend->setEnabled(true);
    ui.buttonRecieve->setEnabled(true);
   
}
void mainWindow::onA52Clicked() {
    A52KeyDialog* a52Dialog = new A52KeyDialog(this);
    if (a52Dialog->exec() == QDialog::Accepted) {
        word frame = a52Dialog->getFrame();
        uint8_t* key = a52Dialog->getKey();

        encAlg = new A52Wrapper(key, frame);
        fsw->setEncryptionStrategy(encAlg);
    }

    ui.pushButtonA52->setEnabled(false);
    ui.pushButtonDT->setEnabled(true);
    ui.pushButtonCFB->setEnabled(true);

    ui.buttonManual->setEnabled(true);
    ui.buttonFSW->setEnabled(true);
    ui.buttonSend->setEnabled(true);
    ui.buttonRecieve->setEnabled(true);
}
void mainWindow::onCfbClicked() {
    CfbDialog* cfbDialog = new CfbDialog(this);
    if (cfbDialog->exec() == QDialog::Accepted) {
        word frame = cfbDialog->getFrame();
        uint8_t* key = cfbDialog->getKey();
        vector<uint8_t> iv = cfbDialog->getIv();
        A52 a52(key, frame);

        encAlg = new CFB(a52,iv,iv.size());
        fsw->setEncryptionStrategy(encAlg);
    }
    ui.pushButtonCFB->setEnabled(false);
    ui.pushButtonDT->setEnabled(true);
    ui.pushButtonA52->setEnabled(true);

    ui.buttonManual->setEnabled(true);
    ui.buttonFSW->setEnabled(true);
    ui.buttonSend->setEnabled(true);
    ui.buttonRecieve->setEnabled(true);
}

void mainWindow::onFswClicked() {
    if (fsw->isRunning()) {
        fsw->stop();
        ui.buttonFSW->setText("Turn FSW on");
        ui.pushButtonDT->setEnabled(true);
        ui.pushButtonA52->setEnabled(true);
        ui.pushButtonCFB->setEnabled(true);
        ui.buttonManual->setEnabled(true);
        ui.buttonSend->setEnabled(true);
        ui.buttonRecieve->setEnabled(true);
        ui.settingsButton->setEnabled(true);
    }
    else {
        fsw->start();
        ui.buttonFSW->setText("Turn FSW off");
        ui.pushButtonDT->setEnabled(false);
        ui.pushButtonA52->setEnabled(false);
        ui.pushButtonCFB->setEnabled(false);
        ui.buttonManual->setEnabled(false);
        ui.buttonSend->setEnabled(false);
        ui.buttonRecieve->setEnabled(false);
        ui.settingsButton->setEnabled(false);
    }
}
void mainWindow::onManualClicked() {
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Select file:"),
        "",
        tr("Text Files (*.txt)")
    );
    if (!filename.isEmpty()) {
        FileDialog* dialog = new FileDialog(filename,encAlg, this);
        dialog->exec();
    }
    else {
        qDebug() << "No file selected.";
    }
}
void mainWindow::onSendClicked() {

    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Select file:"),
        "",
        tr("Text Files (*.txt)")
    );
    QString fileContent;
    string fileContentStd;
    long fileSize;
    string msgHash;
    std::byte* byteHash;
    int hashLength;


    if (!filename.isEmpty()) {
        QFile file(filename);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            fileContent = in.readAll();
            file.close();

            std::string filenameStd = filename.toUtf8().constData();
            fileSize = fileContent.size();
            fileContentStd = fileContent.toUtf8().constData();
            byteHash = new std::byte[msgHash.length()];
            hashLength = msgHash.length();

            for (int i = 0; i < msgHash.length(); i++)
                byteHash[i] = std::byte(msgHash[i]);

            string encryptedMsg = encAlg->encrypt(fileContentStd);
            msgHash = GetMD5String(encryptedMsg);

            initializeWSA();

            Client client;
            client.ConnectToServer(12345);
            
            client.sendFileData(filenameStd, fileSize, hashLength, byteHash, encryptedMsg);
        }
    }
    else {
        qDebug() << "No file selected.";
    }

    cleanupWinsock();
}
void mainWindow::onRecieveClicked() {
    initializeWSA();
    Server server;
    server.BindSocket(12345);
    server.Listen();
    server.AcceptSocket();
    vector<string> fileContent = server.RecieveFileData();
    string fileName = fileContent[0];
    string encryptedMsg = fileContent[1];


    QString qFileName = QFileInfo(QString::fromStdString(fileName)).fileName();

    QDir dir(QString::fromStdString(this->outputDir.string()));

    QString outputFilePath = dir.filePath(qFileName);
    qDebug() << "Final outputFilePath:" << outputFilePath;

    cout << "Recieve file name: " << fileName << endl;
    cout << "Encrypted message: " << encryptedMsg << endl;

    string decryptedMsg = encAlg->decrypt(encryptedMsg);

    QFile file(outputFilePath);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(decryptedMsg.data(), decryptedMsg.size());
        file.flush();
        file.close();
        cout << "File saved successfully!" << endl;
    }
    else {
        cerr << "Error: Could not open file for writing!" << endl;
    }
}
void mainWindow::onSettingsClicked() {
    SettingsWidget settingsDialog(this);
    settingsDialog.exec();

    QSettings settings;
    QString qTargetDir = settings.value("targetDirectory", "").toString().trimmed();
    QString qOutputDir = settings.value("outputDirectory", "").toString().trimmed();
    std::string stdTargetDir = qTargetDir.toUtf8().constData();
    std::string stdOutputDir = qOutputDir.toUtf8().constData();
    std::replace(stdTargetDir.begin(), stdTargetDir.end(), '/', '\\');
    std::replace(stdOutputDir.begin(), stdOutputDir.end(), '/', '\\');

    this->targetDir = stdTargetDir;
    this->outputDir = stdOutputDir;

    fsw = new FileSystemWatcher(targetDir, outputDir);

    ui.pushButtonDT->setEnabled(true);
    ui.pushButtonA52->setEnabled(true);
    ui.pushButtonCFB->setEnabled(true);
}
void mainWindow::initializeWSA() {
    WSADATA wsaData;
    int wsaerr;
    WORD wVersionRequested = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr != 0) {
        std::cout << "Winsock dll not found.\n";
    }
    else {
        std::cout << "Winsock dll found!\n";
        std::cout << "Status: " << wsaData.szSystemStatus << std::endl;
    }
}
void mainWindow::cleanupWinsock() {
    WSACleanup();
}