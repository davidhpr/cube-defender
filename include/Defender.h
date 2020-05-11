#ifndef DEFENDER_H
#define DEFENDER_H

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cmath>
#include "RectBullet.h"
#include "GameObject.h"

class Defender : GameObject{
public:
    Defender(RectBullet& rectbullet);

    void moveLeft(int move_steps);
    void moveRight(int move_steps);
    void shoot(RectBullet& rectbullet);
    void updateBullet(RectBullet& rectbullet);

    int getX() override;
    int getY() override;
    int getH() override;
    int getW() override;
    void setX(int x) override;
    void setY(int y) override;
    void setW(int w) override;
    void setH(int h) override;

private:
    bool fire{false};
    int def_x;
    int def_y;
    int def_h;
    int def_w;
};

#endif // DEFENDER_H
