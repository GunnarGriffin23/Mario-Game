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
    int playerx = 50, playery = 100, playerWidth = 10, playerHeight = 10, jumptime = 0;
    int hsp = 0, vsp = 0;
//	int R, G, B;

//	plotImage(g, 0, 0, 0, 0, 0);
//	plotImage(g, 0, 710, 135, 45, 45);

    while (!g.getQuit())
    {
        hsp = 0;
        //Player input
        if (g.getKey() == 'P')
        {
            stopped = !stopped;
        }
        else if (g.getKey() == UP_ARROW)
        {
            if(jumptime == 0)
                jumptime = 600;
        }
        else if (g.getKey() == RIGHT_ARROW)
        {
            hsp = 1;
        }
        else if (g.getKey() == LEFT_ARROW)
        {
            hsp = -1;
        }

        playerx = playerx + hsp;

        if((playery + playerHeight) != 768)
        {
            playery += 1;
        }

        if(jumptime != 0)
        {
            jumptime--;

            if(jumptime > 300)
                playery -= 2;
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