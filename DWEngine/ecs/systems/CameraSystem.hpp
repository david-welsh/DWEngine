//
//  CameraSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 23/06/2024.
//

#ifndef CameraSystem_hpp
#define CameraSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

class CameraSystem: public EntitySystem {
public:
    CameraSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
};

#endif /* CameraSystem_hpp */
