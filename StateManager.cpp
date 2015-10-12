#include "StateManager.hpp"

namespace SGE
{
	StateManager::StateManager()
	{
	}
	StateManager::~StateManager()
	{
		IStateHandler * asset;
		std::map<const int, IStateHandler*>::iterator itr;

		itr = handlers.begin();
		while(itr != handlers.end())
		{
			asset = itr->second;
			handlers.erase(itr++);
			delete asset;
		}
	}
	IStateHandler& StateManager::GetHandler(typeStateHandlerID id)
	{
		std::map<const int, IStateHandler*>::iterator itr;
		itr = handlers.find(id);
		if(itr != handlers.end())
		{
			IStateHandler* result = itr->second;
			return *result
		}
		else
		{
			exit(1);
		}
	}
	bool StateManager::AddHandler(IStateHandler* handler)
	{
		handlers.insert(std::pair<const typeStateHandlerID, IStateHandler*>(
			0, handler));	//0 is a dummy value, add getID later
	}

}
