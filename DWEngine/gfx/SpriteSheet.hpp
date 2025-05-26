//
//  SpriteSheet.hpp
//  SDLSprites4
//
//  Created by David Welsh on 08/06/2024.
//

#ifndef SpriteSheet_hpp
#define SpriteSheet_hpp

#include <string>
#include <SDL2/SDL.h>
#include "Texture.hpp"
#include "Renderable.hpp"

class SpriteSheet: public Renderable {
    Texture sprites;
    
    int rows;
    int columns;
    
    int current;
public:
    SpriteSheet();
    ~SpriteSheet();
    
    void free();
    
    bool loadFromFile(SDL_Renderer* renderer, std::string path, int rows, int columns);
    
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
    
    void incrCurrent();
    void setCurrent(int current);
    int getCurrent();
};

#endif /* SpriteSheet_hpp */
