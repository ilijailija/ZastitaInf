#pragma once
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "DoubleTranspositionCipher.h"
#include "A52.h"
#include "FileSystemWatcher.h"
#include "Server.h"
#include "Client.h"
#include "MD5Alg.cpp"
#include "qapplication.h"
#include "qmainwindow.h"
#include "mainWindow.h"

using namespace std;
namespace fs = std::filesystem;


int main(int argc, char* argv[]) {

    QApplication app(argc, argv);
    mainWindow mainWindow;

    QCoreApplication::setOrganizationName("Ilija");
    QCoreApplication::setApplicationName("CryptographyApp");

    mainWindow.setWindowTitle("CryptographyApp");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}

