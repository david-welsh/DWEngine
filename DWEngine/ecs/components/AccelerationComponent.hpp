//
//  AccelerationComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 20/06/2024.
//

#ifndef AccelerationComponent_hpp
#define AccelerationComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class AccelerationComponent: public Component {
public:
    float a;
};

void from_json(const nlohmann::json& j, AccelerationComponent& r);

#endif /* AccelerationComponent_hpp */
