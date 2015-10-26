#ifndef IMAGE_ASSET_H
#define IMAGE_ASSET_H

#include <SFML/Graphics.hpp>
#include "TAsset.hpp"
#include "Core_types.hpp"

namespace SQE{
  class ImageAsset : TAsset<sf::Texture>{
    public:
      ImageAsset();
      virtual ~ImageAsset();
  }
}

#endif
