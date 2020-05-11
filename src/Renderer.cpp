#include "Renderer.h"

Renderer::Renderer(const int width, const int height) : _screen_width(width), _screen_height(height) {

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    _window = SDL_CreateWindow("Cube Defender",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               _screen_width,
                               _screen_height,
                               SDL_WINDOW_SHOWN);

    if(_window == nullptr) {
        std::cerr << "Window could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created.\n";
        std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
    }

    setIcon(_icon);

    IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
    _texture = IMG_LoadTexture(renderer, "assets\\defender.png");
    _bullet_texture = IMG_LoadTexture(renderer, "assets\\bullet.png");
}

Renderer::~Renderer() {
    IMG_Quit();
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Renderer::setIcon(SDL_Surface* icon) {
    icon = SDL_LoadBMP("assets/icon.bmp");
    SDL_SetWindowIcon(_window, icon);
}

void Renderer::Render(Defender& defender, RectBullet& rectbullet, CubeEnemy& enemy) {
    //Background Color
    SDL_SetRenderDrawColor(renderer, 0x83, 0xe3, 0x5d, 0xFF);
    SDL_RenderClear(renderer);

    //Render Bullet
    SDL_Rect dest_bullet;
    dest_bullet.x = rectbullet.getX();
    dest_bullet.y = rectbullet.getY();
    dest_bullet.w = rectbullet.getW();
    dest_bullet.h = rectbullet.getH();
    SDL_QueryTexture(_bullet_texture, NULL, NULL, &dest_bullet.w, &dest_bullet.h);
    SDL_RenderCopy(renderer, _bullet_texture, NULL, &dest_bullet);

    //Render Defender Sprite
    SDL_Rect dest;
    dest.x = defender.getX();
    dest.y = defender.getY();
    dest.w = defender.getW();
    dest.h= defender.getH();
    SDL_QueryTexture(_texture, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(renderer, _texture, NULL, &dest);

    //Render Cubes
    SDL_Rect cube;
    cube.x = enemy.getX();
    cube.y = enemy.getY();
    cube.w = enemy.getW();
    cube.h = enemy.getH();
    SDL_SetRenderDrawColor(renderer, enemy.getRed(),enemy.getGreen(), enemy.getBlue(), 0xFF);
    SDL_RenderFillRect(renderer, &cube);

    SDL_RenderPresent(renderer);
}

void Renderer::UpdateWindowTitle(CubeEnemy& enemy) {
    std::string window_title{"Cubes destroyed: " + std::to_string(enemy.getScore())};
    SDL_SetWindowTitle(_window, window_title.c_str());
}

