#include "line.hpp"
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iterator>
#include <vector>

line::line( sf::Vector2f A , sf::Vector2f B): start_pt(A) , end_pt(B), stroke(sf::Lines,2)
{
  stroke[0].position = start_pt;
  stroke[1].position = end_pt;
}

void line::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  target.draw(stroke,states);
}

std::vector<sf::Vector2f> line::getposition(){
  std::vector<sf::Vector2f> bounds =  {start_pt ,end_pt};
  return bounds;
}

line::~line(){

}
