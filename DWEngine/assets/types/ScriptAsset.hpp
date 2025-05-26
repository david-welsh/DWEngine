//
//  ScriptAsset.hpp
//  CDEngine
//
//  Created by David Welsh on 22/06/2024.
//

#ifndef ScriptAsset_hpp
#define ScriptAsset_hpp

#include "../Asset.hpp"

class ScriptAsset: public Asset {
    
public:
    ScriptAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
};

#endif /* ScriptAsset_hpp */
