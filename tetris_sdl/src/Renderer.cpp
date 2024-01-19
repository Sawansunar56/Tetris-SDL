#include "precompch.h"
#include "Renderer.h"
#include <log.h>

Renderer::Renderer(int screenWidth, int screenHeight) 
{
    m_Initialized = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        LOG_ERROR("SDL could not initialize sdl: {0}\n", SDL_GetError());
        m_Initialized = false;
    } else {
        if (!m_Window.init()) 
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

void Renderer::render() {
    SDL_SetRenderDrawColor(m_Renderer, 255, 0, 0, 255);

    SDL_RenderClear(m_Renderer);

    // SDL_SetRenderDrawColor(m_Renderer, 255, 255, 0, 255);
    // SDL_RenderDrawLines(m_Renderer, vertices, 4);

    SDL_RenderPresent(m_Renderer);
}
