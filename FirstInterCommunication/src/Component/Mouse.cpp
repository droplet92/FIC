#include "Mouse.h"
#include <SFML/Window.hpp>
using namespace Mouse;

namespace Component
{
	struct Mouse::Impl
	{
		MouseState state = MouseState::IDLE;
		sf::Mouse mouse;
	};

	Mouse::Mouse()
		: GameObject()
		, pImpl(new Impl)
	{
	}

	Mouse::~Mouse() = default;

	MouseState Mouse::getState() const
	{
		return pImpl->state;
	}

	sf::Vector2i Mouse::getPosition() const
	{
		return pImpl->mouse.getPosition();
	}

	void Mouse::updateState(etype& eventType)
	{
		pImpl->state = changeState(pImpl->state, eventType);
	}
}