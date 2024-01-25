#pragma once

#include <SDL2/SDL.h>
#include "texture.h"

class Tetromino {
    public:
        Tetromino(int x,int y, int w, int h);
        inline SDL_Rect* getClip() { return &m_TextureClip; }
        void render(SDL_Renderer &ref, Texture &text, int x, int y);
    private:
        SDL_Rect m_TextureClip;
};

// class TPiece : public Tetromino {
// };
//
// class SPiece : public Tetromino {
// };
//
// class LongPiece : public Tetromino {
// };
//
// class shortLPiece : public Tetromino {
// };
//
// class LongLPiece : public Tetromino {
// };
