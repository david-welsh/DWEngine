//
//  FrictionSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef FrictionSystem_hpp
#define FrictionSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

class FrictionSystem: public EntitySystem {
public:
    FrictionSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* FrictionSystem_hpp */
