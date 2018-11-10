#include <iostream>
#include "SDL_Plotter.h"
using namespace std;

int main(int argc, char ** argv)
{
	SDL_Plotter g(768,1024);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd;
	int R,G,B;

	// test test test

	// Plot base floor width
	for (int i = 1; i <= 1024; i++)
	{
		// Plot base floor height
		for (int j = 1; j < 768; j++)
		{
			g.plotPixel(i, j, 0,0,0);
		}
	}

	// Color background black
	for (int i = 1; i <= 1024; i++)
	{
		// Plot background width
		for (int j = 710; j < 768; j++)
		{
			g.plotPixel(i, j, 135,45,45);
		}
	}

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