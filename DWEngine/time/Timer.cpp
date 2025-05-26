//
//  Timer.cpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#include "Timer.hpp"
#include <SDL2/SDL.h>

void Timer::start() { 
    startedAt = SDL_GetTicks();
}

int Timer::getTicks() {
    return SDL_GetTicks() - startedAt;
}
