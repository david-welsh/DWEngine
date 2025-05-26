//
//  SpriteSheet.cpp
//  SDLSprites4
//
//  Created by David Welsh on 08/06/2024.
//

#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet() {
}

SpriteSheet::~SpriteSheet() { 
    free();
}

void SpriteSheet::free() { 
    sprites.free();
    rows = 0;
    columns = 0;
    current = 0;
}

bool SpriteSheet::loadFromFile(SDL_Renderer *renderer, std::string path, int rows, int columns) {
    bool success = sprites.loadFromFile(renderer, path);
    
    this->rows = rows;
    this->columns = columns;
    current = 0;
    
    return success;
}

void SpriteSheet::setColor(Uint8 red, Uint8 green, Uint8 blue) { 
    sprites.setColor(red, green, blue);
}

void SpriteSheet::setBlendMode(SDL_BlendMode blending) { 
    sprites.setBlendMode(blending);
}

void SpriteSheet::setAlpha(Uint8 alpha) { 
    sprites.setAlpha(alpha);
}

void SpriteSheet::setCurrent(int current) {
    this->current = current;
}

void SpriteSheet::incrCurrent() {
    current++;
}

int SpriteSheet::getCurrent() {
    return current;
}

void SpriteSheet::render(SDL_Renderer *renderer, int x, int y, SDL_Rect *clip, double angle, SDL_Point *center, SDL_RendererFlip flip) { 
    int currentRow = current / columns;
    int currentColumn = current % columns;
    int width = getWidth();
    int height = getHeight();
    
    SDL_Rect selectClip;
    selectClip.x = currentColumn * width;
    selectClip.y = currentRow * height;
    selectClip.w = width;
    selectClip.h = height;
    
    sprites.render(renderer, x, y, &selectClip, angle, center, flip);
}

int SpriteSheet::getWidth() { 
    if (columns == 0) return 0;
    return sprites.getWidth() / columns;
}

int SpriteSheet::getHeight() { 
    if (rows == 0) return 0;
    return sprites.getHeight() / rows;
}
