#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "SDL_Plotter.h"
using namespace std;

class Pixel
{
public:
    int r, g, b;
    void setRed(int R);
    void setGreen(int G);
    void setBlue(int B);
};


void Pixel::setRed(int R)
{
    r = R;
}

void Pixel::setGreen(int G)
{
    g = G;
}

void Pixel::setBlue(int B)
{
    b = B;
}





int main(int argc, char ** argv)
{
	SDL_Plotter g(600,700);
	Pixel dummy[700][7000];
//	vector<Pixel> p1(1);
	bool stopped = false;
	bool colored = false;
	int x,y, xd, yd, skip, count = 0, rowCount = 0, colCount = 0;
	int R,G,B;

	ifstream inFile;
	inFile.open("smol.txt");
	if(!inFile)
    {
        cerr << "The texture file failed to load" << endl;
        exit(1);
    }

//    inFile >> skip;
//    inFile >> skip;
//    inFile >> skip;

    while(inFile >> R >> G >> B)
    {
        dummy[rowCount][colCount].setRed(R);
        dummy[rowCount][colCount].setGreen(G);
        dummy[rowCount][colCount].setBlue(B);
        colCount++;
        if(colCount == 436)
        {
            rowCount++;
            colCount = 0;
        }

//        cout << xc << " " << yc << " " << p1[count].r << " " << p1[count].g << " " << p1[count].b << endl;
//            g.plotPixel(xc, yc, p1[count].r, p1[count].g, p1[count].b);
        count++;
    }

    for(int j = 0; j < 24; j++)
    {
        for(int i = 192; i < 192 + 15; i++)
        {
            g.plotPixel(i,j, dummy[j][i].r, dummy[j][i].g, dummy[j][i].b);
        }
    }




//for(int i = 0; i < 698; i++)
//{
//    int count1 = 0;
//    for(int j = 0; j < 436; j++)
//    {
//        g.plotPixel(j,i,p1[count1].r, p1[count1].g, p1[count1].b);
//        count1++;
//    }
//}





//	// Plot base floor width
//	for (int i = 1; i <= 1024; i++)
//	{
//		// Plot base floor height
//		for (int j = 1; j < 768; j++)
//		{
//			g.plotPixel(i, j, 0,0,0);
//		}
//	}

//	// Color background black
//	for (int i = 1; i <= 1024; i++)
//	{
//		// Plot background width
//		for (int j = 710; j < 768; j++)
//		{
//			g.plotPixel(i, j, 135,45,45);
//		}
//	}

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