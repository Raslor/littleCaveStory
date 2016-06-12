#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <string>
#include <map>

class SDL_Surface;
class SDL_Rect;

class Graphics {

public:
    
    typedef SDL_Surface* SurfaceID;
    
    Graphics();
    ~Graphics();

    SurfaceID loadImage(const std::string& file_path);

    void blitSurface(
            SDL_Surface* source,
            SDL_Rect* source_rectangle,
            SDL_Rect* destination_rectangle);

    void clear();
    void flip();

private:
    
    typedef std::map<std::string, SDL_Surface*> SpriteMap;
    SpriteMap sprite_sheets_;

    SDL_Surface* screen_;

};

#endif // GRAPHICS_H_
