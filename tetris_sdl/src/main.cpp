#include "precompch.h"
#include <SDL2/SDL.h>
#include "Renderer.h"
#include "Viewport.h"
#include "log.h"
#include "texture.h"
#include "board.h"
#include "Tetromino.h"

constexpr int SCREEN_WIDTH = 960;
constexpr int SCREEN_HEIGHT = 720;

SDL_Rect gSpriteClips[10];

bool loadMedia(Texture &text, SDL_Renderer *ref) {
    bool success = true;

    if (!text.loadFromFile(ref, "Assets/sprites/tetris.png")) {
        LOG_ERROR("Failed to load sprite sheet texture!");
        success = false;
    } else {

        gSpriteClips[0].x = 0;
        gSpriteClips[0].y = 0;
        gSpriteClips[0].w = 80;
        gSpriteClips[0].h = 80;

        gSpriteClips[1].x = 0;
        gSpriteClips[1].y = 100;
        gSpriteClips[1].w = 80;
        gSpriteClips[1].h = 80;
    }
    return success;
}

int main(int argc, char *argv[]) {
    SDL_Point vertices[3] = {{400, 100}, {200, 500}, {600, 500}};
    Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer *ref = renderer.getRenderer();
    Texture text;

    Tetromino lost{0, 0, 80, 80};

    if (!loadMedia(text, ref)) {
        LOG_ERROR("PROBLEMS IN LOAD MEDIA");
    }

    if (!renderer.getInit()) {
        LOG_ERROR("Failed to initialize");
    } else {
        bool quit = false;

        SDL_Event e;

        int i = 0, j = 120, k = 100;

        Viewport gameSide(50, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
        Viewport menuRight(SCREEN_WIDTH - (SCREEN_WIDTH / 3), 0,
                           SCREEN_WIDTH / 3, SCREEN_HEIGHT);
        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                   quit = true;
                }
            }
            renderer.RenderClear();

            renderer.setColor(100,100,100);
            renderer.setCurrentViewport(gameSide);
            renderer.FillViewport(gameSide);

            renderer.setColor(i, i, k);
            renderer.setCurrentViewport(menuRight);
            renderer.FillViewport(menuRight);

            renderer.setColor(i, k, j);

            renderer.setColor(255, 100, 200);
            renderer.setCurrentViewport(gameSide);
            makeBoard(ref, gameSide);

            lost.render(*ref, text, 0, 0);
            // text.render(ref, 0, 0, lost.getClip());
            // text.render(ref, 0, 0, &gSpriteClips[0]);
            // text.render(ref, 0, 20, &gSpriteClips[1]);

            renderer.setCurrentViewport(nullptr);
            renderer.setColor(0, 0, 0);
            renderer.Render();
        }
    }
    return 0;
}
