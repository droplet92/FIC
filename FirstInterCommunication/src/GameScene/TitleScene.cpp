#include "TitleScene.h"
#include "../Component/Button.h"

namespace FIC
{
	struct TitleScene::Impl
	{
		Component::Button startButton;
		Component::Button settingsButton;
		Component::Button recordButton;
		Component::Button exitButton;
	};

	TitleScene::TitleScene()
	{
		//pImpl->startButton.attachListener([]() { changeScene(); });
	}

	TitleScene::~TitleScene() = default;
}