#include <SDL2/SDL.h>

class Viewport {
    public:
        Viewport(int x, int y, int w, int h) {
            m_Viewport.x = x;
            m_Viewport.y = y;
            m_Viewport.w = w;
            m_Viewport.h = h;
        }
    private:
        SDL_Rect m_Viewport;
};
