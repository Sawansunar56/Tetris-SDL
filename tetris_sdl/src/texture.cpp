#include "precompch.h"
#include "SDL2/SDL_render.h"
#include <SDL2/SDL_image.h>
#include <iostream>
#include <texture.h>

Texture::Texture() {
    m_Texture = nullptr;

    m_Width = 0;
    m_Height = 0;
}

Texture::~Texture() { free(); }

bool Texture::loadFromFile(SDL_Renderer *gRenderer, std::string path) {
    free();

    SDL_Texture *newTexture = nullptr;

    SDL_Surface *loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) {
        std::cout << "Unable to load image" << path.c_str()
                  << "! SDL_IMage Error: " << IMG_GetError() << "\n";
    } else {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);

        if (newTexture == NULL) {
            std::cout << "Unable to create Texture from " << path.c_str()
                      << " ! SDL_ERROR: " << SDL_GetError() << "\n";
        } else {
            m_Width = loadedSurface->w;
            m_Height = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    m_Texture = newTexture;
    return m_Texture != NULL;
}

void Texture::free() {
    if (m_Texture != NULL) {
        SDL_DestroyTexture(m_Texture);
        m_Texture = NULL;
        m_Width = 0;
        m_Height = 0;
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(m_Texture, red, green, blue);
}

void Texture::blendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(m_Texture, blending);
}

void Texture::setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(m_Texture, alpha); }
