#include "TitleScene.h"
#include "Button.h"

namespace FIC
{
	struct TitleScene::Impl
	{
		Component::Button startButton;
		Component::Button settingsButton;
		Component::Button recordButton;
		Component::Button exitButton;
	};

	TitleScene::~TitleScene() = default;

	void TitleScene::initialize()
	{
		pImpl->startButton.attachListener([]() { changeScene(); });
	}
}