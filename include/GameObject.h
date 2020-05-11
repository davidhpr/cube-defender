#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
    virtual void setX(int x)=0;
    virtual void setY(int y)=0;
    virtual void setW(int w)=0;
    virtual void setH(int h)=0;
    virtual int getX()=0;
    virtual int getY()=0;
    virtual int getW()=0;
    virtual int getH()=0;
};
#endif // GAMEOBJECT_H
