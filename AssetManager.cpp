#include "AssetManager.hpp"

namespace SGE
{
	AssetManager::AssetManager()
	{
	}
	AssetManager::~AssetManager()
	{
		IAssetHandler * asset;
		std::map<const int, IAssetHandler*>::iterator itr;

		itr = handlers.begin();
		while(itr != handlers.end())
		{
			asset = itr->second;
			handlers.erase(itr++);
			delete asset;
		}
	}
	IAssetHandler& AssetManager::GetHandler(typeAssetHandlerID id)
	{
		std::map<const int, IAssetHandler*>::iterator itr;
		itr = handlers.find(id);
		if(itr != handlers.end())
		{
			IAssetHandler* result = itr->second;
			return *result
		}
		else
		{
			exit(1);
		}
	}
	bool AssetManager::AddHandler(IAssetHandler* handler)
	{
		handlers.insert(std::pair<const typeAssetHandlerID, IAssetHandler*>(
			0, handler));	//0 is a dummy value, add getID later
	}

}