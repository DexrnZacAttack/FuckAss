//
// Created by zach on 8/31/25 using zPc-i2.
//
#ifndef FUCKASS_BOUNCYTEXT_H
#define FUCKASS_BOUNCYTEXT_H

#include <string>
#include <utility>

#include "../Object.h"

class FuckAss;

class BouncyText final : public Object {
public:
    explicit BouncyText(const char *t) : mpText(t) {}
    explicit BouncyText(const std::string &t) : mpText(t.c_str()) {}

    void tick() override;

    int x = 0;
    int y = 0;

    bool up = false;
    bool right = true;

private:
    const char *mpText; // multiplayer text
};

#endif //FUCKASS_BOUNCYTEXT_H