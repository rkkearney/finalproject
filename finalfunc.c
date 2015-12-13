#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "gfx4.h"
#include "finalfunc.h"

// Title
int checkZone(int X, int Y)
{
	int option;
	
	if ((X >= 25 && X <= 175) && (Y >= 225 && Y <= 375)) option = 1;		// attack zone
	else if ((X >= 225 && X <= 375) && (Y >= 225 && Y <= 375)) option = 2;	// treasure zone
	else if ((X >= 25 && X <= 175) && (Y >= 525 && Y <= 675)) option = 3;	// rum zone
	else if ((X >= 225 && X <= 375) && (Y >= 525 && Y <= 675)) option = 0;	// quit zone
	else option = 5;														// junk value
	return option;
}

void printMenu()
{
	printBox(25, 225, "Attack Ships", 55, 300); 			// prints Attack button
	printBox(225, 225, "Hunt for Treasure", 240, 300);		// prints Treasure button
	printBox(25, 525, "Drink Rum", 65, 600);				// prints Rum button
	printBox(225, 525, "Quit", 285, 600);					// prints Quit button
}

void printBox(int x, int y, char * title, int xt, int yt)
{
	// prints box
	gfx_color(51, 25, 0);		//brown
	gfx_fill_rectangle(x, y, 150, 150);
	
	// prints label text
	gfx_color(255, 255, 255);	//white
	//gfx_changefont("lucidasanstypewriter-bold-12");
	gfx_text(xt, yt, title);
}

void printBackground(int xsize, int ysize)
{
	// prints sky
	gfx_color(102, 178, 255);	//light blue
	gfx_fill_rectangle(0, 0, xsize, (ysize - 200));
	
	// prints water
	gfx_color(0, 76, 153);		//dark blue
	gfx_fill_rectangle(0, (ysize - 200), xsize, 200);
	
	// prints sun
	gfx_color(255, 255, 0);		//yellow
	gfx_fill_circle((xsize - (xsize/6)), (ysize/6), 50);
}

void printTitle()
{
	gfx_color(0, 0, 0);			//black
	//gfx_changefont("arial-bold-24");
	gfx_text(175, 75, "YoHo!");
	gfx_text(100, 125, "a pirate's life");
	
}

void printTitleScreen(int xsize, int ysize)
{
	// Clear Window
	gfx_clear();

	// Draw Window
	printBackground(xsize, ysize);
	printShip();
	printTitle();
	printMenu();
}

void printShip()
{
		
	// set parameters for base
	XPoint base[12];
	base[0].x = 448;
	base[0].y = 584;
	base[1].x = 496;
	base[1].y = 584;
	base[2].x = 496;
	base[2].y = 600;
	base[3].x = 528;
	base[3].y = 600;
	base[4].x = 528;
	base[4].y = 616;
	base[5].x = 656;
	base[5].y = 616;
	base[6].x = 752;
	base[6].y = 584;
	base[7].x = 752;
	base[7].y = 589;
	base[8].x = 688;
	base[8].y = 616;
	base[9].x = 672;
	base[9].y = 648;
	base[10].x = 480;
	base[10].y = 648;
	base[11].x = 448;
	base[11].y = 600;

	// set parameters for sail
	XPoint sail[4];
	sail[0].x = 510;
	sail[0].y = 456;
	sail[1].x = 480;
	sail[1].y = 472;
	sail[2].x = 432;
	sail[2].y = 576;
	sail[3].x = 510;
	sail[3].y = 576;
	
	XPoint sail2[4];
	sail2[0].x = 520;
	sail2[0].y = 456;
	sail2[1].x = 576;
	sail2[1].y = 472;
	sail2[2].x = 592;
	sail2[2].y = 504;
	sail2[3].x = 520;
	sail2[3].y = 536;
	
	XPoint sail3[4];
	sail3[0].x = 560;
	sail3[0].y = 520;
	sail3[1].x = 592;
	sail3[1].y = 536;
	sail3[2].x = 592;
	sail3[2].y = 600;
	sail3[3].x = 528;
	sail3[3].y = 584;
	
	XPoint sail4[4];
	sail4[0].x = 624;
	sail4[0].y = 464;
	sail4[1].x = 624;
	sail4[1].y = 496;
	sail4[2].x = 592;
	sail4[2].y = 504;
	sail4[3].x = 592;
	sail4[3].y = 472;
	
	XPoint sail5[4];
	sail5[0].x = 640;
	sail5[0].y = 496;
	sail5[1].x = 640;
	sail5[1].y = 528;
	sail5[2].x = 576;
	sail5[2].y = 552;
	sail5[3].x = 576;
	sail5[3].y = 520;
	
	XPoint sail6[3];
	sail6[0].x = 608;
	sail6[0].y = 488;
	sail6[1].x = 752;
	sail6[1].y = 584;
	sail6[2].x = 672;
	sail6[2].y = 584;
		
	XPoint sail7[3];
	sail7[0].x = 624;
	sail7[0].y = 552;
	sail7[1].x = 688;
	sail7[1].y = 592;
	sail7[2].x = 640;
	sail7[2].y = 600;
	// draw
	gfx_color(74, 64, 25);	//wood brown
	gfx_fill_polygon(base, 12);
	gfx_fill_rectangle(512, 440, 5, 160);
	gfx_fill_rectangle(603, 456, 5, 160);
	gfx_color(0, 0, 0);		//black
	gfx_fill_polygon(sail, 4);
	gfx_fill_polygon(sail2, 4);
	gfx_fill_polygon(sail3, 4);
	gfx_fill_polygon(sail4, 4);
	gfx_fill_polygon(sail5, 4);
	gfx_fill_polygon(sail6, 3);
	gfx_fill_polygon(sail7, 3);
}

// Attack
#define XSIZE 800
#define YSIZE 800
#define XMID 400
#define YMID 400

//FUNCTIONS
void attackWave(PirateShip *myShip, AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	int n = 1;
	
	while (n)
	{
	
		int d = 0;			//distance from user game
		//Your attack on the enemy
		d = playerShot(myShip, attack);
		if (d < 0)
		{
			n = 0;
			continue;
		}
		if (d <= 5)
		{
			attack->hit = myShip->cannons;
		}
		else if (d <= 10)
		{
			attack->hit = myShip->cannons - 1;
		}
		else if (d <= 20)
		{
			attack->hit = myShip->cannons - 2;
		}
		else if (d <= 40)
		{
			attack->hit = myShip->cannons - 3;
		}
		else
		{
			attack->hit = myShip->cannons - 4;
		}
		attack->damageToEnemy = attack->hit * 10;
		attack->enemyLife -= attack->damageToEnemy;
		//enemy attack on you
		attack->enemyHit = rand() % (attack->enemyCannons + 1);
		attack->damageToMe = attack->enemyHit * 10;
		myShip->life -= attack->damageToMe;
		//print results of attack
		printf("Life : %d/%d\n", myShip->life, myShip->hp);
		printf("Enemy Life : %d/%d\n", attack->enemyLife, attack->enemyHP);
		if(gfx_event_waiting())
		{
			char c;
			c = gfx_wait();
			if (c == 'q')
			{
				n = 0;
			}
		}
		if (myShip->life >= .25 * myShip->hp && attack->enemyLife >= .25 * attack->enemyHP)
		{
			n = 1;
		}
		else if (myShip->life > attack->enemyLife && myShip->life > 0 || myShip->life >= .25 * myShip->hp && attack->enemyLife < .25 * attack->enemyHP)
		{
			printf("YOU SUCCESSFULLY LOOTED THE ENEMY SHIP\n");
			winScreen();
			gfx_wait();
			n = 0;
		}
		else 
		{
			printf("YOUR SHIP HAS BEEN BOARDED. BETTER LUCK NEXT TIME.\n");
			loseScreen();
			gfx_wait();
			n = 0;
		}
	}
}

void attackShip(PirateShip *myShip, AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	attack->enemyShipLvl = rand() % 3 +1;
	attack ->enemyCannons = 4;
	if (attack->enemyShipLvl == 1)
	{
		strcpy(attack->EnemyFlagColor, "yellow");
		attack->enemyLife = rand() % 41 + 10;
		attack->enemyHP = attack->enemyLife;
	}
	else if (attack->enemyShipLvl == 2)
	{
		strcpy(attack->EnemyFlagColor, "red");
		attack->enemyLife = rand() % 51+ 50;
		attack->enemyHP = attack->enemyLife;
	}
	else	//if enemy ship lvl == 0
	{
		strcpy(attack->EnemyFlagColor, "blue");
		attack->enemyLife = rand() % 51+ 100;
		attack->enemyHP = attack->enemyLife;
	} 
	if (gfx_event_waiting())
	{
		char c;
		c = gfx_wait();
		if (c == 'q')
		{
			return;
		}
	}
	attackWave(myShip, attack);
}
void winScreen()
{
	gfx_clear();
	gfx_color(167, 226, 255);	//sky blue
	gfx_fill_rectangle(0, 0, XSIZE, YSIZE);
	gfx_color(232, 223, 194);
	gfx_fill_rectangle(0, 530, XSIZE, 270);
	gfx_color(246, 255, 245);
	gfx_fill_rectangle(0, 490, XSIZE, 40);
	gfx_color(23, 113, 130);
	gfx_fill_rectangle(0, 390, XSIZE, 100);
	gfx_color(0, 28, 46);
	gfx_fill_rectangle(0, 300, XSIZE, 90);
	barrel();
	chest();
	gfx_color(0, 0, 0);
	gfx_text(120, 80, "Take what you can, give nothing back! It's a Pirate's Life for me. Savvy?");
}

void loseScreen()
{
	gfx_clear();
	gfx_color(0, 0, 0);	//sky blue
	gfx_fill_rectangle(0, 0, XSIZE, YSIZE);
	gfx_color(255, 255, 255);
	gfx_text(120, 80, "You are without doubt the worst pirate I've ever heard of.");
	skull();
}

void chest()
{
	XPoint lid[4];
	XPoint gold[4];
	
	lid[0].x = 360;
	lid[0].y = 400;
	lid[1].x = 640;
	lid[1].y = 400;
	lid[2].x = 680;
	lid[2].y = 480;
	lid[3].x = 320;
	lid[3].y = 480;
	gold[0].x = 320;
	gold[0].y = 480;
	gold[1].x = 360;
	gold[1].y = 440;
	gold[2].x = 640;
	gold[2].y = 440;
	gold[3].x = 680;
	gold[3].y = 480;
	
	
	gfx_color(89, 55, 34);		//chest brown
	gfx_fill_rectangle(320, 480, 360, 160);
	gfx_color(34, 21, 13);		//chest lid brown
	gfx_fill_polygon(lid, 4);
	gfx_line(320, 520, 680, 520);
	gfx_line(320, 560, 680, 560);
	gfx_line(320, 600, 680, 600);
	gfx_color(242, 183, 5);		//gold
	gfx_fill_polygon(gold, 4);	
	
}

void barrel()
{
	XPoint barr[7];
	barr[0].x = 200;
	barr[0].y = 320;
	barr[1].x = 320;
	barr[1].y = 320;
	barr[2].x = 360;
	barr[2].y = 400;
	barr[3].x = 320;
	barr[3].y = 600;
	barr[4].x = 200;
	barr[4].y = 600;
	barr[5].x = 160;
	barr[5].y = 520;
	barr[6].x = 160;
	barr[6].y = 400;
	
	gfx_color(144, 89, 75);
	gfx_fill_polygon(barr, 7);
	gfx_color(55, 34, 21);
	gfx_fill_rectangle(160, 400, 200, 40);
	gfx_fill_rectangle(160, 480, 200, 40);
	
}

void skull()
{
	gfx_color(255, 255, 255);
	gfx_fill_circle(400, 360, 120);
	gfx_fill_rectangle(320, 400, 160, 80);
	gfx_fill_rectangle(360, 480, 80, 40);
	
	XPoint bone1[4];
	bone1[0].x = 200;
	bone1[0].y = 480;
	bone1[1].x = 200;
	bone1[1].y = 500;
	bone1[2].x = 600;
	bone1[2].y = 660;
	bone1[3].x = 600;
	bone1[3].y = 640;
	
	XPoint bone2[4];
	bone2[0].x = 200;
	bone2[0].y = 640;
	bone2[1].x = 200;
	bone2[1].y = 660;
	bone2[2].x = 600;
	bone2[2].y = 500;
	bone2[3].x = 600;
	bone2[3].y = 480;
	
	gfx_fill_polygon(bone1, 4);
	gfx_fill_polygon(bone2, 4);
	gfx_fill_circle(200, 480, 15);
	gfx_fill_circle(200, 500, 15);
	gfx_fill_circle(200, 640, 15);
	gfx_fill_circle(200, 660, 15);
	gfx_fill_circle(600, 480, 15);
	gfx_fill_circle(600, 500, 15);
	gfx_fill_circle(600, 640, 15);
	gfx_fill_circle(600, 660, 15);
	
	gfx_color(0, 0, 0);
	gfx_fill_circle(360, 400, 25);
	gfx_fill_circle(440, 400, 25);
	gfx_line(370, 520, 370, 500);
	gfx_line(380, 520, 380, 500);
	gfx_line(390, 520, 390, 500);
	gfx_line(400, 520, 400, 500);
	gfx_line(410, 520, 410, 500);
	gfx_line(420, 520, 420, 500);
	gfx_line(430, 520, 430, 500);
	
	XPoint nose[4];
	nose[0].x = 400;
	nose[0].y = 420;
	nose[1].x = 420;
	nose[1].y = 465;
	nose[2].x = 380;
	nose[2].y = 465;
	
	gfx_fill_polygon(nose, 3);
	
	
	
}

int playerShot(PirateShip *myShip, AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	int r = 30;					//radius
	int x = 50, y = YMID;		//starting coordinates
	int d = 0;		//distance from center target
	double dx = 1.;		//change in coordinates
	char c;
	double deltat = 10000;
	drawEnemy(attack);
	attack->enemyShipLvl == rand() % 3 ;
	//change crosshair target speed
	if(attack->enemyShipLvl == 1)		//level 1 enemy
	{
		deltat = 7000;
	}
	else if (attack->enemyShipLvl == 2)		//level 2 enemy
	{
		deltat = 4000;
	}
	else		//level 3 enemy
	{
		deltat = 3000;
	}
	while (1)
	{
		gfx_clear();
		statsBar(myShip, attack);
		//gfx_clear_color(213, 47, 94);
		drawEnemy(attack);
		statsBar(myShip, attack);
		//draw white target circle
		gfx_color(255, 255, 255);
		gfx_circle(XMID, YMID, r);
		//draw moving green crosshair circle
		gfx_color(82, 199, 104);
		gfx_point(x, y);
		gfx_circle(x, y, r);
		gfx_flush();
		usleep(deltat);
		//if crosshairs hits edge of screen reverse direction
		if (x >= XSIZE - r || x <= r)
		{
			dx = dx * -1;
		}
		//change center of crosshairs
		x += dx;
		
		if (gfx_event_waiting())
		{
			c = gfx_wait();
			switch (c)
			{
				case (1):
				{
					d = abs(x-XMID);
					return d;
					break;
				}
				case('q'):
				{
					return -5;
				}
			}
		}
	}	
}
void drawEnemy(AttackStats *attack)
{
	XPoint base[4];
	XPoint sail[3];
	//boat base drawing
	base[0].x = XMID - 70;
	base[0].y = YMID - 20;
	base[1].x = XMID + 70;
	base[1].y = YMID - 20;
	base[2].x = XMID + 40;
	base[2].y = YMID + 20;
	base[3].x = XMID - 40;
	base[3].y = YMID + 20;
	//boat sail drawing
	sail[0].x = XMID;
	sail[0].y = YMID - 100;
	sail[1].x = XMID + 70;
	sail[1].y = YMID - 25;
	sail[2].x = XMID - 40;
	sail[2].y = YMID - 25;
	//color and fill functions
	gfx_color(17, 0, 127);							//ocean blue
	gfx_fill_rectangle(0, YSIZE/2, XSIZE, YSIZE/2);
	gfx_color(74, 64, 25);							//wood brown
	gfx_fill_polygon(base, 4);
	if(!strcmp(attack->EnemyFlagColor, "yellow"))
	{
		gfx_color(255, 255, 102);	//yellow flag
	}
	else if(!strcmp(attack->EnemyFlagColor, "red"))
	{
		gfx_color(204, 0, 0);	//red flag
	}
	else		//blue flag
	{
		gfx_color(32, 106, 255);
	}
	gfx_fill_polygon(sail, 3);
}
void statsBar(PirateShip *myShip, AttackStats *attack)
{
	gfx_color(255, 255, 255);
	gfx_text(25, 25, "Your Life:");
	gfx_text(20, 50, "Enemy Life:");
	
	XPoint myHP[4];
	myHP[0].x = 100;
	myHP[0].y = 20;
	myHP[1].x = myShip->hp*5 + 100;//XSIZE - 100;
	myHP[1].y = 20; 
	myHP[2].x = myShip->hp*5 + 100; //XSIZE - 100;
	myHP[2].y = 30;
	myHP[3].x = 100;
	myHP[3].y = 30;
	XPoint enemyHP[4];
	enemyHP[0].x = 100;
	enemyHP[0].y = 45;
	enemyHP[1].x = attack->enemyHP*5 + 100; //XSIZE - 100;
	enemyHP[1].y = 45;
	enemyHP[2].x = attack->enemyHP*5 + 100;  //XSIZE - 100;
	enemyHP[2].y = 55;
	enemyHP[3].x = 100;
	enemyHP[3].y = 55;
	
	XPoint myLife[4];
	myLife[0].x = 100;
	myLife[0].y = 20;
	myLife[1].x = myShip->life*5 + 100; //(XSIZE - 100) * (myShip->life / myShip->hp) + 50;
	myLife[1].y = 20;
	myLife[2].x = myShip->life*5 + 100; //(XSIZE - 100) * (myShip->life / myShip->hp) + 50;
	myLife[2].y = 30;
	myLife[3].x = 100;
	myLife[3].y = 30;
	XPoint enemyLife[4];
	enemyLife[0].x = 100;
	enemyLife[0].y = 45;
	enemyLife[1].x = attack->enemyLife*5 + 100;//(XSIZE - 100) * (attack->enemyLife / attack->enemyHP) + 50;
	enemyLife[1].y = 45;
	enemyLife[2].x = attack->enemyLife*5 + 100;//(XSIZE - 100) * (attack->enemyLife / attack->enemyHP) + 50;
	enemyLife[2].y = 55;
	enemyLife[3].x = 100;
	enemyLife[3].y = 55;
	
	gfx_color(43, 245, 25);	//blue
	gfx_fill_polygon(myHP, 4);
	gfx_fill_polygon(enemyHP, 4);
	gfx_color(255, 255, 255);
	gfx_fill_polygon(myLife, 4);
	gfx_fill_polygon(enemyLife, 4);	
}

void attackShips()
{
	PirateShip BlackPearl = {110, 110, 2, 4, "Black"};
	AttackStats attack;
	attackShip(&BlackPearl, &attack);
}


// Treasure
void pickColor(int c)
{
	switch (c)
	{
		case 0:
			gfx_color(102, 178, 255);	//light blue
			break;
		case 1:
			gfx_color(0, 102, 204);		//medium
			break;
		case 2:
			gfx_color(0, 51, 102);		//dark
			break;
		case 3:
			gfx_color(255, 255, 255);	//white
			break;
		case 4:
			gfx_color(0, 0, 0);			//black
			break;
		case 5:
			gfx_color(255, 255, 0);		//yellow
			break;
	}
}

// Functions for Set Up
	
void initializeBoard(struct Blocks board[], int length, int x0, int y0, int w)
{
	initializeWidth(board, length, w);	// initializes all width
	initializeX(board, length, x0);		// sets all x positions
	initializeY(board, length, y0);		// sets all y positions
	initializeTreasure(board, length);	// initializes all treasure to 0
	randTreasure(board, length);		// picks random places for treasure
	initializeColor(board, length);		// sets color for each cell
	initializePosition(board, length);	// sets current position
}

void initializeX(struct Blocks board[], int length, int x0)
{
	int i, x = x0, d = board[0].width;
	
	for (i = 0; i < length; i++)
	{
		if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100 || i == 110 || i == 120 || i == 130 || i == 140)		// checks if 1st of row
		{
			x = x0;		// sets 1st of row to intial x-value
		}
		board[i].x = x; // sets x-value of board position to x
		x += d;			// increments x by width of box
	}
}

void initializeY(struct Blocks board[], int length, int y0)
{
	int i, y = y0, d = board[0].width;
	for (i = 0; i < length; i++)
	{	
		if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100 || i == 110 || i == 120 || i == 130 || i == 140)
		{
			y += d;		// increments 1st of row to next y-value
		}
		board[i].y = y; // sets y-value of board position to y
	}
}

void initializeTreasure(struct Blocks board[], int length)
{
	int i;
	for (i = 0; i < length; i++)
	{
		board[i].treasure = 0;		// sets all treasure values to 0 before randTreasure
	}
}

void randTreasure(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	int i, x; 

	for (i = 0; i < 10; i++)
	{
		x = rand() % 150;					// get random place for treasure
		if (x == 74) x + (rand() % 10);		// makes sure initial point is not treasure
		board[x].treasure = 1;				// set position as treasure
	}
}

void initializeWidth(struct Blocks board[], int length, int width)
{
	int i;
	for (i = 0; i < length; i++)
	{
		board[i].width = width;		// intialize every width to 40
	}
}

void initializeColor(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (i == 74) board[i].color = rand() % 3;	// sets random color value between 0-2 for start point
		else board[i].color = 3;					// sets every other value to 3 (white)
	}
}

void initializePosition(struct Blocks board[], int length)
{
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (i == 74) board[i].current = 1;			// sets initialposition value to true
		else if (i != 74) board[i].current = 0;		// sets all others to false
	}
}

void printBoard(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (board[i].treasure) 						// if treasure
		{
			board[i].color = rand() % 3;			// assigns random color value to board[i].treasure
			pickColor(board[i].color); 				// set drawing color to stored (light/medium/dark)
			gfx_fill_rectangle(board[i].x, board[i].y, board[i].width, board[i].width); // draw block
			printCoin(board[i].x, board[i].y);		// prints coin on top of block
		}
		else if (!board[i].treasure)				// if not treasure
		{
			pickColor(board[i].color); 				// set drawing color to stored (white)
			gfx_fill_rectangle(board[i].x, board[i].y, board[i].width, board[i].width); // draw block
		}
		if (board[i].current) 						// if current position
		{
			printX(board[i].x, board[i].y);			// prints X on block
		}
	}
}

void printCoin(int x, int y)
{
	x = x + ((x + 40) - x)/2;	// calculates center x-value for circle
	y = y + ((y + 40) - y)/2;	// calculates center y-value for circle
	
	pickColor(5); 				// set drawing color to yellow
	gfx_fill_circle(x, y, 10);	// draw circle
}

void printX(int x, int y)
{
	int x1, y1, x2, y2;
	pickColor(4); 					// set drawing color to black
	
	x1 = x + ((x + 40) - x)/3;		// calculates end points for line
	y1 = y + ((y + 40) - y)/3;
	x2 = x + 2*((x + 40) - x)/3;
	y2 = y + 2*((y + 40) - y)/3;
	gfx_line(x1, y1, x2, y2);		// prints first line
	
	y = y + 40; 					// adjust y for second line
	x1 = x + ((x + 40) - x)/3;		// calculates end points for line
	y1 = y + ((y - 40) - y)/3;
	x2 = x + 2*((x + 40) - x)/3;
	y2 = y + 2*((y - 40) - y)/3;
	gfx_line(x1, y1, x2, y2);		// prints second line
}

void printUpcoming(int x)
{
	pickColor(x); 							// sets color for upcoming
	gfx_fill_rectangle(350, 115, 20, 20);	// prints upcoming color in upper corner
}

void printText()
{
	pickColor(3); 	// set drawing color to white
	
	// print text
	gfx_text(43, 15, "Arggg, Matey! Time to find the treasure!");
	gfx_text(18, 35, "Use arrow keys to move up, down, left, and right.");
	gfx_text(28, 50, "Match three or more blocks of the same color.");
	gfx_text(55, 65, "Collect as much treasure as possible.");
	gfx_text(105, 80, "But don't get trapped!");
	gfx_text(140, 120, "Good Luck!");
	gfx_text(335, 110, "Up Next: ");
	gfx_text(105, 770, "Press 'q' anytime to exit.");
	
	//gfx_changefont("arial-bold-24");		// change font for title
	pickColor(4);										// change drawing color to black
	gfx_text(580, 320, "HUNT");
	gfx_text(585, 360, "for");
	gfx_text(550, 400, "TREASURE");
}

int newColor()
{
	time_t t;
	srand(time(&t));
	int c;
	
	c = rand() % 3;		// gets random value for color between 0 and 2 
	
	return c;
}

// Functions for Playing
void printBlock(int x, int y, int width, int color)
{
	pickColor(color); 							// set drawing color to next color
	gfx_fill_rectangle(x, y, width, width);		// draw block
}

// Check and Change if Match
int checkFour(struct Blocks board[], int length, int currentPosition)
	/*	checks if four surrounding are a match and adjusts board accordingly
	 	returns 1 if match is made
	 	returns 0 if no match 		*/
{
	if (board[currentPosition].color == board[currentPosition - 1].color && board[currentPosition].color == board[currentPosition - 10].color && board[currentPosition].color == board[currentPosition + 1].color && board[currentPosition].color == board[currentPosition + 10].color)
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else return 0;
}

int checkThree(struct Blocks board[], int length, int currentPosition)
	/*	checks if three surrounding are a match and adjusts board accordingly
	 	returns 1 if match is made
	 	returns 0 if no match 		*/
{	
	if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition + 1].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else return 0;
}

int checkTwo(struct Blocks board[], int length, int currentPosition)
	/*	checks if two surrounding are a match and adjusts board accordingly
	 	returns 1 if match is made
	 	returns 0 if no match 		*/
{
	if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition - 10].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition + 1].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition + 1].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition + 10].color))
	{
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 10].color) && (board[currentPosition].color == board[currentPosition + 20].color))
	{
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		board[currentPosition + 20].color = 3;
		printBlock(board[currentPosition + 20].x, board[currentPosition + 20].y, board[currentPosition + 20].width, board[currentPosition + 20].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition - 20].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition - 20].color = 3;
		printBlock(board[currentPosition - 20].x, board[currentPosition - 20].y, board[currentPosition - 20].width, board[currentPosition - 20].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition + 2].color))
	{
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 2].color = 3;
		printBlock(board[currentPosition + 2].x, board[currentPosition + 2].y, board[currentPosition + 2].width, board[currentPosition + 2].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition - 2].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 2].color = 3;
		printBlock(board[currentPosition - 2].x, board[currentPosition - 2].y, board[currentPosition - 2].width, board[currentPosition - 2].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition - 11].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition - 11].color = 3;
		printBlock(board[currentPosition - 11].x, board[currentPosition - 11].y, board[currentPosition - 11].width, board[currentPosition - 11].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 1].color) && (board[currentPosition].color == board[currentPosition + 9].color))
	{
		board[currentPosition - 1].color = 3;
		printBlock(board[currentPosition - 1].x, board[currentPosition - 1].y, board[currentPosition - 1].width, board[currentPosition - 1].color);
		board[currentPosition + 9].color = 3;
		printBlock(board[currentPosition + 9].x, board[currentPosition + 9].y, board[currentPosition + 9].width, board[currentPosition + 9].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition + 11].color))
	{
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition + 11].color = 3;
		printBlock(board[currentPosition + 11].x, board[currentPosition + 11].y, board[currentPosition + 11].width, board[currentPosition + 11].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 1].color) && (board[currentPosition].color == board[currentPosition - 9].color))
	{
		board[currentPosition + 1].color = 3;
		printBlock(board[currentPosition + 1].x, board[currentPosition + 1].y, board[currentPosition + 1].width, board[currentPosition + 1].color);
		board[currentPosition - 9].color = 3;
		printBlock(board[currentPosition - 9].x, board[currentPosition - 9].y, board[currentPosition - 9].width, board[currentPosition - 9].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition - 11].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition - 11].color = 3;
		printBlock(board[currentPosition - 11].x, board[currentPosition - 11].y, board[currentPosition - 11].width, board[currentPosition - 11].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition - 10].color) && (board[currentPosition].color == board[currentPosition - 9].color))
	{
		board[currentPosition - 10].color = 3;
		printBlock(board[currentPosition - 10].x, board[currentPosition - 10].y, board[currentPosition - 10].width, board[currentPosition - 10].color);
		board[currentPosition - 9].color = 3;
		printBlock(board[currentPosition - 9].x, board[currentPosition - 9].y, board[currentPosition - 9].width, board[currentPosition - 9].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 10].color) && (board[currentPosition].color == board[currentPosition + 11].color))
	{
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		board[currentPosition + 11].color = 3;
		printBlock(board[currentPosition + 11].x, board[currentPosition + 11].y, board[currentPosition + 11].width, board[currentPosition + 11].color);
		return 1;
	}
	else if ((board[currentPosition].color == board[currentPosition + 10].color) && (board[currentPosition].color == board[currentPosition + 9].color))
	{
		board[currentPosition + 10].color = 3;
		printBlock(board[currentPosition + 10].x, board[currentPosition + 10].y, board[currentPosition + 10].width, board[currentPosition + 10].color);
		board[currentPosition + 9].color = 3;
		printBlock(board[currentPosition + 9].x, board[currentPosition + 9].y, board[currentPosition + 9].width, board[currentPosition + 9].color);
		return 1;
	}
	else return 0;
}

int move(struct Blocks board[], int length, int currentPosition, int nextColor, char c)
{
	board[currentPosition].current = 0;	// sets current value to 0 for currentPosition
	printBlock(board[currentPosition].x, board[currentPosition].y, board[currentPosition].width, board[currentPosition].color);
	switch (c)							// to change currentPosition
	{
		case 'u':						// move up
			currentPosition -= 10;		// changes position to one above
			break;
		case 'd':						// move down
			currentPosition += 10;		// changes position to one below
			break;
		case 'l':						// move left
			currentPosition -= 1;		// changes position to one left
			break;
		case 'r':						// move right
			currentPosition += 1;		// changes position to one right
			break;
	}
	board[currentPosition].current = 1;			// sets current value to 1 for new currentPosition
	board[currentPosition].color = nextColor;	// sets value for color to the value of nextColor
	printBlock(board[currentPosition].x, board[currentPosition].y, board[currentPosition].width, board[currentPosition].color); // draws block
	printX(board[currentPosition].x, board[currentPosition].y);		// draws X on block
	
	return currentPosition;
}

int isTrapped(struct Blocks board[], int length, int currentPosition)
	/* 	checks if currentPosition is completely surrounded by other colors or boundary
		if trapped, returns 1
		if not trapped, returns 0 	*/
{
	if (board[currentPosition - 1].color != 3 && board[currentPosition - 10].color != 3 && board[currentPosition + 1].color != 3 && board[currentPosition + 10].color != 3)
	{
		return 1;
	}
	// Top
	else if ((currentPosition >= 1 && currentPosition <= 9) && (board[currentPosition - 1].color != 3 && board[currentPosition - 10].color != 3 && board[currentPosition + 1].color != 3 && board[currentPosition + 10].color != 3))
	{
		return 1;
	}
	// Bottom
	else if ((currentPosition >= 140 && currentPosition <= 149) && (board[currentPosition - 1].color != 3 && board[currentPosition - 10].color != 3 && board[currentPosition + 1].color != 3))
	{
		return 1;
	}
	// Right Side
	else if ((currentPosition == 9 || currentPosition == 19 || currentPosition == 29 || currentPosition == 39 || currentPosition == 49 || currentPosition == 59 || currentPosition == 69 || currentPosition == 79 || currentPosition == 89 || currentPosition == 99 || currentPosition == 109 || currentPosition == 119 || currentPosition == 129 || currentPosition == 139 || currentPosition == 149) && (board[currentPosition - 1].color != 3 && board[currentPosition - 10].color != 3 && board[currentPosition + 10].color != 3))
	{
		return 1;
	}
	// Left Side
	else if ((currentPosition == 0 || currentPosition == 10 || currentPosition == 20 || currentPosition == 30 || currentPosition == 40 || currentPosition == 50 || currentPosition == 60 || currentPosition == 70 || currentPosition == 80 || currentPosition == 90 || currentPosition == 100 || currentPosition == 110 || currentPosition == 120 || currentPosition == 130 || currentPosition == 140) && (board[currentPosition - 10].color != 3 && board[currentPosition + 1].color != 3 && board[currentPosition + 10].color != 3))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int treasureHunt()
	/* runs treasure mini game */
{
	char c;
	int x0 = 0, y0 = 150, w = 40, length = 150, currentPosition = 74;
	int xsize = 800, ysize = 800;
	int nextColor, currentColor;
	int trapped = 0;
	struct Blocks board[length];
	
	printBackground(xsize, ysize);				// prints background
	printShip();								// prints ship on background
	pickColor(4); 								// sets color to black
	gfx_fill_rectangle(0, 0, 400, 150);			// prints box around text
	gfx_line(400, 0, 400, 750);					// prints side border line
	gfx_line(0, 750, 400, 750);					// prints bottom border line
	printText();								// prints text instructions
	nextColor = newColor();						// sets initial nextColor
	printUpcoming(nextColor);					// prints initial nextColor
	initializeBoard(board, length, x0, y0, w);	// intializes board
	printBoard(board, length);					// prints board (block by block)
	
	while (1) {
		c = gfx_wait();
		switch (c) {
			case 'R': // Up
				if (currentPosition >= 1 && currentPosition <= 9)
					// checks if out of board
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition - 10].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'u');	// moves block up
					if (checkFour(board, length, currentPosition));							// check if match is made
					else if (checkThree(board, length, currentPosition));					// check if match is made
					else if (checkTwo(board, length, currentPosition));						// check if match is made
					nextColor = newColor();													// resets nextColor
					printUpcoming(nextColor);												// prints nextColor
				}
				trapped = isTrapped(board, length, currentPosition);						// checks if trapped
				break;
			case 'S': // Right
				if (currentPosition == 9 || currentPosition == 19 || currentPosition == 29 || currentPosition == 39 || currentPosition == 49 || currentPosition == 59 || currentPosition == 69 || currentPosition == 79 || currentPosition == 89 || currentPosition == 99 || currentPosition == 109 || currentPosition == 119 || currentPosition == 129 || currentPosition == 139 || currentPosition == 149)
					// checks if out of board
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition + 1].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'r');	// moves block right
					if (checkFour(board, length, currentPosition));							// check if match is made
					else if (checkThree(board, length, currentPosition));					// check if match is made
					else if (checkTwo(board, length, currentPosition));						// check if match is made
					nextColor = newColor();													// resets nextColor
					printUpcoming(nextColor);												// prints nextColor
				}
				trapped = isTrapped(board, length, currentPosition);						// checks if trapped
				break;
			case 'T': // Down
				if (currentPosition >= 140 && currentPosition <= 149)
					// checks if out of board
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition + 10].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'd');	// moves block down
					if (checkFour(board, length, currentPosition));							// check if match is made
					else if (checkThree(board, length, currentPosition));					// check if match is made
					else if (checkTwo(board, length, currentPosition));						// check if match is made
					nextColor = newColor();													// resets nextColor
					printUpcoming(nextColor);												// prints nextColor
				}
				trapped = isTrapped(board, length, currentPosition);						// checks if trapped
				break;
			case 'Q': // Left
				if (currentPosition == 0 || currentPosition == 10 || currentPosition == 20 || currentPosition == 30 || currentPosition == 40 || currentPosition == 50 || currentPosition == 60 || currentPosition == 70 || currentPosition == 80 || currentPosition == 90 || currentPosition == 100 || currentPosition == 110 || currentPosition == 120 || currentPosition == 130 || currentPosition == 140)
					// checks if out of board
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition - 1].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'l');	// moves block left
					if (checkFour(board, length, currentPosition));							// check if match is made
					else if (checkThree(board, length, currentPosition));					// check if match is made
					else if (checkTwo(board, length, currentPosition));						// check if match is made
					nextColor = newColor();													// resets nextColor
					printUpcoming(nextColor);												// prints nextColor
				}
				trapped = isTrapped(board, length, currentPosition);						// checks if trapped
				break;
			case 'q': // quits
				return 0;
		}
		if (trapped) break;		// if trapped, ends function
	}
	return 0;
}

// Rum
void drawBlackHair()
{
	XPoint hair[10];
	gfx_color(0, 0, 0);		//black
	
	// set paramaters
	hair[0].x = 450;
	hair[0].y = 280;
	hair[1].x = 410;
	hair[1].y = 400;
	hair[2].x = 430;
	hair[2].y = 440;
	hair[3].x = 445;
	hair[3].y = 420;
	hair[4].x = 400;
	hair[4].y = 600;
	hair[5].x = 460;
	hair[5].y = 560;
	hair[6].x = 470;
	hair[6].y = 520;
	hair[7].x = 425;
	hair[7].y = 800;
	hair[8].x = 570;
	hair[8].y = 800;
	hair[9].x = 560;
	hair[9].y = 400;
	
	gfx_fill_polygon(hair, 10);
}

void drawFace()
{
	XPoint face[13];
	gfx_color(229, 165, 108);	//skin tone
	
	// set paramaters
	face[0].x = 450;
	face[0].y = 280;
	face[1].x = 460;
	face[1].y = 345;
	face[2].x = 445;
	face[2].y = 385;
	face[3].x = 455;
	face[3].y = 400;
	face[4].x = 450;
	face[4].y = 440;
	face[5].x = 480;
	face[5].y = 455;
	face[6].x = 480;
	face[6].y = 465;
	face[7].x = 465;
	face[7].y = 480;
	face[8].x = 490;
	face[8].y = 520;
	face[9].x = 560;
	face[9].y = 540;
	face[10].x = 560;
	face[10].y = 680;
	face[11].x = 660;
	face[11].y = 640;
	face[12].x = 690;
	face[12].y = 240;
	
	gfx_fill_polygon(face, 13);
}

void drawLips()
{
	XPoint lips[9];
	gfx_color(255, 204, 204);	//peach
	
	// set paramaters
	lips[0].x = 470;
	lips[0].y = 450;
	lips[1].x = 480;
	lips[1].y = 455;
	lips[2].x = 480;
	lips[2].y = 465;
	lips[3].x = 465;
	lips[3].y = 480;
	lips[4].x = 520;
	lips[4].y = 480;
	lips[5].x = 555;
	lips[5].y = 477;
	lips[6].x = 550;
	lips[6].y = 460;
	lips[7].x = 520;
	lips[7].y = 435;
	lips[8].x = 450;
	lips[8].y = 440;
	
	gfx_fill_polygon(lips, 9);
}

void drawMushtache()
{
	XPoint mushtache[8];
	gfx_color(38, 20, 9);	//dark brown
	
	// set paramaters
	mushtache[0].x = 453;
	mushtache[0].y = 410;
	mushtache[1].x = 450;
	mushtache[1].y = 440;
	mushtache[2].x = 470;
	mushtache[2].y = 450;
	mushtache[3].x = 480;
	mushtache[3].y = 440;
	mushtache[4].x = 500;
	mushtache[4].y = 440;
	mushtache[5].x = 580;
	mushtache[5].y = 480;
	mushtache[6].x = 560;
	mushtache[6].y = 450;
	mushtache[7].x = 510;
	mushtache[7].y = 420;
	
	gfx_fill_polygon(mushtache, 8);
}

void drawTeeth()
{
	XPoint teeth[4];
	gfx_color(255, 255, 255);	//white
	
	// set paramaters
	teeth[0].x = 480;
	teeth[0].y = 455;
	teeth[1].x = 480;
	teeth[1].y = 465;
	teeth[2].x = 550;
	teeth[2].y = 475;
	teeth[3].x = 510;
	teeth[3].y = 450;

	gfx_fill_polygon(teeth, 4);
}

void drawBeard()
{
	XPoint beard[12];
	gfx_color(38, 20, 9);	//dark brown
	
	// set paramaters
	beard[0].x = 490;
	beard[0].y = 520;
	beard[1].x = 485;
	beard[1].y = 550;
	beard[2].x = 520;
	beard[2].y = 570;
	beard[3].x = 540;
	beard[3].y = 560;
	beard[4].x = 560;
	beard[4].y = 540;
	beard[5].x = 660;
	beard[5].y = 495;
	beard[6].x = 660;
	beard[6].y = 480;
	beard[7].x = 560;
	beard[7].y = 520;
	beard[8].x = 520;
	beard[8].y = 520;
	beard[9].x = 510;
	beard[9].y = 490;
	beard[10].x = 495;
	beard[10].y = 490;
	beard[11].x = 505;
	beard[11].y = 520;
	
	gfx_fill_polygon(beard, 12);
}

void drawEyebrows() 
{
	// Left
	XPoint left[4];
	gfx_color(38, 20, 9);	//dark brown
	
	// set paramaters
	left[0].x = 450;
	left[0].y = 280;
	left[1].x = 480;
	left[1].y = 300;
	left[2].x = 470;
	left[2].y = 310;
	left[3].x = 450;
	left[3].y = 290;

	gfx_fill_polygon(left, 4);
	
	// Right
	XPoint right[8];
	
	// set paramaters
	right[0].x = 520;
	right[0].y = 300;
	right[1].x = 530;
	right[1].y = 310;
	right[2].x = 570;
	right[2].y = 280;
	right[3].x = 610;
	right[3].y = 280;
	right[4].x = 615;
	right[4].y = 290;
	right[5].x = 620;
	right[5].y = 290;
	right[6].x = 615;
	right[6].y = 275;
	right[7].x = 560;
	right[7].y = 270;
	
	gfx_fill_polygon(right, 8);
}

void drawNostril()
{
	XPoint nostril[3];
	gfx_color(0, 0, 0);	//black
	
	// set paramaters
	nostril[0].x = 480;
	nostril[0].y = 400;
	nostril[1].x = 500;
	nostril[1].y = 400;
	nostril[2].x = 505;
	nostril[2].y = 410;

	gfx_fill_polygon(nostril, 3);
}

void drawEye()
{
	// White
	XPoint white[5];
	gfx_color(255, 255, 255);	//white
	
	// set paramaters
	white[0].x = 520;
	white[0].y = 340;
	white[1].x = 545;
	white[1].y = 350;
	white[2].x = 580;
	white[2].y = 320; 
	white[3].x = 570;
	white[3].y = 305;
	white[4].x = 540;
	white[4].y = 310;

	gfx_fill_polygon(white, 5);
	
	// Pupil
	XPoint pupil[4];
	gfx_color(0, 0, 0);		//black
	
	// set paramaters
	pupil[0].x = 520;
	pupil[0].y = 340;
	pupil[1].x = 545;
	pupil[1].y = 350;
	pupil[2].x = 550;
	pupil[2].y = 305;
	pupil[3].x = 540;
	pupil[3].y = 310;
	
	gfx_fill_polygon(pupil, 4);
}

void drawBrownHair() 
{
	XPoint hair[14];
	gfx_color(15, 8, 3);	//brown
	
	// set paramaters
	hair[0].x = 680;
	hair[0].y = 240;
	hair[1].x = 600;
	hair[1].y = 560;
	hair[2].x = 640;
	hair[2].y = 520;
	hair[3].x = 660;
	hair[3].y = 440;
	hair[4].x = 660;
	hair[4].y = 760;
	hair[5].x = 690;
	hair[5].y = 720;
	hair[6].x = 720;
	hair[6].y = 600;
	hair[7].x = 720;
	hair[7].y = 720;
	hair[8].x = 680;
	hair[8].y = 800;
	hair[9].x = 720;
	hair[9].y = 800;
	hair[10].x = 760;
	hair[10].y = 700;
	hair[11].x = 760;
	hair[11].y = 800;
	hair[12].x = 800;
	hair[12].y = 800;
	hair[13].x = 800;
	hair[13].y = 240;
	
	gfx_fill_polygon(hair, 14);
}

void drawHat() //6
{
	XPoint hat[6];
	gfx_color(123, 26, 21);		//dark red
	
	// set paramaters
	hat[0].x = 440;
	hat[0].y = 282;
	hat[1].x = 460;
	hat[1].y = 130;
	hat[2].x = 540;
	hat[2].y = 40;
	hat[3].x = 640;
	hat[3].y = 40;
	hat[4].x = 800;
	hat[4].y = 90;
	hat[5].x = 800;
	hat[5].y = 240;
	
	gfx_fill_polygon(hat, 6);
}

void printRum()
{
	gfx_color(0, 0, 0); 	//black
	//gfx_changefont("arial-bold-24");
	gfx_text(120, 240, "WHY IS");
	gfx_text(120, 320, "THE RUM");
	gfx_text(120, 400, "ALWAYS");
	gfx_text(120, 480, "GONE?");
	
	//gfx_changefont("arial-bold-18");
	gfx_text(150, 540, "- Jack Sparrow");
	
	//gfx_changefont("arial-bold-12");
	gfx_text(120, 760, "To exit, press 'q'.");
}


void drinkRum()
	/* runs Rum screen */
{
	char c;
	int xsize = 800, ysize =  800;
	
	while (1)
	{
		gfx_color(102, 152, 182);				// sets drawing color to shade of blue
		gfx_fill_rectangle(0, 0, xsize, ysize);	// draws background
		
		drawBlackHair();
		drawFace();
		gfx_color(0, 0, 0);						// set drawing color to black
		gfx_line(445, 385, 480, 300); 			// nose line
		drawLips();
		drawMushtache();
		drawTeeth();
		drawBeard();
		drawEyebrows();
		drawNostril();
		drawEye();
		drawBrownHair();
		drawHat();
		printRum();
		
		c = gfx_wait();
		if (c == 'q') break;		// quits if 'q' pressed
	}
}
