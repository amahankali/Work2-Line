#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"


//switched - true if octant 2 or octant 7
//downward - true if octant 7 or octant 8
void draw_line_oct(int x0, int y0, int x1, int y1, screen s, color c, int switched, int downward) {

	int A = (y1 - y0);
	int B = -1 * (x1 - x0);
	int d = 2 * A + B;

	int x = x0; int y = y0;

	//printf("Switched: %d\n", switched);
	//printf("Downward: %d\n", downward);

	while(x <= x1)
	{
		int px, py;
		if(!switched && !downward)
		{
			px = x;
			py = y;
		}
		else if(switched && !downward)
		{
			px = y;
			py = x;
		}
		else if(!switched && downward)
		{
			px = x;
			py = 2 * y0 - y;
		}
		else
		{
			px = y;
			py = 2 * x0 - x;
		}

		plot(s, c, px, py);
		//printf("(%d, %d)\n", px, py);

		if(d > 0)
		{
			y++;
			d += 2 * B;
		}
		x++;
		d += 2 * A;
	}

}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {

	//figure out which one is point 0 and which one is point 1
	//if x coordinates are equal, break ties with y coordinates
	if(x0 > x1 || (x0 == x1 && y0 > y1)) //conditions for swap
	{
		int temp;

		//swap x0 and x1
		temp = x0;
		x0 = x1;
		x1 = temp;

		//swap y0 and y1
		temp = y0;
		y0 = y1;
		y1 = temp;
	}
	printf("(%d, %d) --> (%d, %d)\n", x0, y0, x1, y1);

	int deltaX = (x1 - x0);
	int deltaY = (y1 - y0);

	if(deltaY > deltaX) draw_line_oct(y0, x0, y1, x1, s, c, 1, 0);
	else if(deltaY <= deltaX && deltaY >= 0) draw_line_oct(x0, y0, x1, y1, s, c, 0, 0);
	else if(deltaY < 0 && deltaY >= -1 * deltaX) draw_line_oct(x0, y0, x1, 2 * y0 - y1, s, c, 0, 1);
	else draw_line_oct(y0, x0, 2 * y0 - y1, x1, s, c, 1, 1);
}