#ifndef ISTATE_HPP
#define ISTATE_HPP

#include <SFML/Graphics.hpp>

namespace SGE
{
	class IState 
	{
		public:
			IState();
			~IState();
			void Draw(); //Passed a window
			void HandleEvent(sf::Event evnt);
			void Pause();
			void Resume();
			float GetTime();
		private:
			sf::Clock runningClock;
			sf::Clock pausedClock;
			float runningTime;
			float pausedTime;

	}
}

#endif
