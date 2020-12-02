#pragma once
#include "SFML/Graphics/Sprite.hpp"
#include <vector>
#include <memory>
#include "Time.h"
#include "TextureAttribute.h"
#include "MouseState.h"
#include <SFML/System/Vector2.hpp>

namespace FIC
{
	class Window;

	class GameObject : public sf::Sprite
	{
	public:
		GameObject();
		GameObject(Texture::TextureAttribute textureAttribute);
		~GameObject();

		bool includes(const sf::Vector2i& pos);

		void addChild(GameObject& child);

		void processInput(Mouse::MouseState mouseState, const sf::Vector2i& pos);
		void draw(Window& window) const;
		void update(Time::time_ms dt);

		void setHighlight();
		void clearColor();

	private:
		std::vector<GameObject*> children;

		void _processInput(Mouse::MouseState mouseState);
		virtual void _draw(Window& window) const;
		virtual void _update(Time::time_ms dt);

		virtual void onFocus();
		virtual void onClick();

		void setColor(sf::Color color);
	};
}