#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class Game;

	class PlayingScene : public GameScene
	{
	public:
		PlayingScene(Game& game);
		~PlayingScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
