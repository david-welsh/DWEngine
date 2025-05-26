//
//  SpriteSheetAsset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef SpriteSheetAsset_hpp
#define SpriteSheetAsset_hpp

#include "../Asset.hpp"

#include <map>
#include <string>
#include <vector>

class SpriteSheetAsset: public Asset {
    int rows;
    int columns;
    
    std::map<std::string, std::pair<int, int>> animations;
public:
    SpriteSheetAsset(std::string id, std::string path, int rows, int columns): Asset(id, path), rows(rows), columns(columns) {}
    
    SpriteSheetAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
    
    void loadData(nlohmann::json data) override;
    
    int getRows();
    int getColumns();
    
    std::pair<int, int> getAnimation(std::string animationId);
    
    void registerAnimation(std::string name, int from, int to);
};

#endif /* SpriteSheetAsset_hpp */
