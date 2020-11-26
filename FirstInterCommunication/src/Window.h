#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

namespace FIC
{
	class Window
	{
	public:
		Window();
		~Window();

		void draw(const GameObject& object) const;
		void clear() const;
		void display() const;

		static const sf::VideoMode windowVideoMode;
		static const std::string windowTitle;

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;
	};
}