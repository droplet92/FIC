#include "Button.h"

namespace Component
{
	struct Button::Impl
	{
		Listener listener = [] {};
	};

	Button::Button()
		: pImpl(new Impl)
	{
	}

	Button::~Button() = default;

	void Button::attachListener(Listener listener)
	{
		const auto& current = pImpl->listener;
		pImpl->listener = [=] { current(); listener(); };
	}

	void Button::click()
	{
		pImpl->listener();
	}
}
