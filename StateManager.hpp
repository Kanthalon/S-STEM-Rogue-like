#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <map>
#include "TStateHandler.hpp"

namespace SGE
{
	class Game;
	class StateManager
	{
		public:
			StateManager();
			virtual ~StateManager();
			void RegisterGame(Game* g);
			bool AddHandler(IStateHandler* handler);
			IStateHandler& GetHandler(typeStateHandlerID id);
			bool IsEmpty();

		private:
			Game* game;
			std::map<const int, IStateHandler*> handlers;
	};
}

#endif
