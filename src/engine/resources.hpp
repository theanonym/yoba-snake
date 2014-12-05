#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include "common.hpp"
#include "singleton.hpp"

class Resources : public Singleton<Resources>
{
public:
   void loadTexture(const std::string & name, const std::string & path);
   void loadFont(const std::string & name, const std::string & path);

   sf::Texture * getTexture(const std::string & name);
   sf::Font * getFont(const std::string & name);

private:
   std::unordered_map<std::string, std::unique_ptr<sf::Texture> > _textures;
   std::unordered_map<std::string, std::unique_ptr<sf::Font> >    _fonts;
};

#endif // RESOURCES_HPP
