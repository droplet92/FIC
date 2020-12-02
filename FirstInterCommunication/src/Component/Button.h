#pragma once
#include <functional>
#include <memory>
#include "../GameObject.h"
#include "../TextureAttribute.h"
#include "../MouseState.h"

namespace Component
{
	class Button : public FIC::GameObject
	{
		using Listener = std::function<void()>;

	public:
		Button(Texture::TextureAttribute textureAttribute, const sf::Vector2f& pos);
		~Button();

		void attachListener(Listener listener);

	private:
		struct Impl;
		std::unique_ptr<Impl> pImpl;

		void onFocus() final;
		void onClick() final;
	};
}