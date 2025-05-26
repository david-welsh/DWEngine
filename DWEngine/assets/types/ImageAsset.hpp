//
//  ImageAsset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef ImageAsset_hpp
#define ImageAsset_hpp

#include <stdio.h>
#include "../Asset.hpp"

class ImageAsset: public Asset {
public:
    ImageAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
};

#endif /* ImageAsset_hpp */
