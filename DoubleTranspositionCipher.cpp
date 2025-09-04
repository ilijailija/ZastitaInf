#include "DoubleTranspositionCipher.h"
DoubleTranspositionCipher::DoubleTranspositionCipher(const vector<int>& rowKey, const vector<int>& colKey)
	:keyRow(rowKey), keyCol(colKey){}

string DoubleTranspositionCipher::applyRowTransposition(const string& text, int numRows) {
	int numCols = (text.length() + numRows - 1) / numRows;

	vector<string> rows(numRows, string(numCols, 'x'));

	for (int i = 0; i < text.length(); i++) {
		rows[i / numCols][i % numCols] = text[i];
	}

	string result;

	for (int i : keyRow) {
		result += rows[i];
	}
	return result;
}

string DoubleTranspositionCipher::applyColumnTransposition(const string& text, int numCols) {
	int numRows = (text.length() + numCols - 1) / numCols;

	vector<string> cols(numCols, string(numRows, ' '));

	for (int i = 0; i < text.length(); i++) {
		cols[i % numCols][i / numCols] = text[i];
	}

	string result;

	for (int j = 0; j < numRows; j++) 
		for (int i: keyCol) 
			result += cols[i][j];

	return result;
}

string DoubleTranspositionCipher::encrypt(const string& plaintext){
	int numRows = keyRow.size();
	int numCols = keyCol.size();

	string rowTransposed = applyRowTransposition(plaintext, numRows);
	return applyColumnTransposition(rowTransposed, numCols);
}

string DoubleTranspositionCipher::decrypt(const string& ciphertext) {
	int numRows = keyRow.size();
	int numCols = keyCol.size();

	vector<int> inverseKeyRow(keyRow.size());
	vector<int> inverseKeyCol(keyCol.size());

	for (size_t i = 0; i < keyCol.size(); ++i) inverseKeyCol[keyCol[i]] = i;
	for (size_t i = 0; i < keyRow.size(); ++i) inverseKeyRow[keyRow[i]] = i;

	DoubleTranspositionCipher inverseCipher(inverseKeyRow, inverseKeyCol);
	string colTransposed = inverseCipher.applyColumnTransposition(ciphertext, numCols);
	return inverseCipher.applyRowTransposition(colTransposed, numRows);
}