#include "canvas.hpp"
#include "line.hpp"
#include "ray.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <memory>
canvas::canvas(){
  this->init_variable();
};

void canvas::init_variable(){
  this->window=new sf::RenderWindow(sf::VideoMode(600,800),"Canvas",sf::Style::Fullscreen);
  this->mouse_pressed=false;
  this->clock.restart();
  this->time_elapsed= clock.getElapsedTime().asSeconds();
}
bool canvas::is_running(){
  return this->window->isOpen();
}

void canvas::poll_events(){ 
  while(this->window->pollEvent(ev)){
    if(ev.type==sf::Event::KeyPressed && ev.key.code == sf:: Keyboard :: Escape){
      this->window->close();
    }
    if(ev.type == sf::Event::MouseMoved && mouse_pressed )
    {
      final_pos =sf::Vector2f( static_cast<float>(sf::Mouse::getPosition().x),static_cast<float> (sf::Mouse::getPosition().y ));
      this->lines.push_back( new line(initial_pos ,final_pos));
      initial_pos=final_pos;
    }
    if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button== sf::Mouse::Right){      
      mouse_pressed=true;
      initial_pos=sf::Vector2f(static_cast<float>(sf::Mouse::getPosition().x),static_cast<float>(sf::Mouse::getPosition().y) );
    }
    if(ev.type == sf::Event::MouseButtonReleased){
      mouse_pressed= false;
    }
    if(ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left){
        this->body = std::make_unique<player> (sf::Mouse::getPosition());
        this->rays.clear();
        for (int i=0 ; i<360 ; i++){
          this->rays.push_back(new ray(static_cast<float>(i) ));
      }
    }

    if(ev.type == sf::Event::KeyPressed ){  
     switch (ev.key.code) {
      case sf::Keyboard::A :
            body->set_param(-1,false);  // move left
        break;
      case sf::Keyboard::D :
            body->set_param(1,false);  // move right
 

        break;

      case sf::Keyboard::W :
            body->set_param(0, true);
            break;
        default:
            body->set_param(0,0);
          break;
     }
      
    }
    if(ev.type ==sf::Event::KeyReleased){
        body->set_param(0, 0);
    }
  }
  
  
}

void canvas::update(){
  this->time_elapsed = clock.getElapsedTime().asSeconds();
  clock.restart();
  this->poll_events();
  if(body){ 
    body->update(time_elapsed);
    // sets the rays to be emanated from player
    for (ray* ray : rays){
      ray->set_position(body->get_position());

      //cast the ray onto walls
      ray->cast(this->lines);
    }
  }
}

void canvas::draw(){
  this->window->clear();
  
  // draw out all the borders
  for(line* entity : lines ){
     this->window->draw(*entity); 
  }

    if(body){
      this->window->draw(*this->body);
      for (ray* ray : rays){
        this->window->draw(*ray);
    }
      
  }
}
void canvas::render(){
  this->draw();
  this->window->display();
}
 
canvas::~canvas(){

  for (line* entity: lines){
    delete entity;
  }
  for(ray* ray : rays){
    delete ray;
  }
  delete this->window;
}
