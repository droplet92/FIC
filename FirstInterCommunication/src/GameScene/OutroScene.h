#pragma once
#include "GameScene.h"
#include <memory>

namespace FIC
{
	class OutroScene : public GameScene
	{
	public:
		OutroScene();
		~OutroScene() final;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}
