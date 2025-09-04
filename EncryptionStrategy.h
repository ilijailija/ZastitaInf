#pragma once
#include <iostream>
using namespace std;

class EncryptionStrategy
{
public:
	virtual ~EncryptionStrategy() = default;
	virtual string encrypt(const string& plaintext) = 0;
	virtual string decrypt(const string& ciphertext) = 0;
};

