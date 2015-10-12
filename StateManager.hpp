#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <map>
#include "TStateHandler.hpp"

namespace SGE
{
	class StateManager
	{
		public:
			StateManager();
			virtual ~StateManager();
			bool AddHandler(TStateHandler* handler);
			IStateHandler& GetHandler(typeStateHandlerID id);

		private:
			std::map<const int, IStateHandler*> handlers;


	}
}

#endif
