#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include <vector>
#include <memory>

namespace FIC
{
	class Window;

	class GameObject : public sf::Sprite
	{
	public:
		void addChild(GameObject& child);
		void draw(Window& window);

	private:
		std::vector<GameObject*> children;
	};
}