#pragma once
#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <unordered_set>
#include <atomic>
#include <functional>
#include <mutex>
#include <fstream>
#include <sstream>
#include "EncryptionStrategy.h"

using namespace std;
namespace fs = std::filesystem;

class FileSystemWatcher
{
	EncryptionStrategy* encStrategy;

	fs::path targetDir;
	fs::path outputDir;

	atomic<bool> running;
	thread watcher_thread;
	mutex console_mutex;

	void watch();

public:

	FileSystemWatcher(fs::path target, fs::path output)
		:targetDir(target), outputDir(output), running(false) {}
	~FileSystemWatcher() {
		stop();
	}
	void start();
	void stop();
	bool isRunning() { return running; }
	void setEncryptionStrategy(EncryptionStrategy* strategy);
};

