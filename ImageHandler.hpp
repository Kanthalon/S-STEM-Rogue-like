#include "TAssetHandler.hpp"
#include "Core_types.hpp"
#include <SFML\Graphics.hpp>

namespace SGE {
	class ImageHandler: public TAssetHandler<sf::Texture> {
		public:
			ImageHandler();
			virtual ~ImageHandler();
			virtual bool LoadFromFile(const typeAssetID AssetID, sf::Texture& texture);
			virtual bool LoadFromMemory(const typeAssetID AssetID, sf::Texture& texture);
	};
}