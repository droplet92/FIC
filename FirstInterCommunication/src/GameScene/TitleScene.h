#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class Game;

	class TitleScene : public GameScene
	{
	public:
		TitleScene(Game& game);
		~TitleScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}