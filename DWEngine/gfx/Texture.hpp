//
//  Texture.hpp
//  SDLSprites4
//
//  Created by David Welsh on 08/06/2024.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <string>
#include <SDL2/SDL.h>
#include <SDL_ttf.h>

#include "Renderable.hpp"

class Texture: public Renderable {
public:
    Texture();
    
    ~Texture();
    
    bool loadFromFile(SDL_Renderer *renderer, std::string path);
    
    bool loadFromRenderedText(SDL_Renderer *renderer, TTF_Font *font, std::string textureText, SDL_Color textColor);
    
    void free();
    
    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    
    void setBlendMode(SDL_BlendMode blending);
    
    void setAlpha(Uint8 alpha);
    
    void render(SDL_Renderer *renderer,
                int x, 
                int y,
                SDL_Rect* clip = nullptr,
                double angle = 0.0, 
                SDL_Point* center = nullptr,
                SDL_RendererFlip flip = SDL_FLIP_NONE) override;
    
    int getWidth();
    int getHeight();
    
private:
    SDL_Texture* texture;
    
    int width;
    int height;
};

#endif /* Texture_hpp */
