#include "player.hpp"
#include <SFML/System/Vector2.hpp>
#include <cmath>
#include <iostream>


 void player::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  target.draw((this->body),states);
  target.draw((this->direction),states);
}


void player::configure_variables(sf::Vector2i& position){
  
  this->dir=0;
  this->move=0;

  this->body.setOrigin(10.0f,10.0f);
  this->direction.setOrigin(2.0f,20.0f);

  this->body.setPosition(position.x,position.y);
  this->direction.setPosition(position.x,position.y);
}


void player::set_position(sf::Vector2i position){
  this->body.setPosition(position.x,position.y);
  this->direction.setPosition(position.x,position.y); 
}


player::player(sf::Vector2i position) : body(10.f) , direction(sf::Vector2f(4.0f, 20.0f)) , rotation_speed(95.0f),translation_speed(60.0f)   {
  this->configure_variables(position); 
} 

void player::set_param(int dir, bool move){
  this->dir = dir;
  this->move = move;
}

void player::rotate( double dt ){
  
  this->direction.rotate(this->rotation_speed*dt*this->dir);
}


void player::update(double dt){
  if(this->move){
    this->translate(dt);
  }
  else{
    this->rotate(dt);
  }

}

void player::translate(double dt){
  
  float angle = this->direction.getRotation()*M_PI/180;


  // Why???????????????????????????????????????????/
  float dx = sin(angle)*translation_speed*dt;
  float dy = cos(angle)*translation_speed*dt;
  //WHY????????????????????????????????????????????/
  this->body.move(dx,-dy);
  this->direction.move(dx,-dy);
  
}

sf::Vector2f player::get_position(){
  return this->body.getPosition();  
}
player::~player(){
  
}
