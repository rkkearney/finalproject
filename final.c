#include <stdio.h>
#include <math.h>
#include "gfx4.h"
#include "finalfunc.h"

int main ()
{
	char c;							// user input from keyboard
	int X, Y, check;				// X position, Y position, check for zone
	int xsize = 800, ysize = 800;	// window sizes

	gfx_open(xsize, ysize, "YoHo: A Pirate's Life");	// opens window
	printTitleScreen(xsize, ysize);						// prints title screen
	
	while(1)
	{
		c = gfx_wait();		// gets user input
			
		switch (c)
		{
			case 1:	// click
				X = gfx_xpos();				// gets X position of click
				Y = gfx_ypos();				// gets y position of click
				check = checkZone(X, Y);	// checks range of click position
				switch (check)
				{
					case 0: // Quit
						return 0;
						break;
					case 1: // Attack
						gfx_clear();
						attackShips(); 		// runs attack minigame
						break;
					case 2: // Treasure
						gfx_clear();	
						treasureHunt();		// runs treasure minigame
						break;
					case 3: // Rum
						gfx_clear();	
						drinkRum();			// runs run screen
						break;
				}
				break;
		}
		printTitleScreen(xsize, ysize); // reprints title screen following minigames
	}
	
	return 0;
}
