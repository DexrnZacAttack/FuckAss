//
// Created by zach on 8/31/25 using zPc-i2.
//
#ifndef FUCKASS_H
#define FUCKASS_H

#include <sstream>
#include <unordered_map>

#include "raylib.h"
#include "obj/objects/BouncyText.h"
#include "obj/objects/DebugView.h"

class FuckAss final : public Object {
public:
    static constexpr Color FUCKASS_WHITE = Color(0xFF, 0xFF, 0xFF, 0xFF);
    static FuckAss sInstance;

    FuckAss();

    void tick() override;

    void begin();

    template<typename T>
    T *getObject(const char *name) {
        return dynamic_cast<T*>(mObjects[name]);
    }

    int oldW = 800;
    int oldH = 600;
    int w = 800;
    int h = 600;

private:
    void addObject(const char *name, Object* obj) {
        mObjects[name] = obj;
    }

    // objects
    std::unordered_map<const char*, Object*> mObjects;
};

#endif //FUCKASS_H
