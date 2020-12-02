#include "IntroScene.h"
#include "PlayingScene.h"
#include "../Game.h"

namespace FIC
{
	const Texture::TextureAttribute backgroundImageAttribute = { 1, "background.jpg" };

	struct IntroScene::Impl
	{
		GameObject backgroundImage{ backgroundImageAttribute };
	};

	IntroScene::IntroScene(Game& game)
		: GameScene(game)
		, pImpl(new Impl)
	{
		setTextureRect(sf::IntRect(0, 0, 1920, 1080));
		addChild(pImpl->backgroundImage);
	}

	IntroScene::~IntroScene() = default;

	void IntroScene::onClick()
	{
		// next text
		game.changeScene(new PlayingScene(game));
	}
}