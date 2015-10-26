#include "StateManager.hpp"
#include "Game.hpp"
#include <iostream>


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

	void StateManager::RegisterGame(Game* g)
	{
		game = g;
		std::cout << game->GetUpdateRate();
	}

	IStateHandler& StateManager::GetHandler(typeStateHandlerID id)
	{
		std::map<const int, IStateHandler*>::iterator itr;
		itr = handlers.find(id);
		if(itr != handlers.end())
		{
			IStateHandler* result = itr->second;
			return *result;
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
		return false;
	}

	bool StateManager::IsEmpty()
	{
		return handlers.size() == 0;
	}

}
