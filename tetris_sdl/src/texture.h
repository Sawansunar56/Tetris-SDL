#include <SDL2/SDL.h>
#include <string>

class Texture {
  public:
    Texture();
    ~Texture();

    bool loadFromFile(SDL_Renderer *renderer, std::string filepath);

    inline int getHeight() const { return m_Height; }
    inline int getWidth() const { return m_Width; }

    void free();

    void render(SDL_Renderer* ref, int x, int y, SDL_Rect *clip = NULL, double angle = 0.0,
                SDL_Point *center = NULL,
                SDL_RendererFlip flip = SDL_FLIP_NONE);

    void setColor(uint8_t red, uint8_t green, uint8_t blue);

    void blendMode(SDL_BlendMode blending);

    void setAlpha(Uint8 alpha);

  private:
    SDL_Texture *m_Texture;

    int m_Width;
    int m_Height;
};
