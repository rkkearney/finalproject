#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "gfx4.h"
#include "titlescreenfunc.h"

// Title
int checkZone(int X, int Y)
{
	int option;
	
	if ((X >= 25 && X <= 175) && (Y >= 225 && Y <= 375)) option = 1;
	else if ((X >= 225 && X <= 375) && (Y >= 225 && Y <= 375)) option = 2;
	//else if ((X >= 125 && X <= 275) && (Y >= 400 && Y <= 500)) option = 3;
	else if ((X >= 25 && X <= 175) && (Y >= 525 && Y <= 675)) option = 3;
	else if ((X >= 225 && X <= 375) && (Y >= 525 && Y <= 675)) option = 0;
	else option = 5;
	return option;
}

void printMenu()
{
	printBox(25, 225, "Attack Ships", 55, 300);
	printBox(225, 225, "Hunt for Treasure", 240, 300);
	// printBox(125, 400, "Drink Rum", 165, 450);
	printBox(25, 525, "Drink Rum", 65, 600);
	printBox(225, 525, "Quit", 285, 600);
}

void printBox(int x, int y, char * title, int xt, int yt)
{
	// box
	gfx_color(51, 25, 0); //brown
	gfx_fill_rectangle(x, y, 150, 150);
	
	// text
	gfx_color(255, 255, 255); //white
	gfx_changefont("lucidasanstypewriter-bold-12");
	gfx_text(xt, yt, title);
}

void printBackground(int xsize, int ysize)
{
	// sky
	gfx_color(102, 178, 255); //light blue
	gfx_fill_rectangle(0, 0, xsize, (ysize - 200));
	
	// water
	gfx_color(0, 76, 153); //dark blue
	gfx_fill_rectangle(0, (ysize - 200), xsize, 200);
	
	// sun
	gfx_color(255, 255, 0); //yellow
	gfx_fill_circle((xsize - (xsize/6)), (ysize/6), 50);
}

void printTitle()
{
	gfx_color(0, 0, 0);
	gfx_changefont("lucidasanstypewriter-bold-24");
	gfx_text(175, 75, "YoHo!");
	gfx_text(100, 125, "a pirate's life");
	
}

void playGame(int c)
{
	// gfx_open(xsize, ysize, "Mini Game");
	gfx_clear();
	
	if (c == 1) ; // playPirate();
	else if (c == 2) treasureHunt();
}

void printTitleScreen(int xsize, int ysize)
{
	// Set Up Window
	gfx_clear();

	// Draw Window
	printBackground(xsize, ysize);
	printShip();
	printTitle();
	printMenu();
}

void printShip()
{
	int X = 600, Y = 600;
	
	XPoint base[4];
	XPoint sail[3];
	base[0].x = X - 70;
	base[0].y = Y - 20;
	base[1].x = X + 70;
	base[1].y = Y - 20;
	base[2].x = X + 40;
	base[2].y = Y + 20;
	base[3].x = X - 40;
	base[3].y = Y + 20;
	
	sail[0].x = X;
	sail[0].y = Y - 100;
	sail[1].x = X + 70;
	sail[1].y = Y - 25;
	sail[2].x = X - 40;
	sail[2].y = Y - 25;	
	
	gfx_color(74, 64, 25);	//wood brown
	gfx_fill_polygon(base, 4);
	gfx_color(0, 0, 0);		//black
	gfx_fill_polygon(sail, 3);
}

// Treasure
void pickColor(int c)
{
	switch (c)
	{
		case 0:
			gfx_color(102, 178, 255); // light
			break;
		case 1:
			gfx_color(0, 102, 204); // medium
			break;
		case 2:
			gfx_color(0, 51, 102); // dark
			break;
		case 3:
			gfx_color(255, 255, 255); // white
			break;
		case 4:
			gfx_color(0, 0, 0); // black
			break;
		case 5:
			gfx_color(255, 255, 0); // yellow
			break;
	}
}

// Functions for Set Up
	
void initializeBoard(struct Blocks board[], int length, int x0, int y0, int w)
{
	initializeWidth(board, length, w); // initializes all width
	initializeX(board, length, x0); // sets all x positions
	initializeY(board, length, y0); // sets all y positions
	initializeTreasure(board, length); // initializes all treasure to 0
	randTreasure(board, length); // picks random places for treasure
	initializeColor(board, length); // sets color for each cell
	initializePosition(board, length); // sets current position
}

void initializeX(struct Blocks board[], int length, int x0)
{
	int i, x = x0, d = board[0].width;
	for (i = 0; i < length; i++)
	{
		if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100 || i == 110 || i == 120 || i == 130 || i == 140)
		{
			x = x0;
		}
		board[i].x = x;
		x += d;
	}
}

void initializeY(struct Blocks board[], int length, int y0)
{
	int i, y = y0, d = board[0].width;
	for (i = 0; i < length; i++)
	{	
		if (i == 10 || i == 20 || i == 30 || i == 40 || i == 50 || i == 60 || i == 70 || i == 80 || i == 90 || i == 100 || i == 110 || i == 120 || i == 130 || i == 140)
		{
			y += d;
		}
		board[i].y = y;
	}
}

void initializeTreasure(struct Blocks board[], int length)
{
	int i; // get random value for color
	for (i = 0; i < length; i++)
	{
		board[i].treasure = 0;
	}
}

void randTreasure(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	int i, x; 

	for (i = 0; i < 10; i++)
	{
		x = rand() % 150; // get random place for treasure
		if (x == 74) x + (rand() % 10);
		board[x].treasure = 1; // set position as treasure
	}
}

void initializeWidth(struct Blocks board[], int length, int width)
{
	int i;
	for (i = 0; i < length; i++)
	{
		board[i].width = width;
	}
}

void initializeColor(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (i == 74) board[i].color = rand() % 3;
		else board[i].color = 3;
	}
}

void initializePosition(struct Blocks board[], int length)
{
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (i == 74) board[i].current = 1;
		else if (i != 74) board[i].current = 0;
	}
}

void printBoard(struct Blocks board[], int length)
{
	time_t t;
	srand(time(&t));
	
	int i;
	
	for (i = 0; i < length; i++)
	{
		if (board[i].treasure)
		{
			board[i].color = rand() % 3;
			pickColor(board[i].color); // set drawing color to stored (light/medium/dark)
			gfx_fill_rectangle(board[i].x, board[i].y, board[i].width, board[i].width);
			printCoin(board[i].x, board[i].y);
		}
		else if (!board[i].treasure)
		{
			pickColor(board[i].color); // set drawing color to stored (white)
			gfx_fill_rectangle(board[i].x, board[i].y, board[i].width, board[i].width);
		}
		if (board[i].current)
		{
			printX(board[i].x, board[i].y);
		}
	}
}

void printCoin(int x, int y)
{
	x = x + ((x + 40) - x)/2;
	y = y + ((y + 40) - y)/2;
	
	pickColor(5); // set drawing color to yellow
	gfx_fill_circle(x, y, 10);
}

void printX(int x, int y)
{
	int x1, y1, x2, y2;
	pickColor(4); // set drawing color to black
	
	x1 = x + ((x + 40) - x)/3;
	y1 = y + ((y + 40) - y)/3;
	x2 = x + 2*((x + 40) - x)/3;
	y2 = y + 2*((y + 40) - y)/3;
	gfx_line(x1, y1, x2, y2);
	
	y = y + 40; // adjust y for second line
	x1 = x + ((x + 40) - x)/3;
	y1 = y + ((y - 40) - y)/3;
	x2 = x + 2*((x + 40) - x)/3;
	y2 = y + 2*((y - 40) - y)/3;
	gfx_line(x1, y1, x2, y2);
}

void printUpcoming(int x)
{
	pickColor(x); // sets color
	gfx_fill_rectangle(350, 115, 20, 20);
}

void printText()
{
	pickColor(3); // set drwaing color to white
	// print text
	gfx_text(43, 15, "Arggg, Matey! Time to find the treasure!");
	gfx_text(18, 35, "Use arrow keys to move up, down, left, and right.");
	gfx_text(28, 50, "Match three or more blocks of the same color.");
	gfx_text(55, 65, "Collect as much treasure as possible.");
	gfx_text(105, 80, "But don't get trapped!");
	gfx_text(140, 120, "Good Luck!");
	gfx_text(335, 110, "Up Next: ");
	gfx_text(105, 770, "Press 'q' anytime to exit.");
	
	gfx_changefont("lucidasanstypewriter-bold-24");
	pickColor(4);
	gfx_text(580, 320, "HUNT");
	gfx_text(585, 360, "for");
	gfx_text(550, 400, "TREASURE");
}

int newColor()
{
	time_t t;
	srand(time(&t));
	int c;
	c = rand() % 3;
	
	return c;
}

// Functions for Playing
void printBlock(int x, int y, int width, int color)
{
	pickColor(color); // set drawing color to next color
	gfx_fill_rectangle(x, y, width, width);
}

// Check and Change if Match
int checkFour(struct Blocks board[], int length, int currentPosition)
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
	board[currentPosition].current = 0;
	printBlock(board[currentPosition].x, board[currentPosition].y, board[currentPosition].width, board[currentPosition].color);
	switch (c)
	{
		case 'u':
			currentPosition -= 10;
			break;
		case 'd':
			currentPosition += 10;
			break;
		case 'l':
			currentPosition -= 1;
			break;
		case 'r':
			currentPosition += 1;
			break;
	}
	board[currentPosition].current = 1;
	board[currentPosition].color = nextColor;
	printBlock(board[currentPosition].x, board[currentPosition].y, board[currentPosition].width, board[currentPosition].color);
	printX(board[currentPosition].x, board[currentPosition].y);
	
	return currentPosition;
}

int isTrapped(struct Blocks board[], int length, int currentPosition)
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
{
	char c;
	int x0 = 0, y0 = 150, w = 40, length = 150, currentPosition = 74;
	int xsize = 800, ysize = 800;
	int nextColor, currentColor;
	int trapped = 0;
	struct Blocks board[length];
	
	printBackground(xsize, ysize);
	printShip();
	pickColor(4); // sets color to black
	gfx_fill_rectangle(0, 0, 400, 150);		// prints box around text
	gfx_line(400, 0, 400, 750);			// prints side border line
	gfx_line(0, 750, 400, 750);			// prints bottom border line
	printText();
	nextColor = newColor();
	printUpcoming(nextColor);
	initializeBoard(board, length, x0, y0, w);
	printBoard(board, length);
	
	while (1) {
		c = gfx_wait();
		switch (c) {
			case 'R': // Up
				if (currentPosition >= 1 && currentPosition <= 9)
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition - 10].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'u');
					if (checkFour(board, length, currentPosition));
					else if (checkThree(board, length, currentPosition));
					else if (checkTwo(board, length, currentPosition));
					nextColor = newColor();
					printUpcoming(nextColor);
				}
				trapped = isTrapped(board, length, currentPosition);
				break;
			case 'S': // Right
				if (currentPosition == 9 || currentPosition == 19 || currentPosition == 29 || currentPosition == 39 || currentPosition == 49 || currentPosition == 59 || currentPosition == 69 || currentPosition == 79 || currentPosition == 89 || currentPosition == 99 || currentPosition == 109 || currentPosition == 119 || currentPosition == 129 || currentPosition == 139 || currentPosition == 149)
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition + 1].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'r');
					if (checkFour(board, length, currentPosition));
					else if (checkThree(board, length, currentPosition));
					else if (checkTwo(board, length, currentPosition));
					nextColor = newColor();
					printUpcoming(nextColor);
				}
				trapped = isTrapped(board, length, currentPosition);
				break;
			case 'T': // Down
				if (currentPosition >= 140 && currentPosition <= 149)
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition + 10].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'd');
					if (checkFour(board, length, currentPosition));
					else if (checkThree(board, length, currentPosition));
					else if (checkTwo(board, length, currentPosition));
					nextColor = newColor();
					printUpcoming(nextColor);
				}
				trapped = isTrapped(board, length, currentPosition);
				break;
			case 'Q': // Left
				if (currentPosition == 0 || currentPosition == 10 || currentPosition == 20 || currentPosition == 30 || currentPosition == 40 || currentPosition == 50 || currentPosition == 60 || currentPosition == 70 || currentPosition == 80 || currentPosition == 90 || currentPosition == 100 || currentPosition == 110 || currentPosition == 120 || currentPosition == 130 || currentPosition == 140)
				{
					printf("Out of Board. Make another move.\n");
				}
				else if (board[currentPosition - 1].color == 3)
				{
					currentPosition = move(board, length, currentPosition, nextColor, 'l');
					if (checkFour(board, length, currentPosition));
					else if (checkThree(board, length, currentPosition));
					else if (checkTwo(board, length, currentPosition));
					nextColor = newColor();
					printUpcoming(nextColor);
				}
				trapped = isTrapped(board, length, currentPosition);
				break;
			case 'q':
				return 0;
		}
		if (trapped) break;
	}
	return 0;
}

// Attack


/*void playPirate()
{
	PirateShip BlackPearl = {0.0, 0.0, 0.0, 1001, 125, 125, 2, 4, 100, "Black", "SEA", "null"};
	AttackStats attack;
	printStart(&BlackPearl);
	pirateLife(&BlackPearl, &attack);
}*/

// Rum
void drawBlackHair()
{
	XPoint hair[10];
	gfx_color(0, 0, 0);	//black
	
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

void drawBeard() //12
{
	XPoint beard[12];
	gfx_color(38, 20, 9);	//dark brown
	
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

void drawEyebrows() //left 4 //right 8
{
	// Left
	XPoint left[4];
	gfx_color(38, 20, 9);	//dark brown
	
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
	
	right[0].x = 520;
	right[0].y = 300;
	right[1].x = 530; // 3 or 5
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

void drawNostril() //3
{
	XPoint nostril[3];
	gfx_color(0, 0, 0);	//black
	
	nostril[0].x = 480;
	nostril[0].y = 400;
	nostril[1].x = 500;
	nostril[1].y = 400;
	nostril[2].x = 505;
	nostril[2].y = 410;

	gfx_fill_polygon(nostril, 3);
}

void drawEye() //white 5 //pupil 4
{
	// White
	XPoint white[5];
	gfx_color(255, 255, 255);	//white
	
	white[0].x = 520;
	white[0].y = 340;
	white[1].x = 545;
	white[1].y = 350;
	white[2].x = 580;
	white[2].y = 320; // 3 or 5
	white[3].x = 570;
	white[3].y = 305;
	white[4].x = 540;
	white[4].y = 310;

	gfx_fill_polygon(white, 5);
	
	// Pupil
	XPoint pupil[4];
	gfx_color(0, 0, 0);	//black
	
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

void drawBrownHair() //14
{
	XPoint hair[14];
	gfx_color(15, 8, 3);	//brown
	
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
	gfx_color(123, 26, 21);	//dark red
	
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
	gfx_color(0, 0, 0); //black
	gfx_changefont("lucidasanstypewriter-bold-24");
	gfx_text(120, 240, "WHY IS");
	gfx_text(120, 320, "THE RUM");
	gfx_text(120, 400, "ALWAYS");
	gfx_text(120, 480, "GONE?");
	
	gfx_changefont("lucidasanstypewriter-bold-18");
	gfx_text(150, 540, "- Jack Sparrow");
	
	gfx_changefont("lucidasanstypewriter-bold-12");
	gfx_text(120, 760, "To exit, press 'q'.");
}


void drinkRum()
{
	char c;
	int xsize = 800, ysize =  800;
	
	gfx_open(xsize, ysize, "Rum");
	gfx_clear();
	
	while (1)
	{
		gfx_color(102, 152, 182);
		gfx_fill_rectangle(0, 0, xsize, ysize);
		
		drawBlackHair();
		drawFace();
		gfx_color(0, 0, 0);
		gfx_line(445, 385, 480, 300); // nose line
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
		if (c == 'q') break;
	}
}

