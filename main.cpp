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

int main(int argc, char ** argv) {
	SDL_Plotter g(768, 1024);
	bool stopped = false;
//	bool colored = false;
//	int x, y, xd, yd;
	int playerx = 50, playery = 0, playerWidth = 10, playerHeight = 10, jumptime = -9;
//	int R, G, B;

//	plotImage(g, 0, 0, 0, 0, 0);
//	plotImage(g, 0, 710, 135, 45, 45);

	while (!g.getQuit())
	{
		//Player input
		if (g.getKey() == 'P')
		{
			stopped = !stopped;
		}
		else if (g.getKey() == RIGHT_ARROW)
		{
			playerx = min(playerx + 1, 1024 - playerWidth);
		}
		else if (g.getKey() == LEFT_ARROW)
		{
			playerx = max(playerx - 1, 0);
		}
		else if (g.getKey() == UP_ARROW)
		{
			if(jumptime == -9)
				jumptime = 10;
		}

		if(jumptime > -10)
		{
			jumptime--;

			if(jumptime > 0)
				playery = max(playery - 1, 0);
			else
				playery = min(playery + 1, 768 - playerHeight);
		}

		//Draw loop

		g.clear();

		for (int col = playerx; col < playerWidth + playerx; col++)
		{
			for (int row = playery; row < playerHeight + playery; row++)
			{
				g.plotPixel(col, row, 255, 0, 0);
			}
		}

		g.update();

		if (g.kbhit())
		{
			g.getKey();
		}
	}
}
