#include "GameObject.h"
#include "Window.h"
#include <SFML/Graphics.hpp>
#include "Manager/TextureManager.h"


namespace FIC
{
	GameObject::GameObject()
	{
	}

	GameObject::GameObject(Texture::TextureAttribute textureAttribute)
	{
		setTexture(Manager::TextureManager::instance().getTexture(textureAttribute));
	}

	GameObject::~GameObject()
	{
	}

	bool GameObject::includes(const sf::Vector2i& pos)
	{
		const sf::FloatRect area = {
			getPosition(),
			sf::Vector2f{
				static_cast<float>(getTextureRect().width),
				static_cast<float>(getTextureRect().height)
			}
		};
		return area.contains(static_cast<const sf::Vector2f>(pos));
	}

	void GameObject::addChild(GameObject& child)
	{
		children.push_back(&child);
	}

	void GameObject::processInput(Mouse::MouseState mouseState, const sf::Vector2i& pos)
	{
		clearColor();

		if (includes(pos))
			_processInput(mouseState);

		std::for_each(children.begin(), children.end(),
			[&](GameObject* child)
			{
				child->processInput(mouseState, pos);
				return;
			});
	}

	void GameObject::draw(Window& window) const
	{
		_draw(window);

		std::for_each(children.begin(), children.end(),
			[&window](const GameObject* child)
			{
				child->draw(window);
			});
	}

	void GameObject::update(Time::time_ms dt)
	{
		_update(dt);

		std::for_each(children.begin(), children.end(),
			[&](GameObject* child)
			{
				child->update(dt);
			});
	}

	void GameObject::setHighlight()
	{
		this->setColor(sf::Color{ 0xF6, 0xBB, 0x43 });
	}

	void GameObject::clearColor()
	{
		this->setColor(sf::Color{ 0xFF, 0xFF, 0xFF, 0xFF });
	}

	void GameObject::_processInput(Mouse::MouseState mouseState)
	{
		onFocus();

		if (mouseState == Mouse::MouseState::RELEASE)
			onClick();
	}

	void GameObject::_draw(Window& window) const
	{
		window.draw(*this);
	}

	void GameObject::_update(Time::time_ms dt)
	{
	}

	void GameObject::onFocus()
	{
	}

	void GameObject::onClick()
	{
	}

	void GameObject::setColor(sf::Color color)
	{
		sf::Sprite::setColor(color);
	}
}
