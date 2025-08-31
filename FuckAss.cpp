//
// Created by zach on 8/31/25 using zPc-i2.
//

#include "FuckAss.h"

#include <ranges>

#include "Logging.h"
#include "raylib.h"

FuckAss FuckAss::sInstance = FuckAss();

FuckAss::FuckAss() {
    // shut up auto everywhere
    BouncyText *t = new BouncyText(FILE_NAME);
    this->addObject("BouncyText", t);
    this->addObject("DebugView", new DebugView(*t));
}

void FuckAss::tick() {
    ClearBackground(Color(0, 0, 0,0xFF));

    if (IsWindowResized()) {
        this->oldW = this->w;
        this->oldH = this->h;
        this->w = GetScreenWidth();
        this->h = GetScreenHeight();
    }

    // WHAT THE FUCK IS THIS SYNTAX
    for (const auto &val: mObjects | std::views::values) {
        val->tick();
    }
}

void FuckAss::begin() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(this->w, this->h, "FuckAss");

    // birds nest
    SetTargetFPS(GetMonitorRefreshRate(GetCurrentMonitor()));

    while (!WindowShouldClose()) {
        BeginDrawing();

        // tick loop
        this->tick();

        EndDrawing();
    }
}

int main() {
    FuckAss::sInstance.begin();

    return 0;
}

