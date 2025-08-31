//
// Created by zach on 8/31/25 using zPc-i2.
//

#include "BouncyText.h"

#include "raylib.h"
#include "../../FuckAss.h"
#include "../../Logging.h"

void BouncyText::tick() {
    DrawText(this->mpText, this->x, this->y, 20, FuckAss::FUCKASS_WHITE);

    if (IsWindowResized()) {
        this->x *= (float)FuckAss::sInstance.w / (float)FuckAss::sInstance.oldW;
        this->y *= (float)FuckAss::sInstance.h / (float)FuckAss::sInstance.oldH;
    }

    // I feel like this is too janky, Too bad!
    if (this->x > FuckAss::sInstance.w - MeasureText(this->mpText, 20)) right = false;
    if (this->x <= 0) right = true;

    if (this->y > FuckAss::sInstance.h - 20) up = true;
    if (this->y <= 0) up = false;

    if (up) y--;
    else y++;

    if (right) x++;
    else x--;
}
