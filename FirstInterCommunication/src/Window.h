#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <string>
#include <memory>

namespace FIC
{
	class Window
	{
	public:
		Window();
		~Window();

		bool isOpen() const;

		void draw(const GameObject& object) const;
		void clear() const;
		void display() const;

		bool pollEvent(sf::Event& event);
		void close() const;

		static const sf::VideoMode windowVideoMode;
		static const std::string windowTitle;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}