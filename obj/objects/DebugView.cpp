//
// Created by zach on 8/31/25 using zPc-i2.
//

#include "DebugView.h"
#include "../../FuckAss.h"

#include "raylib.h"

void DebugView::tick() {
    this->x = 0;
    this->y = FuckAss::sInstance.h - 16;

    // left out for now uncomment if you want it back in
    // DrawText(("Text coords: [" + std::to_string(text->x) + ", " + std::to_string(text->y) + "]").c_str(), this->x, this->y - 20, 16, Color(0xFF, 0xFF, 0xFF, 0xFF));
    DrawText(("FPS: " + std::to_string(GetFPS())).c_str(), this->x, this->y, 16, FuckAss::FUCKASS_WHITE);
}