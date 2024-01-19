#include "precompch.h"
#include <SDL2/SDL.h>
#include "Renderer.h"
#include "log.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(int argc, char *argv[]) {
    SDL_Point vertices[3] = {{400, 100}, {200, 500}, {600, 500}};
    Renderer renderer;
    if (!renderer.getInit()) {
        LOG_ERROR("Failed to initialize");
    } else {
        bool quit = false;

        SDL_Event e;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            renderer.render();
        }
    }
    return 0;
}
