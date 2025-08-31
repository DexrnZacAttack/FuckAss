//
// Created by zach on 8/31/25 using zPc-i2.
//
#ifndef FUCKASS_DEBUGVIEW_H
#define FUCKASS_DEBUGVIEW_H

#include "BouncyText.h"
#include "../Object.h"

class FuckAss;

class DebugView final : public Object {
public:
    explicit DebugView(BouncyText &txt) : mrText(txt) {};

    void tick() override;

    int x = 0;
    int y = 0;
private:
    // saves large stl call per frame
    BouncyText &mrText;
};

#endif //FUCKASS_DEBUGVIEW_H