//
//  FontAsset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 10/06/2024.
//

#ifndef FontAsset_hpp
#define FontAsset_hpp

#include "../Asset.hpp"

class FontAsset: public Asset {
    
public:
    FontAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
};

#endif /* FontAsset_hpp */
