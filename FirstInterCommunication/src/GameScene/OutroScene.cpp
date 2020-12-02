#include "OutroScene.h"
#include "../Game.h"

namespace FIC
{
	struct OutroScene::Impl
	{
	};

	OutroScene::OutroScene(Game& game)
		: GameScene(game)
		, pImpl(new Impl)
	{
	}

	OutroScene::~OutroScene() = default;
}