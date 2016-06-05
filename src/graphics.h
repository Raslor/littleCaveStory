#ifndef GRAPHICS_H_
#define GRAPHICS_H_

class SDL_Surface;
class SDL_Rect;

class Graphics {
public:
    Graphics();
    ~Graphics();

    void blitSurface(
            SDL_Surface* source,
            SDL_Rect* source_rectangle,
            SDL_Rect* destination_rectangle);

    void flip();
private:
    SDL_Surface* screen_;   
};

#endif // GRAPHICS_H_
