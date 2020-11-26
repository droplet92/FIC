#include "Window.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"

namespace FIC
{
	constexpr unsigned int windowWidth = 800;
	constexpr unsigned int windowHeight = 600;
	const sf::VideoMode Window::windowVideoMode = { windowWidth, windowHeight };
	const std::string Window::windowTitle = "FIC";

	struct Window::Impl
	{
		sf::RenderWindow window{ windowVideoMode, windowTitle };
	};

	Window::Window()
		: pImpl(std::make_unique<Window::Impl>())
	{
	}

	Window::~Window() = default;

	void Window::draw(const GameObject& object) const
	{
		pImpl->window.draw(object);
	}

	void Window::clear() const
	{
		pImpl->window.clear(sf::Color::Blue);
	}

	void Window::display() const
	{
		pImpl->window.display();
	}
}