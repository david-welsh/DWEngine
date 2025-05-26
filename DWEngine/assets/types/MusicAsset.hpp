//
//  MusicAsset.hpp
//  SDLSprites4
//
//  Created by David Welsh on 09/06/2024.
//

#ifndef MusicAsset_hpp
#define MusicAsset_hpp

#include "../Asset.hpp"

class MusicAsset: public Asset {
    
public:
    MusicAsset(std::string id, std::string path): Asset(id, path) {}
    
    std::string getAssetType() override;
};

#endif /* MusicAsset_hpp */
