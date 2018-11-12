#include <iostream>
#include <fstream>
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
    int x1,y1,r1,g1,b1,a1;
    char buffer[2048];
	SDL_Plotter g(768,1024);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd;
	int R,G,B;

	plotImage(g,1,1,0,0,0);
	plotImage(g,1,710,135,45,45);
	//begining of image read
    ifstream infile("Mario_space_delimited.txt");
    if (!infile)
    {
        cout <<"inputfile.txt no worky" << endl;
        exit(1);
    }

    infile.getline(buffer,2045);
    while(infile>>x1>>y1>>r1>>g1>>b1>>a1)
    {
        if (a1==1) {
            printImage(g, x1, y1, r1, g1, b1);
        }
        infile.getline(buffer, 2045);
    }
//end of image read
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
	infile.close();
}