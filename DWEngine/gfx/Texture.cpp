//
//  Texture.cpp
//  SDLSprites4
//
//  Created by David Welsh on 08/06/2024.
//

#include "Texture.hpp"

#include <SDL_image.h>
#include <SDL_ttf.h>

Texture::Texture() {
    texture = NULL;
    width = 0;
    height = 0;
}

Texture::~Texture(){
    free();
}

bool Texture::loadFromFile(SDL_Renderer *renderer, std::string path) {
    free();
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (texture == nullptr) {
        printf("Failed to load texture at %s: %s\n", path.c_str(), SDL_GetError());
        return false;
    }
    if (SDL_QueryTexture(texture, nullptr, nullptr, &width, &height) < 0) {
        printf("Failed to query texture at %s: %s\n", path.c_str(), SDL_GetError());
        return false;
    }
    return true;
}

bool Texture::loadFromRenderedText(SDL_Renderer *renderer, TTF_Font *font, std::string textureText, SDL_Color textColor) {
    free();
        
    SDL_Surface* loadedSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if (loadedSurface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if(texture == nullptr) {
            printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
        } else {
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        
        SDL_FreeSurface(loadedSurface);
    }
    
    return texture != nullptr;
}

void Texture::free() {
    if(texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(Uint8 alpha) {
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(SDL_Renderer *renderer, 
                     int x,
                     int y,
                     SDL_Rect* clip,
                     double angle,
                     SDL_Point* center ,
                     SDL_RendererFlip flip) {
    SDL_Rect renderQuad = { x, y, width, height };
    
    if (clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    if (SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip) < 0) {
        printf("Failed to render texture: %s\n", SDL_GetError());
    }
}

int Texture::getWidth() {
    return width;
}

int Texture::getHeight() {
    return height;
}
