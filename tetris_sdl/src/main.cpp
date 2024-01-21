#include "precompch.h"
#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Viewport.h"
#include "log.h"

constexpr int SCREEN_WIDTH =  1280;
constexpr int SCREEN_HEIGHT =  720;

int main(int argc, char *argv[]) {
    SDL_Point vertices[3] = {{400, 100}, {200, 500}, {600, 500}};
    Renderer renderer;
    if (!renderer.getInit()) {
        LOG_ERROR("Failed to initialize");
    } else {
        bool quit = false;

        SDL_Event e;

        int i = 0, j = 120, k = 100;

        Viewport leftSide(0, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        Viewport rightSide(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2,
                           SCREEN_HEIGHT / 2);
        Viewport menuRight(SCREEN_WIDTH - (SCREEN_WIDTH / 3), 0, SCREEN_WIDTH / 3, SCREEN_HEIGHT);
        while (!quit) {
            if(i >= 255) i = 0;
            if(j >= 255) j = 0;
            if(k >= 255) k = 0;
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    quit = true;
                }
            }
            renderer.RenderClear();

            renderer.setColor(k, j, i);
            renderer.setCurrentViewport(leftSide);
            renderer.DrawQuad(0, 0, 150, 100);
            // renderer.FillViewport(leftSide);

            renderer.setColor(i, i, k);
            renderer.setCurrentViewport(menuRight);
            renderer.FillViewport(menuRight);
        
            renderer.setColor(i, k, j);
            renderer.Render();
            i++; j++; k++;
        }
    }
    return 0;
}
