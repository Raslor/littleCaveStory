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
            SDL_RESIZABLE);
}

Graphics::~Graphics() {
    SDL_FreeSurface(screen_);
}

void Graphics::blitSurface(
        SDL_Surface* source,
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
