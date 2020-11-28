#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class PlayingScene : public GameScene
	{
	public:
		PlayingScene();
		~PlayingScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
