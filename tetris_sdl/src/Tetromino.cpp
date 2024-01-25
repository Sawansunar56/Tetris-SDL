#include "precompch.h"
#include "Tetromino.h"

Tetromino::Tetromino(int x,int y, int w, int h) {
    m_TextureClip = { x, y, w, h };
}

void Tetromino::render(SDL_Renderer &ref, Texture &text, int x, int y) {
    text.render(&ref, x, y, &m_TextureClip);
}
