#include "ActorFactory.h"

namespace Factory
{
	struct ActorFactory::Impl
	{

	};

	ActorFactory::ActorFactory()
		: pImpl(new Impl)
	{
	}

	ActorFactory::~ActorFactory() = default;
}
