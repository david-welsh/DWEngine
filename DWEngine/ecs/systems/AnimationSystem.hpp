//
//  AnimationSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 18/06/2024.
//

#ifndef AnimationSystem_hpp
#define AnimationSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"
#include "../../assets/AssetManager.hpp"

const int FRAME_RATE = 12;
const float FRAME_TIME = 1.0f / FRAME_RATE;

class AnimationSystem: public EntitySystem {
public:
    AnimationSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* AnimationSystem_hpp */
