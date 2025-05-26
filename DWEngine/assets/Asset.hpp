//
//  Asset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef Asset_hpp
#define Asset_hpp

#include <string>
#include <nlohmann/json.hpp>

const std::string ASSET_IMAGE = "ASSET_IMAGE";
const std::string ASSET_SPRITE_SHEET = "ASSET_SPRITE_SHEET";
const std::string ASSET_FONT = "ASSET_FONT";
const std::string ASSET_SOUND = "ASSET_SOUND";
const std::string ASSET_MUSIC = "ASSET_MUSIC";
const std::string ASSET_SCRIPT = "ASSET_SCRIPT";

class Asset {
    std::string id;
    std::string path;
public:
    Asset(std::string id, std::string path): id(id), path(path) {};
    virtual ~Asset() = default;
    
    std::string getId() {
        return id;
    }
    
    std::string getPath() {
        return path;
    }
    
    virtual void loadData(nlohmann::json data) {
    }
    
    virtual std::string getAssetType() = 0;
};

#endif /* Asset_hpp */
