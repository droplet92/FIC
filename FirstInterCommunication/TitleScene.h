#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class TitleScene : GameScene
	{
	public:
		~TitleScene() final;

		void initialize();

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}