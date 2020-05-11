#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include <string>
#include <iostream>
#include "RectBullet.h"
#include "Defender.h"
#include "SDL_image.h"
#include "CubeEnemy.h"

class Renderer {
public:
    Renderer(const int width, const int height);
    ~Renderer();

    void setIcon(SDL_Surface* icon);
    void Render(Defender& defender, RectBullet& rectbullet, CubeEnemy& enemy);
    void UpdateWindowTitle(CubeEnemy& enemy);

    SDL_Renderer* renderer;
    SDL_Rect* dest;

private:
    SDL_Window* _window;
    SDL_Surface* _screen_surface;
    SDL_Surface* _icon;
    SDL_Texture* _texture;
    SDL_Texture* _bullet_texture;
    const int _screen_width;
    const int _screen_height;
};

#endif // RENDERER_H
