#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class Game;

	class OutroScene : public GameScene
	{
	public:
		OutroScene(Game& game);
		~OutroScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
