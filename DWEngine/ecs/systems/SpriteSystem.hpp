//
//  SpriteSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef SpriteSystem_hpp
#define SpriteSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

class SpriteSystem: public EntitySystem {
public:
    SpriteSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* SpriteSystem_hpp */
