#include <iostream>
#include <vector>
#include <bitset>
#include <cstdint>
#include "EncryptionStrategy.h"
#pragma once

using namespace std;

typedef unsigned char byteT;
typedef unsigned long word;
typedef word bit;

class A52 : public EncryptionStrategy
{
	static constexpr word R1MASK = 0x07FFFF; // 19 bits
	static constexpr word R2MASK = 0x3FFFFF; // 22 bits
	static constexpr word R3MASK = 0x7FFFFF; // 23 bits
	static constexpr word R4MASK = 0x01FFFF; // 17 bits

	static constexpr word R1TAPS = 0x072000; // Feedback taps for R1
	static constexpr word R2TAPS = 0x300000; // Feedback taps for R2
	static constexpr word R3TAPS = 0x700080; // Feedback taps for R3
	static constexpr word R4TAPS = 0x010800; // Feedback taps for R4

	static constexpr word R4TAP1 = 0x000400; // R4 bit 10
	static constexpr word R4TAP2 = 0x000008; // R4 bit 3
	static constexpr word R4TAP3 = 0x000080; // R4 bit 7

	word R1, R2, R3, R4;
	byteT storedKey[8];

	bit parity(word x);

	bit majority(word bit1, word bit2, word bit3);

	word clockOne(word reg, word mask, word taps, word loaded_bit);
	
	void clock(int allP, int loaded);
	bit getBit();
public:
	A52(uint8_t* key, word frame) :R1(0), R2(0), R3(0), R4(0) {
		memcpy(storedKey, key, 8);
		keySetup(key, frame);
	}

	void keySetup(byteT key[8], word frame);
	void run(byteT AtoBkeystream[], byteT BtoAkeystream[]);

	void test();
	void seed(vector<uint8_t> iv);
	string encrypt(const string& plaintext) override;
	string decrypt(const string& ciphertext) override;

};

