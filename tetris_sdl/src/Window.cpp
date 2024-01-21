#include "precompch.h"
#include "Window.h"

Window::Window()
    : m_Window(nullptr), m_MouseFocus(false), m_KeyboardFocus(false),
      m_FullScreen(false), m_Minimized(false), m_Width(0), m_Height(0) {}

bool Window::init(int width, int height, const char *title) {
    m_Window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, width, height,
                                SDL_WINDOW_SHOWN);
    if (m_Window != nullptr) {
        m_MouseFocus = true;
        m_KeyboardFocus = true;
        m_Width = width;
        m_Height = height;
    }
    return m_Window != nullptr;
}

void Window::free() {
    if (m_Window != nullptr) {
        SDL_DestroyWindow(m_Window);
    }

    m_MouseFocus = false;
    m_KeyboardFocus = false;
    m_Width = 0;
    m_Height = 0;
}

SDL_Renderer *Window::createRenderer() {
    return SDL_CreateRenderer(
        m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void Window::handleEvent(SDL_Renderer *renderer, SDL_Event &e) {
    if (e.type == SDL_WINDOWEVENT) {
        bool updateCaptain = false;

        switch (e.window.event) {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            m_Width = e.window.data1;
            m_Height = e.window.data2;
            SDL_RenderPresent(renderer);
            break;

        case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent(renderer);
            break;

        case SDL_WINDOWEVENT_MINIMIZED:
            m_Minimized = true;
            break;

        case SDL_WINDOWEVENT_MAXIMIZED:
            m_Minimized = false;
            break;

        case SDL_WINDOWEVENT_RESTORED:
            m_Minimized = false;
            break;
        }
    } else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_RETURN) {
        if (m_FullScreen) {
            SDL_SetWindowFullscreen(m_Window, 0);
            m_FullScreen = false;
        } else {
            SDL_SetWindowFullscreen(m_Window, SDL_WINDOW_FULLSCREEN_DESKTOP);
            m_FullScreen = true;
            m_Minimized = false;
        }
    }
}
