#ifndef IASSETHANDLER_HPP
#define IASSETHANDLER_HPP

#include <map>
#include "Core_types.hpp"

namespace SGE
{
	class IAssetHandler 
	{
		public:
			virtual IAssetHandler();
			virtual ~IAssetHandler();
			virtual bool DropReference(typeAssetID id);
			virtual bool IsLoaded();
			virtual bool LoadAsset(typeAssetID id);
	}
}

#endif