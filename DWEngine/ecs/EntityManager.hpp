//
//  EntityManager.hpp
//  CDEngine
//
//  Created by David Welsh on 15/06/2024.
//

#ifndef EntityManager_hpp
#define EntityManager_hpp

#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <bitset>

#include "components/Component.hpp"
#include "../data/EntitiesData.hpp"

constexpr std::size_t MAX_COMPONENTS = 64;

class Entity;

class EntityManager {
    int nextEntityId;
    std::unordered_map<int, Entity> entities;
    std::unordered_map<std::type_index, std::unordered_map<int, std::unique_ptr<Component>>> components;
    
    std::unordered_map<std::string, std::vector<int>> tags;
    
    std::unordered_map<int, std::bitset<MAX_COMPONENTS>> entityComponentMasks;
    std::unordered_map<std::type_index, std::size_t> componentIndices;
    std::size_t nextComponentIndex = 0;
public:
    Entity createEntity(EntityData entity);
    
    void loadEntities(std::string path);
    
    template <typename T>
    void addComponent(Entity entity, T component);
    
    template <typename T>
    T& getComponent(int entityId);
    
    template <typename T>
    bool hasComponent(int entityId);
    
    template <typename T>
    std::vector<T&> getEntitiesWithComponent();
    
    template <typename... Components>
    std::vector<int> getEntitiesWithComponents();
    
    std::vector<int> getEntitiesWithTag(std::string tag);
};

#include "Entity.hpp"

template <typename T>
void EntityManager::addComponent(Entity entity, T component) {
    std::type_index typeIndex = typeid(T);
    if (componentIndices.find(typeIndex) == componentIndices.end()) {
        componentIndices[typeIndex] = nextComponentIndex++;
    }

    components[typeIndex][entity.getId()] = std::make_unique<T>(std::move(component));
    entityComponentMasks[entity.getId()].set(componentIndices[typeIndex]);
}

template <typename T>
T& EntityManager::getComponent(int entityId) {
    std::type_index typeIndex(typeid(T));
    auto& componentMap = components[typeIndex];
    return *static_cast<T*>(componentMap[entityId].get());
}

template <typename T>
bool EntityManager::hasComponent(int entityId) {
    std::type_index typeIndex(typeid(T));
    auto& componentMap = components[typeIndex];
    return componentMap.contains(entityId);
}

template <typename T>
std::vector<T&> EntityManager::getEntitiesWithComponent() {
    std::type_index typeIndex(typeid(T));
    std::vector<T&> results;
    auto& componentMap = components[typeIndex];
    for(auto it = componentMap.begin(); it != componentMap.end(); ++it) {
        results.push_back(entities[it->first]);
    }
    return results;
}

template <typename... Components>
std::vector<int> EntityManager::getEntitiesWithComponents() {
    std::vector<int> result;
    std::bitset<MAX_COMPONENTS> requiredComponents;

    (requiredComponents.set(componentIndices[typeid(Components)]), ...);

    for (const auto& pair : entityComponentMasks) {
        if ((pair.second & requiredComponents) == requiredComponents) {
            result.push_back(pair.first);
        }
    }

    return result;
}

#endif /* EntityManager_hpp */
