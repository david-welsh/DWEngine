//
//  SpriteSheetAssetData.hpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#ifndef SpriteSheetAssetData_hpp
#define SpriteSheetAssetData_hpp

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

struct Animation {
    std::string id;
    int from;
    int to;
};

struct SpriteSheetAssetData {
    int rows;
    int columns;
    std::vector<Animation> animations;
};

void from_json(const nlohmann::json& j, Animation& a);
void from_json(const nlohmann::json& j, SpriteSheetAssetData& a);

#endif /* SpriteSheetAssetData_hpp */
