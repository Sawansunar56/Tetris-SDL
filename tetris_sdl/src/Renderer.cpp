#include "precompch.h"
#include "Renderer.h"
#include <log.h>

Renderer::Renderer(int screenWidth, int screenHeight, const char* title) 
{
    m_Initialized = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        LOG_ERROR("SDL could not initialize sdl: {0}\n", SDL_GetError());
        m_Initialized = false;
    } else {
        if (!m_Window.init(screenWidth, screenHeight, title)) 
        {
            LOG_ERROR("SDL window could not initialize sdl: {0}\n",
                      SDL_GetError());
            m_Initialized = false;
        } else {
            m_Renderer = m_Window.createRenderer();

            if (m_Renderer == nullptr) 
            {
                LOG_ERROR("SDL Renderer could not initialize sdl: {0}\n",
                          SDL_GetError());
                m_Initialized = false;
            } else {
                SDL_SetRenderDrawColor(m_Renderer, 0xff, 0xff, 0xff, 0xff);
            }
        }
    }
}

Renderer::~Renderer() 
{
    m_Window.free();
    SDL_DestroyRenderer(m_Renderer);

    SDL_Quit();
}

void Renderer::RenderClear() {
    SDL_RenderClear(m_Renderer);
}
void Renderer::Render() {

    // SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);
    // SDL_RenderDrawLines(m_Renderer, vertices, 4);

    SDL_RenderPresent(m_Renderer);
}

void Renderer::setColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
    SDL_SetRenderDrawColor(m_Renderer, red, green, blue, alpha);
}

void Renderer::setCurrentViewport(Viewport viewport) {
    SDL_RenderSetViewport(m_Renderer, &viewport.getViewport());
}

void Renderer::DrawQuad(int x, int y, int width, int height) {
    SDL_Rect fillRect = {x, y, width, height};
    SDL_RenderFillRect(m_Renderer, &fillRect);
}

void Renderer::FillViewport(Viewport viewport) {
    DrawQuad(0, 0, viewport.getWidth(), viewport.getHeight());
}
