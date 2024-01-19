#pragma once

#include <SDL2/SDL.h>
#include "Window.h"

class Renderer {
    public:
        Renderer(int screenWidth = 1280, int screenHeight = 720);
        ~Renderer();
        void render();
        inline bool getInit() const { return m_Initialized; }
    private:
        Window m_Window;
        SDL_Renderer* m_Renderer;
        bool m_Initialized;
};

