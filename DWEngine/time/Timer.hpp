//
//  Timer.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>

class Timer {
    int startedAt;
    
public:
    Timer(): startedAt(0) {}
    
    void start();
    
    int getTicks();
};

#endif /* Timer_hpp */
