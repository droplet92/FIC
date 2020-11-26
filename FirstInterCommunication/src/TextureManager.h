#pragma once
#include <unordered_map>
#include <SFML/Graphics/Texture.hpp>

namespace FIC
{
	struct TextureNumber
	{
		int uniqueNumber;
	};

	class TextureManager
	{
	public:

	private:
		using TextureTable = std::unordered_map<TextureNumber, sf::Texture*>;
		TextureTable textureTable;
	};
}