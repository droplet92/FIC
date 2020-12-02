#pragma once
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>
#include "../TextureAttribute.h"

namespace Manager
{
	class TextureManager
	{
	public:
		using TextureTable = std::unordered_map<int, sf::Texture>;

	public:
		static TextureManager& instance();

		sf::Texture& getTexture(Texture::TextureAttribute textureAttribute);

	private:
		TextureTable textureTable;

	private:
		TextureManager() = default;
	};
}