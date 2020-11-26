#include "GameObject.h"
#include "Window.h"

namespace FIC
{
	void GameObject::addChild(GameObject& child)
	{
		children.push_back(&child);
	}

	void GameObject::draw(Window& window)
	{
		std::for_each(children.begin(), children.end(),
			[&window](const GameObject* child)
			{
				window.draw(*child);
			});
	}
}
