#pragma once

namespace FIC
{
	class Game;

	class GameScene
	{
	public:
		virtual ~GameScene() = 0;

		void changeScene(Game& game);
	};
}