#include "CFB.h"
CFB::CFB(A52 a52cipher, vector<uint8_t> initVector, size_t blockSize)
	:cipher(a52cipher), iv(initVector), blockSize(blockSize) {}

vector<uint8_t> CFB::generateBlock() {
	uint8_t AtoB[15], BtoA[15];
	cipher.run(AtoB, BtoA);
	return vector<uint8_t>(AtoB, AtoB + blockSize);
}
string CFB::encrypt(const string& plaintext) {
	string ciphertext;
	vector<uint8_t> currentIv = iv;

    for (size_t i = 0; i < plaintext.size(); ++i) {
        cipher.seed(currentIv);

        auto keystream = generateBlock();
        uint8_t streamByte = keystream[0];

        uint8_t ptByte = static_cast<uint8_t>(plaintext[i]);
        uint8_t ctByte = ptByte ^ streamByte;
        ciphertext.push_back(ctByte);

        currentIv.erase(currentIv.begin());   
        currentIv.push_back(ctByte);        
    }
	return ciphertext;
}
string CFB::decrypt(const string& ciphertext) {
    std::string plaintext;
    std::vector<uint8_t> currentIV = iv;

    for (size_t i = 0; i < ciphertext.size(); ++i) {
        cipher.seed(currentIV);

        auto keystream = generateBlock();
        uint8_t streamByte = keystream[0];
      
        uint8_t ctByte = static_cast<uint8_t>(ciphertext[i]);
        uint8_t ptByte = ctByte ^ streamByte;
        plaintext.push_back(ptByte);

        currentIV.erase(currentIV.begin());
        currentIV.push_back(ctByte);
    }

    return plaintext;
}