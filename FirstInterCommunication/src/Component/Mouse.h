#pragma once
#include "../GameObject.h"
#include "../Time.h"
#include <memory>
#include <SFML/Window/Event.hpp>
#include "../MouseState.h"

using namespace Mouse;

using etype = sf::Event::EventType;

namespace Component
{
	class Mouse : public FIC::GameObject
	{
	public:
		Mouse();
		~Mouse();

		MouseState getState() const;
		sf::Vector2i getPosition() const;

		void updateState(etype& eventType);

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}