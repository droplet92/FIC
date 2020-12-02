#pragma once
#include "../GameObject.h"

namespace FIC
{
	class Game;

	class GameScene : public GameObject
	{
	public:
		GameScene(Game& game);
		virtual ~GameScene() = 0;

	protected:
		Game& game;
	};
}
