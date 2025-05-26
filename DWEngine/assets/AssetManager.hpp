//
//  AssetManager.hpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <unordered_map>
#include <string>
#include <typeindex>
#include <typeinfo>
#include "Asset.hpp"
#include "../data/AssetData.hpp"

class AssetManager {
    std::unordered_map<std::type_index, std::unordered_map<std::string, std::unique_ptr<Asset>>> assets;
    std::string basePath;
    
    template <typename T>
    T loadAsset(AssetData asset) {
        T s(asset.id, asset.path);
        s.loadData(asset.data);
        return s;
    }
public:
    AssetManager(std::string basePath): basePath(basePath) {}
    
    std::string absolutePath(Asset& a);
    
    void loadAssets(std::string assetFilePath);
    
    template <typename T>
    void addAsset(std::string assetId, T asset) {
        std::type_index typeIndex(typeid(T));
        auto& assetMap = assets[typeIndex];
        assetMap[assetId] = std::make_unique<T>(asset);
    }
    
    template <typename T>
    T& getAsset(std::string assetId) {
        std::type_index typeIndex(typeid(T));
        auto& assetMap = assets[typeIndex];
        return *static_cast<T*>(assetMap[assetId].get());
    }
};

#endif /* AssetManager_hpp */
