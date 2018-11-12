#include <iostream>
#include "SDL_Plotter.h"
using namespace std;


struct Pixel
{
public:
	int x, y, r, g, b;
	Pixel();
	Pixel(int X, int Y, int R, int G, int B);
};
Pixel::Pixel()
{
	x = 0;
	y = 0;
	r = 0;
	g = 0;
	b = 0;
}
//constructor to make a specific pixel with a X, Y value RGB colors and transparency(alpha)
Pixel::Pixel(int X, int Y, int R, int G, int B)
{
	x = X;
	y = Y;
	r = R;
	g = G;
	b = B;
}

void plotImage(SDL_Plotter &game, Pixel pixel[], int index)
{
	for(int i = 0; i < index; i++)
	{
		game.plotPixel(pixel[i].x, pixel[i].y, pixel[i].r, pixel[i].g, pixel[i].b);
	}
}

//-----------------------------

void plotBackground(SDL_Plotter &game, int i, int j, int id, int jd, int r, int g, int b)
{
	for (int x = i; x <= id; x++)
	{
	// Plot background width
		for (int y = j; y < jd; y++)
		{
			game.plotPixel(x, y, r, g, b);
		}
	}
}

int main(int argc, char ** argv)
{
	Pixel p1[1];
	SDL_Plotter g(768,1024);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd;
	int R,G,B;


	plotBackground(g,0,0,1024,768,0,0,0);
	plotBackground(g,0,710,1024,768,135,45,45);
	plotBackground(g,300,300,320,320,255,155,55);

	while (!g.getQuit())
	{
		if (!stopped)
		{

		}

		if (g.kbhit())
		{
			if (g.getKey() == 'P')
			{
				stopped = !stopped;
			}
			else if (g.getKey() == RIGHT_ARROW)
			{
				// Move mario right
			}
			else if (g.getKey() == LEFT_ARROW)
			{
				// Move mario left
			}
			else if (g.getKey() == UP_ARROW)
			{
				// Mario jump
			}
		}

		g.update();
	}
}