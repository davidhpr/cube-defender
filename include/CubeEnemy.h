#ifndef CUBEENEMY_H
#define CUBEENEMY_H

#include <iostream>
#include <cstdlib>
#include <SDL.h>
#include <ctime>
#include <cmath>
#include "RectBullet.h"
#include "GameObject.h"

class CubeEnemy{
    public:
        CubeEnemy(int y, int h, int w, RectBullet& rectbullet);
        void addEnemies(int cnt, CubeEnemy enemy);
        void updatePositionY();
        bool checkCollision();
        void randomCubeColor();
        int getScore();
        void updateScore();
        int getX();
        int getY();
        int getW();
        int getH();
        Uint8 getRed();
        Uint8 getGreen();
        Uint8 getBlue();
        bool getExit();
    private:
       Uint8 red, green, blue;
       int score{0};
       bool exit{false};
       float dy{0.0f};
       int x;
       int y;
       int h;
       int w;
       RectBullet& rectbullet;
};

#endif // CUBEENEMY_H
