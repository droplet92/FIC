#include "Game.h"
#include "Window.h"
#include "GameObject.h"
#include "GameScene/GameScene.h"
#include "GameScene/GameScenes.h"

namespace FIC
{
	struct Game::Impl
	{
		GameObject* root = new GameObject();
		GameScene& scene = titleScene;
		Window window;
	};

	Game::Game()
		: pImpl(std::make_unique<Game::Impl>())
	{
	}

	Game::~Game() = default;

	void Game::run()
	{
		while (1)
		{
			draw();
		}
	}

	void Game::update()
	{
	}

	void Game::draw()
	{
		pImpl->window.clear();
		pImpl->root->draw(pImpl->window);
		pImpl->window.display();
	}
}