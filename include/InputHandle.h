#ifndef INPUTHANDLE_H
#define INPUTHANDLE_H

#include "SDL.h"
#include "Defender.h"
#include "RectBullet.h"

class InputHandle {
public:
    InputHandle(bool& running, Defender& defender, RectBullet& rectbullet);
};

#endif // INPUTHANDLE_H
