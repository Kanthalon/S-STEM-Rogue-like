
#include "Game.hpp"

namespace SGE
{
	Game::Game(std::string title)
	{
		this->title = title;
	}
	Game::~Game()
	{
	}
	int Game::Run()
	{
		running = true;

		// Register with State Manager
		//stateManager.RegisterGame(this);

		// Register handlers with AssetManager

		InitAssetHandlers();

		GameLoop();

		Cleanup();

		return 0;
	}

	bool Game::IsRunning()
	{
		return running;
	}

	float Game::GetUpdateRate()
	{
		return updateRate;
	}

	void Game::SetUpdateRate(float newRate)
	{
		updateRate = newRate;
	}
	
	void Game::Quit(int exitCode)
	{
		// Stub
	}

	void Game::InitAssetHandlers()
	{
		// Stub
	}

	void Game::GameLoop()
	{
		sf::Clock updateClock;
		sf::Clock frameClock;
		updateClock.restart();
		sf::Int32 nextUpdateTime = updateClock.getElapsedTime().asMilliseconds();

		// Check if StateManager loaded correctly

		// Loop while running
		{

			// Get active state

			// ProcessInput(currentState);

			sf::Int32 updateTime = updateClock.restart().asMilliseconds();

			while ((updateTime - nextUpdateTime) >= updateRate/* && updates <= maxUpdates*/)
			{
				// State updates

				// StatManager updates

				nextUpdateTime += updateRate;
			}

			// Pass frameClock time to state

			// State draws

			// StatManager draws

			// Display Window

			// StateManager does any necessary cleanup
		}
	}

	void Game::ProcessInput(IState state)
	{
		// Stub
	}

	void Game::Cleanup()
	{
		// Stub
	}
}