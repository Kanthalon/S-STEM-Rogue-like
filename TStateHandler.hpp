#ifndef TSTATEHANDLER_HPP
#define TSTATEHANDLER_HPP

#include <map>
#include "IStateHandler.hpp"
#include "Core_types.hpp"

namespace SGE
{
	template<class TYPE>
	class TStateHandler : public IStateHandler
	{
		public:
			TStateHandler();
			virtual ~TStateHandler();
			bool DropReference(typeStateID id);
			bool IsLoaded();
			bool LoadState(typeStateID id);
		private:
			static typeStateHandlerID idOffset;
			typeStateHandlerID id;
	};
}

#endif
