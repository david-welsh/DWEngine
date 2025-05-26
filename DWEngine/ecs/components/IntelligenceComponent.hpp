//
//  IntelligenceComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#ifndef IntelligenceComponent_hpp
#define IntelligenceComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class IntelligenceComponent: public Component {
public:
    std::map<std::string, std::string> data;
    std::string scriptAsset;
};

void from_json(const nlohmann::json& j, IntelligenceComponent& p);

#endif /* IntelligenceComponent_hpp */
