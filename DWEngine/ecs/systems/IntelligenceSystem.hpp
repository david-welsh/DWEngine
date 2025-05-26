//
//  IntelligenceSystem.hpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#ifndef IntelligenceSystem_hpp
#define IntelligenceSystem_hpp

#include "EntitySystem.hpp"
#include "../Entity.hpp"
#include "../EntityManager.hpp"

const float DEFAULT_ACCEL_INTEL = 0.5f;
const float THRESHOLD_INTEL = 10.0f;

class IntelligenceSystem: public EntitySystem {
public:
    IntelligenceSystem(EntityManager& em, AssetManager& am, GameConfig& config): EntitySystem(em, am, config) {}
    
    void update(float deltaTime) override;
    
    void playSound(const int& entityId, std::string sound);
};

#endif /* IntelligenceSystem_hpp */
