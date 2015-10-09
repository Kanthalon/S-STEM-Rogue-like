#ifndef TASSETHANDLER_HPP
#define TASSETHANDLER_HPP

#include <map>
#include "IAssetHandler.hpp"
#include "Core_types.hpp"

namespace SGE
{
	template<class TYPE>
	class TAssetHandler : public IAssetHandler
	{
		public:
			TAssetHandler();
			virtual ~TAssetHandler();
			bool DropReference(typeAssetID id);
			bool IsLoaded();
			bool LoadAsset(typeAssetID id);
	}
}

#endif