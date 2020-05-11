#include "CubeEnemy.h"

CubeEnemy::CubeEnemy(int y, int h, int w, RectBullet& rectbullet) : y(y),h(h),w(w), rectbullet(rectbullet) {
    x = 16+(rand() % 600);
    randomCubeColor();
}

void CubeEnemy::updatePositionY() {
    this->y += 2 + dy;

    if(y >= 420) {
        exit = true;
    }

    if(checkCollision()) {
        y = -10;
        x = rand() % 600;
        new RectBullet;
        new CubeEnemy(y, 20, 20, rectbullet);
        randomCubeColor();
        dy-=0.28f;
    }

    dy+=0.003f;
}

bool CubeEnemy::checkCollision() {
    if(abs(this->y - rectbullet.getY()) <= 10 && abs(this->x - rectbullet.getX()) <= 16) {
        updateScore();
        rectbullet.isColided(true);
        return true;
    }
    return false;
}

int CubeEnemy::getScore() {
    return score;
}

void CubeEnemy::updateScore() {
    score++;
}

void CubeEnemy::randomCubeColor() {
    red = rand() % 255;
    green = rand() % 255;
    blue = rand() % 255;

    if((red >= 0x80 && red <= 0x8F)
        || (green >= 0xC0 && green <= 0xEF )
        || (blue == 0x50 && blue <= 0x5F)) {
            red = 0x00;
            green = 0x00;
            blue = 0x00;
    }
}

Uint8 CubeEnemy::getRed() {return red;}
Uint8 CubeEnemy::getGreen() {return green;}
Uint8 CubeEnemy::getBlue() {return blue;}
bool CubeEnemy::getExit(){return exit;}
int CubeEnemy::getX() {return x;}
int CubeEnemy::getY() {return y;}
int CubeEnemy::getW() {return w;}
int CubeEnemy::getH() {return h;}
