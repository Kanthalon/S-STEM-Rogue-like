#ifndef ISTATEHANDLER_HPP
#define ISTATEHANDLER_HPP

#include <map>
#include "Core_types.hpp"

namespace SGE
{
	class IStateHandler 
	{
		public:
			IStateHandler();
			virtual ~IStateHandler();
			virtual bool DropReference(typeStateID id);
			virtual bool IsLoaded();
			virtual bool LoadState(typeStateID id);
	};
}

#endif
