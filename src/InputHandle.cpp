#include "InputHandle.h"

InputHandle::InputHandle(bool& running, Defender& defender, RectBullet& rectbullet) {
    SDL_Event e;

    while (SDL_PollEvent(&e)) {
        if(e.type == SDL_QUIT) {
            running = false;
        } else {
            if(e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                case SDLK_a:
                    defender.moveLeft(14);
                    break;
                case SDLK_d:
                    defender.moveRight(14);
                    break;
                case SDLK_w:
                    defender.shoot(rectbullet);
                    break;
                }
            }
        }
    }
}


