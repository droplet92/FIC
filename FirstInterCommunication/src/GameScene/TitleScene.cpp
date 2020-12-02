#include "TitleScene.h"
#include "../Component/Button.h"
#include "../GameObject.h"
#include "../TextureAttribute.h"
#include "../Game.h"
#include "IntroScene.h"

namespace FIC
{
	const Texture::TextureAttribute backgroundImageAttribute = { 1, "background.jpg" };

	const Texture::TextureAttribute startButtonAttribute	= { 2, "start_button.png" };
	const Texture::TextureAttribute settingsButtonAttribute = { 3, "settings_button.png" };
	const Texture::TextureAttribute exitButtonAttribute		= { 4, "exit_button.png" };

	const sf::Vector2f startButtonPos		= { 760,540 };
	const sf::Vector2f settingsButtonPos	= { 760,720 };
	const sf::Vector2f exitButtonPos		= { 760,900 };

	struct TitleScene::Impl
	{
		GameObject backgroundImage{ backgroundImageAttribute };

		Component::Button startButton{ startButtonAttribute, startButtonPos };
		Component::Button settingsButton{ settingsButtonAttribute, settingsButtonPos };
		Component::Button exitButton{ exitButtonAttribute, exitButtonPos };
	};

	TitleScene::TitleScene(Game& game)
		: GameScene(game)
		, pImpl(new Impl)
	{
		addChild(pImpl->backgroundImage);
		addChild(pImpl->startButton);
		addChild(pImpl->settingsButton);
		addChild(pImpl->exitButton);
		pImpl->startButton.attachListener([&]() { game.changeScene(new IntroScene(game)); });
		//pImpl->settingsButton.attachListener([]() { changeScene(); });
		pImpl->exitButton.attachListener([&]() { game.exit(); });
	}

	TitleScene::~TitleScene() = default;
}