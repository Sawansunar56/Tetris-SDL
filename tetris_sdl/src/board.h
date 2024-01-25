#pragma once
#include "Viewport.h"

void makeBoard(SDL_Renderer *ref, Viewport viewport) {
    int widthOffset = viewport.getWidth() / 10;
    int heightOffset = viewport.getHeight() / 10;

    for (int i = widthOffset; i < viewport.getWidth(); i += widthOffset) {
        SDL_RenderDrawLine(ref, i, 0, i, viewport.getHeight());
    }
    for (int i = viewport.getHeight() - widthOffset; i > 0; i -= widthOffset) {
        SDL_RenderDrawLine(ref, 0, i, viewport.getWidth(), i);
    }
}
