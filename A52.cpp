#include "A52.h"

bit A52::parity(word x) {   // ispravno
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;
	x ^= x >> 1;

	return x & 1;
}
bit A52::majority(word bit1, word bit2, word bit3) { // ispravno
	int sum = (bit1 != 0) + (bit2 != 0) + (bit3 != 0);
	if (sum >= 2)
		return 1;
	else
		return 0;
}
word A52::clockOne(word reg, word mask, word taps, word loaded_bit) {  // ispravno
	word t = reg & taps;

	reg = (reg << 1) & mask;

	reg |= parity(t);

	reg |= loaded_bit;

	return reg;
}
void A52::clock(int allP, int loaded) { //provereno
	bit maj = majority(R4 & R4TAP1, R4 & R4TAP2, R4 & R4TAP3);
	if (allP || (((R4 & R4TAP1) != 0) == maj))
		R1 = clockOne(R1, R1MASK, R1TAPS, loaded << 15);
	if (allP || (((R4 & R4TAP2) != 0) == maj))
		R2 = clockOne(R2, R2MASK, R2TAPS, loaded << 16);
	if (allP || (((R4 & R4TAP3) != 0) == maj))
		R3 = clockOne(R3, R3MASK, R3TAPS, loaded << 18);

	R4 = clockOne(R4, R4MASK, R4TAPS, loaded << 10);
}
bit A52::getBit() {  // provereno
	bit topbits = (((R1 >> 18) ^ (R2 >> 21) ^ (R3 >> 22)) & 0x01);

	static bit delaybit = 0;
	bit nowbit = delaybit;
	delaybit = (
		topbits
		^ majority(R1 & 0x8000, (~R1) & 0x4000, R1 & 0x1000)
		^ majority((~R2) & 0x10000, R2 & 0x2000, R2 & 0x200)
		^ majority(R3 & 0x40000, R3 & 0x10000, (~R3) & 0x2000)
		);
	return nowbit;
}
void A52::keySetup(byteT key[8], word frame) {

	bit keyBit, frameBit;
	R1 = R2 = R3 = R4 = 0;


	for (int i = 0; i < 64; i++) {
		clock(1, 0);
		keyBit = (key[i / 8] >> (i & 7)) & 1;
		R1 ^= keyBit; R2 ^= keyBit; R3 ^= keyBit; R4 ^= keyBit;
	}

	for (int i = 0; i < 22; i++) {
		clock(1, i == 21);
		frameBit = (frame >> i) & 1;
		R1 ^= frameBit; R2 ^= frameBit; R3 ^= frameBit; R4 ^= frameBit;
	}

	for (int i = 0; i < 100; i++) {
		clock(0, 0);
	}
	getBit();
}
void A52::run(byteT AtoBkeystream[], byteT BtoAkeystream[]) {

	for (int i = 0; i <= 113 / 8; i++)
		AtoBkeystream[i] = BtoAkeystream[i] = 0;

	for (int i = 0; i < 114; i++) {
		clock(0, 0);
		AtoBkeystream[i / 8] |= getBit() << (7 - (i & 7));
	}
	for (int i = 0; i < 114; i++) {
		clock(0, 0);
		BtoAkeystream[i / 8] |= getBit() << (7 - (i & 7));
	}
}
void A52::test() {
	uint8_t key[8] = { 0x00, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
	word frame = 0x21;
	uint8_t goodAtoB[15] = { 0xf4, 0x51, 0x2c, 0xac, 0x13, 0x59, 0x37,
						  0x64, 0x46, 0x0b, 0x72, 0x2d, 0xad, 0xd5, 0x00 };
	uint8_t goodBtoA[15] = { 0x48, 0x00, 0xd4, 0x32, 0x8e, 0x16, 0xa1,
						  0x4d, 0xcd, 0x7b, 0x97, 0x22, 0x26, 0x51, 0x00 };

	uint8_t AtoB[15], BtoA[15];
	int i, failed = 0;

	keySetup(key, frame);
	run(AtoB, BtoA);

	for (i = 0; i < 15; i++)
		if (AtoB[i] != goodAtoB[i])
			failed = 1;
	for (i = 0; i < 15; i++)
		if (BtoA[i] != goodBtoA[i])
			failed = 1;

	printf("key:0x");
	for (i = 0; i < 8; i++)
		printf("%02X", key[i]);
	printf("\n");
	printf("frame number: 0x%06X\n", (unsigned int)frame);
	printf("known good output:\n");
	printf(" A->B: 0x");
	for (i = 0; i < 15; i++)
		printf("%02X", goodAtoB[i]);
	printf("  B->A: 0x");
	for (i = 0; i < 15; i++)
		printf("%02X", goodBtoA[i]);
	printf("\n");
	printf("observed output:\n");
	printf(" A->B: 0x");
	for (i = 0; i < 15; i++)
		printf("%02X", AtoB[i]);
	printf("  B->A: 0x");
	for (i = 0; i < 15; i++)
		printf("%02X", BtoA[i]);
	printf("\n");

	if (!failed) {
		printf("Self-check succeeded: everything looks ok.\n");
		exit(0);
	}
	else {
		/* Problems!  The test vectors didn't compare*/
		printf("\nCODE IS NOT WORKIND PROPERLY\n");
	}

}

string A52::encrypt(const string& plaintext) {

	int numBlocks = (plaintext.size() + 13) / 14;
	string ciphertext;
	ciphertext.reserve(plaintext.size());

	for (int i = 0; i < numBlocks; i++) {
		int blockStart = i * 14;
		int blockSize = min(14ULL, plaintext.size() - blockStart);

		uint8_t AtoB[15], BtoA[15];
		run(AtoB, BtoA);

		for (int j = 0; j < blockSize; j++) {
			char encryptedChar = plaintext[blockStart + j] ^ AtoB[j];
			ciphertext.push_back(encryptedChar);
		}
	}
	return ciphertext;
}
string A52::decrypt(const string& ciphertext) {
	return encrypt(ciphertext);
}
void A52::seed(vector<uint8_t> iv) {
	word frame = 0;
	if (iv.size() >= 2) {
		frame = (iv[0] << 8) | iv[1];
	}

	keySetup(this->storedKey, frame);
}
