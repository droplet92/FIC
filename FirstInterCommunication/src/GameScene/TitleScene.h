#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class TitleScene : public GameScene
	{
	public:
		TitleScene();
		~TitleScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}