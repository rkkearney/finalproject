#include <stdio.h>
#include <math.h>
#include "gfx4.h"
#include "titlescreenfunc.h"

int main ()
{
	char c;
	int X, Y, check;
	int xsize = 800, ysize = 800, minixsize = 400, miniysize = 750;
	int treasure;

	/*// Set Up Window
	gfx_open(xsize, ysize, "YoHo: A Pirate's Life");
	gfx_clear();
	
	// Draw Window
	printBackground(xsize, ysize);
	printTitle();
	printMenu();*/
	printTitleScreen(xsize, ysize);
	
	while(1)
	{
		c = gfx_wait();
			
		switch (c)
		{
			case 1:
				X = gfx_xpos();
				Y = gfx_ypos();
				check = checkZone(X, Y);
				switch (check)
				{
					case 0: // Quit
						return 0;
						break;
					case 1: // Attack
					case 2: // Treasure
						/*gfx_open(minixsize, miniysize, "Mini Game");
						gfx_clear();
						if (check == 1)
						{
							printf("Attack!!\n");
						}
						if (check == 2)
						{
							treasure = treasureHunt();
						}*/
						playGame(minixsize, miniysize, check);
						break;
					case 3: // Rum
						break;
					case 4: // Store
						break;
				}
				break;
		}
		printTitleScreen(xsize, ysize);
	}
	
	return 0;
}