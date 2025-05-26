//
//  SpriteSheetAsset.cpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#include "SpriteSheetAsset.hpp"

#include "../../data/SpriteSheetAssetData.hpp"

std::string SpriteSheetAsset::getAssetType() {
    return ASSET_SPRITE_SHEET;
}

int SpriteSheetAsset::getRows() {
    return rows;
}

int SpriteSheetAsset::getColumns() {
    return columns;
}

void SpriteSheetAsset::registerAnimation(std::string name, int from, int to) {
    animations.insert({ name, std::pair<int,int>(from, to) });
}

std::pair<int, int> SpriteSheetAsset::getAnimation(std::string animationId) {
    return animations.at(animationId);
}

void SpriteSheetAsset::loadData(nlohmann::json data) {
    SpriteSheetAssetData d = data.get<SpriteSheetAssetData>();
    rows = d.rows;
    columns = d.columns;
    
    for (const auto& item : d.animations) {
        registerAnimation(item.id, item.from, item.to);
    }
}
