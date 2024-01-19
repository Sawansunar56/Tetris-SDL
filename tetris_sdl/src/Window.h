#pragma once

#include <SDL2/SDL.h>

class Window {
    public:
        Window();
        bool init(int width = 1280, int height = 720, const char* title = "Tetris");

        void free();

        SDL_Renderer* createRenderer();

        inline int getWidth() const { return m_Width; }
        inline int getHeight() const { return m_Height; }

        void handleEvent(SDL_Event& e);

        inline bool hasMouseFocus() const { return m_MouseFocus; }
        inline bool hasKeyboardFocus() const { return m_KeyboardFocus; }
        inline bool isMinimized() const { return m_Minimized; }
    private:
        SDL_Window* m_Window;

        int m_Width;
        int m_Height;

        bool m_MouseFocus;
        bool m_KeyboardFocus;
        bool m_FullScreen;
        bool m_Minimized;
};
