#include "graphics.h"

#include <SDL.h>

namespace {
    const int kScreenWidth = 640;
    const int kScreenHeight = 480;
    const int kBitsPerPixel = 32;
}

Graphics::Graphics() {
    screen_ = SDL_SetVideoMode(
            kScreenWidth,
            kScreenWidth,
            kBitsPerPixel,
            0);
    SDL_ShowCursor(SDL_DISABLE);
}

Graphics::~Graphics() {
    for (SpriteMap::iterator iter = sprite_sheets_.begin() ; iter != sprite_sheets_.end() ; ++iter)
    {
        SDL_FreeSurface(iter->second);
    }
    SDL_FreeSurface(screen_);
}

Graphics::SurfaceID Graphics::loadImage(const std::string& file_path) {
    
    // if we have not loaded in the spritesheet
    if (sprite_sheets_.count(file_path) == 0) {
        //load it in now
        sprite_sheets_[file_path] = SDL_LoadBMP(file_path.c_str());
        
        if (sprite_sheets_[file_path] == NULL) {
            // Could not load the image for whatever reason, print to stderr.
            fprintf(stderr, "Could not find image: %s\n", file_path.c_str());
            // Don't try to continue if we couldn't load an image, just exit.
            exit(EXIT_FAILURE);
        }

    }

    return sprite_sheets_[file_path];
}

void Graphics::blitSurface(
        SurfaceID source,
        SDL_Rect* source_rectangle,
        SDL_Rect* destination_rectangle) {

    SDL_BlitSurface(source, source_rectangle, screen_, destination_rectangle);

}

void Graphics::clear() {
    SDL_FillRect(screen_, NULL/*,  SDL_Surface* surface, SDL_Rect* destination_rectangle,*/, 0/* Uint32 Color*/);
}

void Graphics::flip() {
    SDL_Flip(screen_);
}
