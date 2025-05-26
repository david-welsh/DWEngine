//
//  EntityData.hpp
//  CDEngine
//
//  Created by David Welsh on 13/06/2024.
//

#ifndef EntityData_hpp
#define EntityData_hpp

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

struct EntityData {
    std::string id;
    std::string type;
    std::vector<std::string> tags;
    nlohmann::json components;
};

void from_json(const nlohmann::json& j, EntityData& e);

#endif /* EntityData_hpp */
