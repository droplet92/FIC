#include "Game.h"
#include "Window.h"
#include "GameObject.h"
#include "GameScene/TitleScene.h"
#include "Stopwatch.h"
#include "Component/Mouse.h"

namespace FIC
{
	struct Game::Impl
	{
		GameScene* scene, *prev;
		Window window;
		Component::Mouse mouse;
	};

	Game::Game()
		: pImpl(new Impl)
	{
		pImpl->prev = pImpl->scene = new TitleScene(*this);
	}

	Game::~Game() = default;

	void Game::run()
	{
		Time::Stopwatch stopwatch;

		while (pImpl->window.isOpen())
		{
			Time::time_ms dt = stopwatch.stop();
			processInput();
			update(dt);
			stopwatch.clear();
			stopwatch.start();
			draw();
		}
	}

	void Game::processInput()
	{
		sf::Event event;

		while (pImpl->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed
				|| event.key.code == sf::Keyboard::Key::Escape)
			{
				pImpl->window.close();
			}
			pImpl->mouse.updateState(event.type);

			pImpl->scene->processInput(
				pImpl->mouse.getState(),
				pImpl->mouse.getPosition()
			);
		}
	}

	void Game::update(Time::time_ms dt)
	{
		if (pImpl->prev != pImpl->scene)
		{
			delete pImpl->prev;
			pImpl->prev = pImpl->scene;
		}
		pImpl->mouse.update(dt);
		pImpl->scene->update(dt);
	}

	void Game::draw()
	{
		pImpl->window.clear();
		pImpl->mouse.draw(pImpl->window);
		pImpl->scene->draw(pImpl->window);
		pImpl->window.display();
	}

	void Game::changeScene(GameScene* gameScene)
	{
		pImpl->scene = gameScene;
	}

	void Game::exit() const
	{
		pImpl->window.close();
	}
}