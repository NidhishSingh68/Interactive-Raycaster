#include "canvas.hpp"

int main(){
  canvas canvas;
  
  while(canvas.is_running()){
    canvas.update();
    canvas.render();
  }
  
  return 1;
}
