#pragma once
#include <memory>
#include "Time.h"
#include "GameScene/GameScene.h"

namespace FIC
{
	class Game
	{
	public:
		Game();
		~Game();

		void run();

		void processInput();
		void update(Time::time_ms dt);
		void draw();

		void changeScene(GameScene* gameScene);
		void exit() const;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}