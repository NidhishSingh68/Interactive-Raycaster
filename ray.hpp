#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <cmath>
#include "line.hpp"
#include "player.hpp"
class ray :public sf::Drawable{
  float angle_offset;
  sf::VertexArray ray_segment;
  sf::Vector2f player_pos , ray_terminal_pt;
  float ray_length_parameter;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  public:
    ray( float angle );
    ~ray();
    void set_position(sf::Vector2f player_pos);
    void cast( std::vector<line*>& walls );
};
