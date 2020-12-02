#pragma once
#include <cassert>
#include <memory>
#include "../Actor/Actor.h"
#include "../Actor/ActorTypes.h"
#include "../Actor/Player.h"

namespace Factory
{
	class ActorFactory
	{
	public:
		std::unique_ptr<Actor::Actor> createActor(Actor::ActorType actorType)
		{
			switch (actorType)
			{
			case Actor::ActorType::PLAYER:
				return std::make_unique<Actor::Player>(new Actor::Player);

			case Actor::ActorType::MONSTER:
				
			case Actor::ActorType::BULLET:

			case Actor::ActorType::DOOR:

			case Actor::ActorType::PLAYER_ICON:

			case Actor::ActorType::PANEL_LIGHT:

			default:
				std::assert(!"Unknown ActorType.");
			}
		}
	};
}