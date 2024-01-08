#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <vector>

class line: public sf::Drawable{
private: 
  sf::VertexArray stroke;
  sf::Vector2f  start_pt;
  sf::Vector2f  end_pt;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

  line(sf::Vector2f A ,sf::Vector2f B);
  ~line();
  std::vector<sf::Vector2f> getposition();
};
