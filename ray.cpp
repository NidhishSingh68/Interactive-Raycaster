#include "ray.hpp"


ray::ray( float angle ): ray_segment(sf::Lines , 2)  {
  this->ray_length_parameter =0.0f; 
  this->angle_offset = angle;  
}
void ray::set_position(sf::Vector2f player_position){
  this->ray_length_parameter =0.0f;
  this->player_pos =player_position;
  ray_segment[0].position = this->player_pos;
  ray_segment[1].position = this->player_pos;
}



// Genetates a line segement from player's postion to the line segment
void ray::cast( std::vector<line*>& walls ){
    // multiplied by 1 (the magnitude) because unit vectors
    float d_x =  1 * cos(this->angle_offset*M_PI/180);
    float d_y = - 1 * sin(this->angle_offset*M_PI/180);     
    
  for(line* wall : walls){
    std::vector<sf::Vector2f> wall_pos = wall->getposition();
    
    float parameter_0 = (this->player_pos.x * d_y + d_x*wall_pos[0].y - d_x*this->player_pos.y - wall_pos[0].x * d_y) / (d_x*wall_pos[0].y - d_x*wall_pos[1].y - wall_pos[0].x * d_y + wall_pos[1].x*d_y);
    float parameter_1 = ((1-parameter_0)*wall_pos[0].x + parameter_0*wall_pos[1].x - this->player_pos.x) / d_x;
     
    
    if(this->ray_length_parameter!=0){
      if(parameter_1 > this->ray_length_parameter){
        continue;
      }
    }
    //condition for ray and a linesegment to intersect
    if(parameter_0 >= 0 && parameter_0 <= 1 && parameter_1 >= 0 ){

        this->ray_terminal_pt = sf::Vector2f(this->player_pos.x + parameter_1*d_x, this->player_pos.y + parameter_1*d_y);
        ray_segment[1].position = this->ray_terminal_pt;
        this->ray_length_parameter = parameter_1;
    }
       
      
  }
}

void ray::draw(sf::RenderTarget& target, sf::RenderStates states) const{
  target.draw(this->ray_segment,states);
}


ray::~ray(){


}
