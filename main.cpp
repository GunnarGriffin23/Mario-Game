#include <iostream>
#include "SDL_Plotter.h"
using namespace std;

void plotImage(SDL_Plotter &game, int i, int j, int r, int g, int b)
{
	for (int x = i; x <= 1024; x++)
	{
	// Plot background width
		for (int y = j; y < 768; y++)
		{
			game.plotPixel(x, y, r, g, b);
		}
	}
}

int main(int argc, char ** argv)
{
	SDL_Plotter g(768,1024);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd;
	int R,G,B;

	plotImage(g,1,1,0,0,0);
	plotImage(g,1,710,135,45,45);

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