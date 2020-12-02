#pragma once
#include <SFML/Window/Event.hpp>
#include <functional>
#include <unordered_map>

namespace Mouse
{
	enum class MouseState
	{
		IDLE,
		MOVE,
		PRESS,
		RELEASE,
		DRAG,
		DROP
	};

	using etype = sf::Event::EventType;
	using Transferer = std::function<MouseState(etype&)>;
	using StateTransitionTable = std::unordered_map<MouseState, Transferer>;

	MouseState fromIdle(etype& eventType);
	MouseState fromMove(etype& eventType);
	MouseState fromPress(etype& eventType);
	MouseState fromRelease(etype& eventType);
	MouseState fromDrag(etype& eventType);
	MouseState fromDrop(etype& eventType);

	static const StateTransitionTable transitionTable = {
		{ MouseState::IDLE, fromIdle },
		{ MouseState::MOVE, fromMove },
		{ MouseState::PRESS, fromPress },
		{ MouseState::RELEASE, fromRelease },
		{ MouseState::DRAG, fromDrag },
		{ MouseState::DROP, fromDrop },
	};

	MouseState changeState(MouseState current, etype& eventType);
}