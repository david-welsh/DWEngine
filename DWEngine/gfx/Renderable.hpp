//
//  Renderable.hpp
//  SDLSprites4
//
//  Created by David Welsh on 10/06/2024.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include <SDL2/SDL.h>

#include "../assets/Asset.hpp"

class Renderable {
public:
    virtual void render(SDL_Renderer* renderer,
                        int x,
                        int y,
                        SDL_Rect* clip,
                        double angle,
                        SDL_Point* center ,
                        SDL_RendererFlip flip) = 0;
};

#endif /* Renderable_hpp */
