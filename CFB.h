#pragma once
#include "EncryptionStrategy.h"
#include "A52.h"
#include <iostream>
#include <vector>
using namespace std;
class CFB : public EncryptionStrategy
{
	A52 cipher;
	vector<uint8_t> iv;
	size_t blockSize;
	vector<uint8_t> generateBlock();
public:
	CFB(A52 a52cipher, vector<uint8_t> initVector, size_t blockSize);
	string encrypt(const string& plaintext) override;
	string decrypt(const string& ciphertext) override;
};

