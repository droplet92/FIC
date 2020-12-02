#include "Button.h"

namespace Component
{
	struct Button::Impl
	{
		Listener listener = [] {};
	};

	Button::Button(Texture::TextureAttribute textureAttribute, const sf::Vector2f& pos)
		: GameObject(textureAttribute)
		, pImpl(new Impl)
	{
		setPosition(pos);
	}

	Button::~Button() = default;

	void Button::attachListener(Listener listener)
	{
		const auto& current = pImpl->listener;
		pImpl->listener = [=] { current(); listener(); };
	}

	void Button::onFocus()
	{
		setHighlight();
	}

	void Button::onClick()
	{
		pImpl->listener();
	}
}
		