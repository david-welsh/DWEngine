//
//  AssetManager.cpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#include <format>
#include "AssetManager.hpp"
#include <fstream>

#include "../data/AssetsData.hpp"
#include "types/SpriteSheetAsset.hpp"
#include "types/MusicAsset.hpp"
#include "types/ScriptAsset.hpp"
#include "types/SoundAsset.hpp"

void AssetManager::loadAssets(std::string assetFilePath) { 
    std::ifstream f(assetFilePath);
    nlohmann::json data = nlohmann::json::parse(f);
    
    AssetsData aData = data.get<AssetsData>();
    for (const auto& asset: aData.sprites) {
        addAsset(asset.id, loadAsset<SpriteSheetAsset>(asset));
    }
    for (const auto& asset: aData.music) {
        addAsset(asset.id, loadAsset<MusicAsset>(asset));
    }
    for (const auto& asset: aData.sounds) {
        addAsset(asset.id, loadAsset<SoundAsset>(asset));
    }
    for (const auto& asset: aData.scripts) {
        addAsset(asset.id, loadAsset<ScriptAsset>(asset));
    }
}

std::string AssetManager::absolutePath(Asset &a) {
    return std::format("{}/{}", basePath, a.getPath());
}
