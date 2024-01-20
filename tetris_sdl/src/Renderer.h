#pragma once

#include <SDL2/SDL.h>
#include "Window.h"
#include "Viewport.h"

class Renderer {
    public:
        Renderer(int screenWidth = 1280, int screenHeight = 720, const char* title = "Anything");
        ~Renderer();
        void render();
        void setCurrentViewport(Viewport viewport);
        void setColor(uint8_t red, uint8_t green, uint8_t blue,uint8_t alpha = 255);
        inline bool getInit() const { return m_Initialized; }
        void clear();
        SDL_Renderer* getRenderer() { return m_Renderer; }
        void DrawQuad(int x, int y, int width, int height);
        void FillViewport(Viewport viewport);
    private:
        Window m_Window;
        SDL_Renderer* m_Renderer;
        bool m_Initialized;
};

