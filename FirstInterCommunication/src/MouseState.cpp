#include "MouseState.h"

namespace Mouse
{
	MouseState fromIdle(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseMoved:			return MouseState::MOVE;
		case etype::MouseButtonPressed:	return MouseState::PRESS;
		default:	return MouseState::IDLE;
		}
	}
	MouseState fromMove(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseButtonPressed:	return MouseState::PRESS;
		default:	return MouseState::MOVE;
		}
	}
	MouseState fromPress(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseMoved:				return MouseState::DRAG;
		case etype::MouseButtonReleased:	return MouseState::RELEASE;
		default:	return MouseState::PRESS;
		}
	}
	MouseState fromRelease(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseMoved:			return MouseState::MOVE;
		case etype::MouseButtonPressed:	return MouseState::PRESS;
		default:	return MouseState::RELEASE;
		}
	}
	MouseState fromDrag(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseButtonPressed:	return MouseState::DROP;
		default:	return MouseState::DRAG;
		}
	}
	MouseState fromDrop(etype& eventType)
	{
		switch (eventType)
		{
		case etype::MouseMoved:			return MouseState::MOVE;
		case etype::MouseButtonPressed:	return MouseState::PRESS;
		default:	return MouseState::DROP;
		}
	}

	MouseState changeState(MouseState current, etype& eventType)
	{
		return transitionTable.at(current)(eventType);
	}
}