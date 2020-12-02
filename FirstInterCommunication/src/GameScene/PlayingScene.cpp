#include "PlayingScene.h"
#include "../Game.h"

namespace FIC
{
	const Texture::TextureAttribute backgroundImageAttribute = { 1, "background.jpg" };
	const Texture::TextureAttribute moonshotAttribute = { 5, "moonshot.png" };

	struct PlayingScene::Impl
	{
		GameObject backgroundImage{ backgroundImageAttribute };

		GameObject moonshot{ moonshotAttribute };
	};

	PlayingScene::PlayingScene(Game& game)
		: GameScene(game)
		, pImpl(new Impl)
	{
		addChild(pImpl->backgroundImage);
		addChild(pImpl->moonshot);
	}

	PlayingScene::~PlayingScene() = default;
}