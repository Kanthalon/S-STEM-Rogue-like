#ifndef ASSETMANAGER_HPP
#define ASSETMANAGER_HPP

#include <map>
#include "TAssetHandler.hpp"

namespace SGE
{
	class AssetManager
	{
		public:
			AssetManager();
			virtual ~AssetManager();
			bool AddHandler(IAssetHandler* handler);
			IAssetHandler& GetHandler(typeAssetHandlerID id);

		private:
			std::map<const int, IAssetHandler*> handlers;


	}
};

#endif