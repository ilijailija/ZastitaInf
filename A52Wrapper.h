#pragma once
#include "EncryptionStrategy.h"
#include "A52.h"

class A52Wrapper : public EncryptionStrategy {
private:
    A52 a52;
    uint8_t key[8];
    word frame;

public:
    A52Wrapper(uint8_t k[8], word f) : a52(k, f), frame(f) {
        memcpy(key, k, 8);
    }

    std::string encrypt(const std::string& msg) override {
        a52.keySetup(key, frame); // reset pre enkripcije
        return a52.encrypt(msg);
    }

    std::string decrypt(const std::string& msg) override {
        a52.keySetup(key, frame); // reset pre dekripcije
        return a52.decrypt(msg);
    }
};