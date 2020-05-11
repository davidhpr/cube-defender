#include "Defender.h"

Defender::Defender(RectBullet& rectbullet) {
    Defender::setX(640/2 - 20);
    Defender::setY(480 - 65);
    Defender::setW(50);
    Defender::setH(50);

    rectbullet.setX(def_x+36);
    rectbullet.setY(def_y-2);
    rectbullet.setW(100);
    rectbullet.setH(100);
}

void Defender::moveLeft(int move_steps) {
    if(def_x <= -20) {
        move_steps = 0;
    }
    def_x -= move_steps;
}

void Defender::moveRight(int move_steps) {
    if(def_x >= 640-80) {
        move_steps = 0;
    }
    def_x += move_steps;
}

void Defender::shoot(RectBullet& rectbullet) {
    fire = true;
    if(rectbullet.getY() <= -10 || rectbullet.isColided() == true) {
        rectbullet.setX(def_x+36);
        rectbullet.setY(def_y+15);
        rectbullet.isColided(false);
    }
    rectbullet.setY(rectbullet.getY()-10);
}

void Defender::updateBullet(RectBullet& rectbullet) {
    if(!(rectbullet.getY() <= -20) && fire && rectbullet.isColided() == false) {
       rectbullet.setY(rectbullet.getY()-8);
    } else fire = false;
    if(!fire) {
        rectbullet.setX(def_x+36);
        rectbullet.setY(def_y+15);
    }
}

void Defender::setX(int x) {
    def_x = x;
}

void Defender::setY(int y) {
    def_y = y;
}

void Defender::setW(int w) {
    def_w = w;
}

void Defender::setH(int h) {
    def_h = h;
}

int Defender::getX() {return def_x;}

int Defender::getY() {return def_y;}

int Defender::getW() {return def_w;}

int Defender::getH() {return def_h;}



