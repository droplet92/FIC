#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class Game;

	class IntroScene : public GameScene
	{
	public:
		IntroScene(Game& game);
		~IntroScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;

		void onClick() final;
	};
}