//
//  SoundAsset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef SoundAsset_hpp
#define SoundAsset_hpp

#include "../Asset.hpp"

class SoundAsset: public Asset {
public:
    SoundAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
};

#endif /* SoundAsset_hpp */
