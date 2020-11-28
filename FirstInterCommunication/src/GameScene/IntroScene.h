#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class IntroScene : public GameScene
	{
	public:
		IntroScene();
		~IntroScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}