//
//  AssetsData.hpp
//  CDEngine
//
//  Created by David Welsh on 17/06/2024.
//

#ifndef AssetsData_hpp
#define AssetsData_hpp

#include <string>
#include "AssetData.hpp"

struct AssetsData {
    std::vector<AssetData> sprites;
    std::vector<AssetData> music;
    std::vector<AssetData> sounds;
    std::vector<AssetData> scripts;
};

void from_json(const nlohmann::json& j, AssetsData& a);


#endif /* AssetsData_hpp */
