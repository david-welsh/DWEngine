//
//  InputSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef InputSystem_hpp
#define InputSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

const float DEFAULT_ACCEL = 0.5f;
const float THRESHOLD = 10.0f;

class InputSystem: public EntitySystem {
public:
    InputSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* InputSystem_hpp */
