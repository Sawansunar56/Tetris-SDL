#pragma once
#include <SDL2/SDL.h>

class Viewport {
  public:
    Viewport(int x, int y, int w, int h) : m_Width(w), m_Height(h) {
        setViewport(x, y, w, h);
    }
    void setViewport(int x, int y, int w, int h) {
        m_Viewport.x = x;
        m_Viewport.y = y;
        m_Viewport.w = w;
        m_Viewport.h = h;
    }
    inline int getWidth() const { return m_Width; }
    inline int getHeight() const { return m_Height; }
    inline SDL_Rect &getViewport() { return m_Viewport; }

  private:
    int m_Width, m_Height;
    SDL_Rect m_Viewport;
};
