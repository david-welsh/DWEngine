//
//  EntityManager.cpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#include <fstream>

#include "EntityManager.hpp"
#include "Entity.hpp"
#include "components/PositionComponent.hpp"
#include "components/RenderableComponent.hpp"
#include "components/VelocityComponent.hpp"
#include "components/GravityComponent.hpp"
#include "components/AnimationComponent.hpp"
#include "components/CollidableComponent.hpp"
#include "components/FrictionComponent.hpp"
#include "components/InputComponent.hpp"
#include "components/MusicComponent.hpp"
#include "components/SoundComponent.hpp"
#include "components/SpriteComponent.hpp"
#include "components/AccelerationComponent.hpp"
#include "components/IntelligenceComponent.hpp"
#include "components/CameraComponent.hpp"

#include <nlohmann/json.hpp>

Entity EntityManager::createEntity(EntityData entityData) {
    int entityId = nextEntityId++;
    Entity entity(entityId, *this);
    entities.emplace(entityId, entity);
    for (auto& t: entityData.tags) {
        if (!tags.contains(t)) tags.emplace(t, std::vector<int>());
        tags.at(t).push_back(entity.getId());
    }
    return entity;
}

std::vector<int> EntityManager::getEntitiesWithTag(std::string tag) {
    if (tags.contains(tag)) {
        return tags.at(tag);
    } else {
        return std::vector<int>();
    }
}

void EntityManager::loadEntities(std::string path) {
    std::ifstream f(path);
    nlohmann::json data = nlohmann::json::parse(f);
    
    EntitiesData e = data.get<EntitiesData>();
    for (const auto& entityConfig: e.entities) {
        Entity entity = createEntity(entityConfig);
        if (entityConfig.components.contains("PositionComponent")) {
            addComponent(entity, entityConfig.components["PositionComponent"].get<PositionComponent>());
        }
        if (entityConfig.components.contains("RenderableComponent")) {
            addComponent(entity, entityConfig.components["RenderableComponent"].get<RenderableComponent>());
        }
        if (entityConfig.components.contains("VelocityComponent")) {
            addComponent(entity, entityConfig.components["VelocityComponent"].get<VelocityComponent>());
        }
        if (entityConfig.components.contains("GravityComponent")) {
            addComponent(entity, entityConfig.components["GravityComponent"].get<GravityComponent>());
        }
        if (entityConfig.components.contains("AnimationComponent")) {
            addComponent(entity, entityConfig.components["AnimationComponent"].get<AnimationComponent>());
        }
        if (entityConfig.components.contains("MusicComponent")) {
            addComponent(entity, entityConfig.components["MusicComponent"].get<MusicComponent>());
        }
        if (entityConfig.components.contains("CollidableComponent")) {
            addComponent(entity, entityConfig.components["CollidableComponent"].get<CollidableComponent>());
        }
        if (entityConfig.components.contains("InputComponent")) {
            addComponent(entity, entityConfig.components["InputComponent"].get<InputComponent>());
        }
        if (entityConfig.components.contains("FrictionComponent")) {
            addComponent(entity, entityConfig.components["FrictionComponent"].get<FrictionComponent>());
        }
        if (entityConfig.components.contains("SoundComponent")) {
            addComponent(entity, entityConfig.components["SoundComponent"].get<SoundComponent>());
        }
        if (entityConfig.components.contains("SpriteComponent")) {
            addComponent(entity, entityConfig.components["SpriteComponent"].get<SpriteComponent>());
        }
        if (entityConfig.components.contains("AccelerationComponent")) {
            addComponent(entity, entityConfig.components["AccelerationComponent"].get<AccelerationComponent>());
        }
        if (entityConfig.components.contains("IntelligenceComponent")) {
            addComponent(entity, entityConfig.components["IntelligenceComponent"].get<IntelligenceComponent>());
        }
        if (entityConfig.components.contains("CameraComponent")) {
            addComponent(entity, entityConfig.components["CameraComponent"].get<CameraComponent>());
        }
    }
}
