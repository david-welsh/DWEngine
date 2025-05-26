//
//  AssetData.hpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#ifndef AssetData_hpp
#define AssetData_hpp

#include <string>
#include <nlohmann/json.hpp>

struct AssetData {
    std::string id;
    std::string type;
    std::string path;
    
    nlohmann::json data;
};

void from_json(const nlohmann::json& j, AssetData& a);

#endif /* AssetData_hpp */
