#include "Renderer.h"
#include "InputHandle.h"
#include <random>

constexpr int screen_width = 640;
constexpr int screen_height = 480;
bool running = true;

struct Frames {
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    float target_frame_duration = 1000/60;
};

int main(int argc, char* args[]) {
    srand((unsigned) time(0));

    Frames frames;
    Renderer render(screen_width, screen_height);
    RectBullet rectbullet;
    CubeEnemy cube(-10,20,20, rectbullet);
    Defender defender(rectbullet);

    SDL_Delay(2000);

    //Game Loop
    while(running) {
        frames.frame_start = SDL_GetTicks();

        //1. Input
        InputHandle handle(running, defender, rectbullet);

        //2. Update
        render.UpdateWindowTitle(cube);
        defender.updateBullet(rectbullet);
        cube.updatePositionY();

        if(cube.getExit()) {
            std::cout << "Game Done!" << std::endl;
            std::cout << "Your Score was: " << cube.getScore() << std::endl;
            SDL_Delay(2000);
            running = false;
        }

        //3. Render
        render.Render(defender, rectbullet, cube);

        frames.frame_end = SDL_GetTicks();
        frames.frame_duration = frames.frame_end - frames.frame_start;
        if(frames.frame_duration < frames.target_frame_duration) {
            SDL_Delay(frames.target_frame_duration - frames.frame_duration);
        }
    }

    return 0;
}




