
#include "Game.hpp"
#include "StateManager.hpp"
#include <iostream>

namespace SGE
{
	Game::Game(std::string title)
	{
		this->title = title;
		SetUpdateRate(UPDATE_RATE);
		stateManager = &StateManager();
	}
	Game::~Game()
	{
	}
	int Game::Run()
	{
		std::cout << title << "\n";
		running = true;

		// Register with Stat Manager and State Manager
		//statManager.RegisterGame(this);
		stateManager->RegisterGame(this);

		// Get settings

		// Open window


		// Register handlers with AssetManager

		// Initialize Stat Manager

		GameLoop();

		Cleanup();

		running = false;

		return 0;
	}

	bool Game::IsRunning()
	{
		return running;
	}

	sf::Int32 Game::GetUpdateRate()
	{
		return updateRate;
	}

	void Game::SetUpdateRate(sf::Int32 newRate)
	{
		updateRate = newRate;
	}
	
	void Game::Quit(int exitCode)
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
		if (stateManager->IsEmpty())
		{
			std::cout<< "StateManager created.\n";
		}

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

//	void Game::ProcessInput(IState state)
//	{
//		// Stub
//	}

	void Game::Cleanup()
	{
		// Stub
	}
}