#include "Window.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "GameObject.h"

namespace FIC
{
	constexpr unsigned int windowWidth = 1920;
	constexpr unsigned int windowHeight = 1080;
	const sf::VideoMode Window::windowVideoMode = { windowWidth, windowHeight };
	const std::string Window::windowTitle = "FIC";

	struct Window::Impl
	{
		sf::RenderWindow window{ windowVideoMode, windowTitle, sf::Style::Fullscreen };
	};

	Window::Window()
		: pImpl(new Impl)
	{
	}

	Window::~Window() = default;

	bool Window::isOpen() const
	{
		return pImpl->window.isOpen();
	}

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

	bool Window::pollEvent(sf::Event& event)
	{
		return pImpl->window.pollEvent(event);
	}

	void Window::close() const
	{
		pImpl->window.close();
	}
}