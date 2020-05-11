#include "RectBullet.h"

void RectBullet::setX(int x) {
    posX = x;
}

void RectBullet::setY(int y) {
    posY = y;
}

void RectBullet::setW(int w) {
    w = w;
}

void RectBullet::setH(int h) {
    h = h;
}

int RectBullet::getX() {return posX;}
int RectBullet::getY() {return posY;}
int RectBullet::getW() {return w;}
int RectBullet::getH() {return h;}

bool RectBullet::isColided() { return collision;}
void RectBullet::isColided(bool colide) {
    collision = colide;
}

