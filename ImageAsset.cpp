#include <assert.h>
#include <stddef.h>
#include "ImageAsset.hpp"

namespace SQE{
  ImageAsset::ImageAsset() : TAsset<sf::Texture>(){}

  ImageAsset::~ImageAsset(){}
}
