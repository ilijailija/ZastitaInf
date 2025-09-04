#include "FileSystemWatcher.h"
void FileSystemWatcher::watch() {
	if (!encStrategy) {
		throw runtime_error("No encryption strategy set.");
	}
	unordered_set<string> existing_files;

	for (auto entry : fs::directory_iterator(targetDir)) {
		if (fs::is_regular_file(entry)) {
			existing_files.insert(entry.path().string());
		}
	}

	while (running) {
		for (auto entry : fs::directory_iterator(targetDir)) {
			if (fs::is_regular_file(entry)) {
				string filePath = entry.path().string();

				if (existing_files.find(filePath) == existing_files.end()) {
					existing_files.insert(filePath);

					ifstream is(filePath);
					stringstream buffer;
					buffer << is.rdbuf();
					string fileContent = buffer.str();
					is.close();

					string encrypted = encStrategy->encrypt(fileContent);

					auto outputFilePath = outputDir / entry.path().filename();
					ofstream os(outputFilePath);
					os << encrypted;
					os.close();

					cout << endl;
					cout << "New file: " << filePath << endl;
				}
			}
		}
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void FileSystemWatcher::start() {
	if (!running) {
		running = true;
		watcher_thread = thread(&FileSystemWatcher::watch, this);
		cout << "FSW started" << endl;
	}
	else {
		cout << "FSW already running." << endl;
	}
}
void FileSystemWatcher::stop() {
	if (running) {
		running = false;
		if (watcher_thread.joinable()) {
			watcher_thread.join();
		}
	}
	else {
		cout << "FSW isn`t running." << endl;
	}
}
void FileSystemWatcher::setEncryptionStrategy(EncryptionStrategy* strategy){
	this->encStrategy = strategy;
}