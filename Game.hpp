#ifndef GAME_HPP
#define GAME_HPP

#include <stdlib.h>
#include "AssetManager.hpp"
#include "StateManager.hpp"
#include "IState.hpp"

namespace SGE
{
	class Game
	{
		public:
			AssetManager assetManager;
			StateManager stateManager;
			Game(std::string title = "Game");
			virtual ~Game();
			int Run();
			bool IsRunning();
			float GetUpdateRate();
			void SetUpdateRate(float newRate);
			void Quit(int exitCode);
		private:
			void InitAssetHandlers();
			void GameLoop();
			void ProcessInput(IState state);
			void Cleanup();
			bool running;
			sf::Int32 updateRate;
			std::string title;
	};
}


#endif