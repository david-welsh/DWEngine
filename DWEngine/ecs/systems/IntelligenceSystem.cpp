//
//  IntelligenceSystem.cpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#define SOL_STD_OPTIONAL 1
#include <sol/sol.hpp>

#include "IntelligenceSystem.hpp"
#include "../components/IntelligenceComponent.hpp"
#include "../components/VelocityComponent.hpp"
#include "../components/PositionComponent.hpp"
#include "../components/AccelerationComponent.hpp"
#include "../components/CollidableComponent.hpp"
#include "../components/SoundComponent.hpp"
#include "../../assets/types/ScriptAsset.hpp"

void IntelligenceSystem::update(float deltaTime) {
    for (auto& e: em.getEntitiesWithComponents<IntelligenceComponent, VelocityComponent, PositionComponent, CollidableComponent>()) {
        auto targets = em.getEntitiesWithTag("player");
        if (targets.size() > 0) {
            auto& target = targets.at(0);
            
            auto& targetPos = em.getComponent<PositionComponent>(target);
            auto& vel = em.getComponent<VelocityComponent>(e);
            auto& i = em.getComponent<IntelligenceComponent>(e);
            auto& pos = em.getComponent<PositionComponent>(e);
            auto& c = em.getComponent<CollidableComponent>(e);
            auto& a = em.hasComponent<AccelerationComponent>(e) ? em.getComponent<AccelerationComponent>(e).a : DEFAULT_ACCEL_INTEL;
            
            auto& sc = am.getAsset<ScriptAsset>(i.scriptAsset);
            sol::state lua;
            lua.open_libraries(sol::lib::base);
            lua.open_libraries(sol::lib::math);
                
            lua["playSound"] = [this, e](std::string soundId) {
                printf("playing %s\n", soundId.c_str());
                this->playSound(e, soundId);
            };
            
            lua.new_usertype<PositionComponent>("PositionComponent",
                                                "x", &PositionComponent::x,
                                                "y", &PositionComponent::y);
            
            lua.new_usertype<VelocityComponent>("VelocityComponent",
                                                "vx", &VelocityComponent::vx,
                                                "vy", &VelocityComponent::vy,
                                                "maxV", &VelocityComponent::maxV);
            
            lua.new_usertype<CollidableComponent>("CollidableComponent",
                                                "isGrounded", &CollidableComponent::isGrounded);
            
            lua["targetPos"] = &targetPos;
            lua["vel"] = &vel;
            lua["pos"] = &pos;
            lua["a"] = a;
            lua["c"] = &c;
            lua["state"] = &(i.data);
            
            auto l = lua.load_file(am.absolutePath(sc));
            if (!l.valid()) {
                sol::error err = l;
                std::string what = err.what();
                printf("Error in lua script %s: %s\n", i.scriptAsset.c_str(), what.c_str());
            } else {
                auto r = l();
                if (!r.valid()) {
                    sol::error err = r;
                    std::string what = err.what();
                    printf("Error in lua script %s: %s\n", i.scriptAsset.c_str(), what.c_str());
                } else {
                    lua["update"](deltaTime);
                }
            }
        }
    }
}

void IntelligenceSystem::playSound(const int& entityId, std::string sound) {
    if (em.hasComponent<SoundComponent>(entityId)) {
        em.getComponent<SoundComponent>(entityId).toPlay.push(sound);
    }
}
