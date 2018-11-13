#include <iostream>
#include <fstream>
#include "SDL_Plotter.h"
#include "Pixel.h"
using namespace std;


int main(int argc, char ** argv)
{
    int x1,y1,r1,g1,b1,a1, count = 0;
    char buffer[2048];
	Pixel p1[786432];
	SDL_Plotter g(768,1024);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd;
	int R,G,B;

    ifstream infile("Mario.txt");
    if (!infile)
    {
        cout <<"inputfile.txt no worky" << endl;
        exit(1);
    }

    infile.getline(buffer,2045);
    while(!infile.eof())
    {
        infile>>x1>>y1>>r1>>g1>>b1>>a1;
        if (a1==1)
        {
//            p1[count].x = x1;
//            p1[count].y = y1;
//            p1[count].r = r1;
//            p1[count].g = g1;
//            p1[count].b = b1;
            p1[count]=Pixel(x1, y1, r1, g1, b1);
            count++;
        }

        infile.getline(buffer, 2045);
    }

	plotBackground(g,0,0,1024,768,0,0,0);
	plotBackground(g,0,710,1024,768,135,45,45);
	plotBackground(g,300,300,320,320,255,155,55);
	plotImage(g, p1, count-1);

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