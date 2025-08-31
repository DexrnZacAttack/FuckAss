//
// Created by zach on 8/31/25 using zPc-i2.
//

#ifndef FUCKASS_OBJECT_H
#define FUCKASS_OBJECT_H

// java.lang.Object
class Object {
public:
    virtual ~Object() = default;

    virtual void tick() = 0;
};

#endif //FUCKASS_OBJECT_H