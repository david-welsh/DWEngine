//
//  InputComponent.hpp
//  CDEngine
//
//  Created by David Welsh on 19/06/2024.
//

#ifndef InputComponent_hpp
#define InputComponent_hpp

#include "Component.hpp"
#include <nlohmann/json.hpp>

class InputComponent: public Component {
public:
    float jumpPower;
    
    bool doubleJumped{false};
};

void from_json(const nlohmann::json& j, InputComponent& a);

#endif /* InputComponent_hpp */
