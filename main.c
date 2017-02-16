#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
 
  
  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;
  
  clear_screen(s);

  //////////////////////////test cases//////////////////////////

  //From origin, to octant 1 or 2
  draw_line(0, 0, 100, 100, s, c);
  draw_line(0, 0, 110, 50, s, c);
  draw_line(100, 200, 0, 0, s, c);

  //Not from origin, to octant 1 or 2
  draw_line(50, 50, 150, 150, s, c);
  draw_line(50, 50, 160, 100, s, c);
  draw_line(150, 250, 50, 50, s, c);

  draw_line(300, 300, 400, 400, s, c);
  draw_line(200, 200, 310, 250, s, c);
  draw_line(300, 400, 200, 200, s, c);

  //Not from origin, to octant 7 or 8
  draw_line(0, 300, 300, 0, s, c);
  draw_line(0, 300, 300, 150, s, c);
  draw_line(0, 400, 300, 0, s, c);

  //horizontal line
  draw_line(0, 300, 300, 300, s, c);

  //vertical line
  draw_line(400, 0, 400, 400, s, c);

  display(s);
  save_extension(s, "lines.png");
}  
