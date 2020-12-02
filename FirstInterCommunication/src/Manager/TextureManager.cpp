#include "TextureManager.h"
#include <cassert>

namespace TableFunctions
{
    using namespace Manager;

    bool exist(const TextureManager::TextureTable& table, int textureNumber)
    {
        return (table.find(textureNumber) != table.end());
    }
}

namespace Manager
{
    TextureManager& TextureManager::instance()
    {
        static TextureManager* textureManager = new TextureManager();
        return *textureManager;
    }

    sf::Texture& TextureManager::getTexture(Texture::TextureAttribute textureAttribute)
    {
        if (!TableFunctions::exist(textureTable, textureAttribute.id))
        {
            sf::Texture texture = {};
            if (!texture.loadFromFile(textureAttribute.pathname))
                textureTable[textureAttribute.id] = sf::Texture{};
            else
                textureTable[textureAttribute.id] = texture;
        }
        return textureTable[textureAttribute.id];
    }

}