#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Err.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>
#include <vector>
#include "line.hpp"
#include "player.hpp"
#include "ray.hpp"
class canvas {

  bool mouse_pressed;
    
  sf::Vector2f initial_pos,final_pos;
  sf::RenderWindow* window;
  sf::Event ev;
std::vector<line*> lines;
  sf::Clock clock;
  double time_elapsed;
  std::unique_ptr<player> body;
  std::vector<ray*> rays;

public:
  canvas();

  bool is_running();
  void init_variable();
  void poll_events();
  void update();
  void draw();
  void render();
  ~canvas();
};
