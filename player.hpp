#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <cmath>


class player: public sf::Drawable{
  
  float rotation_speed;
  float translation_speed;
  int dir;
  bool move;
  sf::CircleShape body;
  
  sf::RectangleShape direction;

  void configure_variables(sf::Vector2i& position); 
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  public:
    player(); 
    player(sf::Vector2i position);
    ~player();
    sf::Vector2f get_position();
    void set_position(sf::Vector2i position); 
    void set_param(int dir , bool move);
    void update ( double dt); 
    void rotate( double dt);
    void translate(double dt);
};


