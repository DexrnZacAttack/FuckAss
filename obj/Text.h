//
// Created by zach on 8/31/25 using zPc-i2.
//

#ifndef FUCKASS_TEXT_H
#define FUCKASS_TEXT_H
#include <string>
#include <utility>

class Text {
public:
    explicit Text(const char *s, const int xPos = 0, const int yPos = 0) : mX(xPos), mY(yPos), mrStr(s)  {}
    explicit Text(const std::string &s, const int xPos = 0, const int yPos = 0) : mX(xPos), mY(yPos), mrStr(s.c_str())  {}

    void setString(const char *s) {
        mrStr = s;
    }

    void setString(const std::string &s) {
        mrStr = s.c_str();
    }

    void setX(const int x) {
        this->mX = x;
    }

    void setY(const int y) {
        this->mY = y;
    }

    [[nodiscard]] const char *getString() const {
        return this->mrStr;
    }

    [[nodiscard]] int getX() const {
        return this->mX;
    }

    [[nodiscard]] int getY() const {
        return this->mY;
    }

private:
    int mX;
    int mY;
    const char *mrStr; // mister string
    // I'm more used to just shoving m to the start of each field no matter what, it's easier.
};

#endif //FUCKASS_TEXT_H