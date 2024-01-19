#include "precompch.h"
#include "Window.h"

Window::Window() {
    m_Window = nullptr;
    m_MouseFocus = false;
    m_KeyboardFocus = false;
    m_FullScreen = false;
    m_Minimized = false;
    m_Width = 0;
    m_Height = 0;
}

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
    if(m_Window != nullptr) {
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
