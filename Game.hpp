#ifndef GAME_HPP
#define GAME_HPP

#include <stdlib.h>
#include "Control.h"
#include "AssetManager.hpp"
#include "IState.hpp"

namespace SGE
{
	class StateManager;
	class Game
	{
		public:
			Game(std::string title = "Game");
			virtual ~Game();
			int Run();
			bool IsRunning();
			sf::Int32 GetUpdateRate();
			void SetUpdateRate(sf::Int32 newRate);
			void Quit(int exitCode);
		private:
			StateManager* stateManager;
			AssetManager assetManager;
			void GameLoop();
			//void ProcessInput(IState state);
			void Cleanup();
			bool running;
			sf::Int32 updateRate;
			std::string title;
	};
}


#endif