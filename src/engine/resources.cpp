#include "resources.hpp"

void Resources::loadTexture(const std::string & name,
                            const std::string & path)
{
   std::unique_ptr<sf::Texture> texture(new sf::Texture);
   assert(texture->loadFromFile(path));

   texture->setSmooth(true);
   texture->setRepeated(true);

   _textures[name] = std::move(texture);
}

void Resources::loadFont(const std::string & name,
                         const std::string & path)
{
   std::unique_ptr<sf::Font> font(new sf::Font);
   assert(font->loadFromFile(path));
   _fonts[name] = std::move(font);
}

sf::Texture * Resources::getTexture(const std::string & name)
{
   auto it = _textures.find(name);
   assert(it != _textures.end());
   return it->second.get();
}

sf::Font * Resources::getFont(const std::string & name)
{
   auto it = _fonts.find(name);
   assert(it != _fonts.end());
   return it->second.get();
}
