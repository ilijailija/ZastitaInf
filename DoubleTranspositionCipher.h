#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "EncryptionStrategy.h"
#pragma once

using namespace std;
class DoubleTranspositionCipher : public EncryptionStrategy
{
	vector<int> keyRow;
	vector<int> keyCol;

	string applyRowTransposition(const string& text, int numRows);
	string applyColumnTransposition(const string& text, int numColumns);

public:
	DoubleTranspositionCipher(const vector<int>& rowKey, const vector<int>& colKey);

	string encrypt(const string& plaintext) override;
	string decrypt(const string& ciphertext) override;
};

