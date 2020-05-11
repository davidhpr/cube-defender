#ifndef RECTBULLET_H
#define RECTBULLET_H

#include <SDL.h>
#include "GameObject.h"

class RectBullet : public GameObject{
    public:
         int getX() override;
         int getY() override;
         int getW() override;
         int getH() override;

         void setX(int x) override;
         void setY(int y) override;
         void setW(int w) override;
         void setH(int h) override;

        bool isColided();
        void isColided(bool colide);
    private:
         bool collision = false;
         int posX;
         int posY;
         int w;
         int h;

};

#endif // RECTBULLET_H
