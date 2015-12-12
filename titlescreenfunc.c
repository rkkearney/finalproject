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
	
	/*if ((X >= 100 && X <= 350) && (Y >= 275 && Y <= 375)) option = 1;
	else if ((X >= 450 && X <= 700) && (Y >= 275 && Y <= 375)) option = 2;
	else if ((X >= 275 && X <= 525) && (Y >= 450 && Y <= 550)) option = 3;
	else if ((X >= 100 && X <= 350) && (Y >= 625 && Y <= 725)) option = 4;
	else if ((X >= 450 && X <= 700) && (Y >= 625 && Y <= 725)) option = 0;
	else option = 5;*/
	if ((X >= 25 && X <= 175) && (Y >= 225 && Y <= 325)) option = 1;
	else if ((X >= 225 && X <= 375) && (Y >= 225 && Y <= 325)) option = 2;
	else if ((X >= 125 && X <= 275) && (Y >= 400 && Y <= 500)) option = 3;
	else if ((X >= 25 && X <= 175) && (Y >= 575 && Y <= 675)) option = 4;
	else if ((X >= 225 && X <= 375) && (Y >= 575 && Y <= 675)) option = 0;
	else option = 5;
	return option;
}

void printMenu()
{
	printBox(25, 225, "Attack Ships", 55, 275);
	printBox(225, 225, "Hunt for Treasure", 240, 275);
	printBox(125, 400, "Drink Rum", 165, 450);
	printBox(25, 575, "Go to the Market", 45, 625);
	printBox(225, 575, "Quit", 285, 625);
}

void printBox(int x, int y, char * title, int xt, int yt)
{
	// box
	gfx_color(51, 25, 0); //brown
	gfx_fill_rectangle(x, y, 150, 100);
	
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

int playGame(int xsize, int ysize, int c)
{
	int gold = 0;
	
	// gfx_open(xsize, ysize, "Mini Game");
	gfx_clear();
	
	if (c == 1) playPirate();
	else if (c == 2) gold = treasureHunt();
	
	return gold;
}

void printTitleScreen(int xsize, int ysize)
{
	// Set Up Window
	gfx_clear();

	// Draw Window
	printBackground(xsize, ysize);
	printTitle();
	printMenu();
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
		if (x == 74)
		{
			x + (rand() % 10);
		}
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
		if (i == 74)
		{
			board[i].current = 1;
		}
		else if (i != 74)
		{
			board[i].current = 0;
		}
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
	gfx_text(70, 15, "Arggg, Matey! Time to find the treasure!");
	gfx_text(45, 35, "Use arrow keys to move up, down, left, and right.");
	gfx_text(55, 50, "Match three or more blocks of the same color.");
	gfx_text(85, 65, "Collect as much treasure as possible.");
	gfx_text(125, 80, "But don't get trapped!");
	gfx_text(120, 95, "Click to anywhere to exit.");
	gfx_text(160, 120, "Good Luck!");
	gfx_text(335, 110, "Up Next: ");
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
	int nextColor, currentColor;
	int trapped = 0;
	struct Blocks board[length];
	
	printText();
	printUpcoming(3);
	initializeBoard(board, length, x0, y0, w);
	printBoard(board, length);
	nextColor = newColor();

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
			case 1:
				return 0;
		}
		if (trapped) break;
	}
	
	// printf("Collected Treasure: %d \n", collectedTreasure);
	
	return 0;
}

// Attack
#define XSIZE 400
#define YSIZE 750
#define XMID 200
#define YMID 375
#define CANNONBALLWEIGHT 10
#define CANNONWEIGHT 1000
#define SHIPWEIGHT 10000
#define CANNONPRICE 2000
#define CANNONBALLPRICE 10
/*
typedef struct PirateShip_t
{
	double windSpeed, weight, shipSpeed;
	int gold, life, hp, level, cannons, cannonballs;
	char FlagColor[10];
	char Location[15];
	char Action[20];
} PirateShip;
typedef struct Attack_t
{
	int enemyShipLvl, enemyGold, enemyLife, enemyHP, enemyCannons, enemyCannonballs, damageToEnemy, hit, enemyHit, damageToMe;
	char EnemyLocation[10];
	char EnemyFlagColor[10];
	char Attack[20];
	bool win;
} AttackStats;*/
//FUNCTIONS
void rest(PirateShip *myShip)
{
	printf("YOU HAVE RESTED AND REPAIRED ALL DAMAGE TO YOUR SHIP.\n");
	myShip->life = myShip->hp;
}

void printEnemy(AttackStats *attack)
{
	printf("Enemy Ship Lvl : %d\n", attack->enemyShipLvl);
	printf("Enemy Location : %s\n", attack->EnemyLocation);
	printf("Enemy Flag Color : %s\n", attack->EnemyFlagColor);
}

void attackWave(PirateShip *myShip, AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	char Answer[20];
	int d = 0;			//distance from user game
	//Your attack on the enemy
	if (myShip->cannonballs <= 0)
	{
		printf("YOU HAVE NO CANNONBALLS. GO BUY THEM AT THE PORT\n");
	}
	else
	{
		d = playerShot(attack);
		if (myShip->cannonballs >= myShip->cannons)
		{
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
			else if (d <= 80)
			{
				attack->hit = myShip->cannons - 4;
			}
			else if (d <= 160)
			{
				attack->hit = myShip->cannons - 5;	
			}
			else if (d <= 185)
			{
				attack->hit = myShip->cannons - 6;	
			}
			attack->damageToEnemy = attack->hit * 10;
			attack->enemyLife -= attack->damageToEnemy;
			myShip->cannonballs -= myShip->cannons;
		}
		else	//if 0<cannonballs<cannons
		{
			if (d <= 10)
			{
				attack->hit = myShip->cannonballs;
			}
			else if (d <= 20)
			{
				attack->hit = myShip->cannonballs - 1;
			}
			else if (d <= 40)
			{
				attack->hit = myShip->cannonballs - 2;
			}
			else if (d <= 80)
			{
				attack->hit = myShip->cannonballs - 3;
			}
			else if (d <= 160)
			{
				attack->hit = myShip->cannonballs - 4;
			}
			else if (d <= 320)
			{
				attack->hit = myShip->cannonballs - 5;	
			}
			else
			{
				attack->hit = myShip->cannonballs - 6;	
			}
			attack->damageToEnemy = attack->hit * 10;
			attack->enemyLife -= attack->damageToEnemy;
			myShip->cannonballs = 0;
		} 
		
	}
	/*
	if (myShip->cannonballs >= myShip->cannons)
	{
		attack->hit = rand() % myShip->cannons +1;
		attack->damageToEnemy = attack->hit * 10;
		attack->enemyLife -= attack->damageToEnemy;
		myShip->cannonballs -= myShip->cannons;
	}
	else if (myShip->cannonballs > 0)
	{
		attack->hit = rand() % myShip->cannonballs +1;
		attack->damageToEnemy = attack->hit * 10;
		attack->enemyLife -= attack->damageToEnemy;
		myShip->cannonballs = 0;
	}
	else
	{
		printf("YOU HAVE NO CANNONBALLS. GO BUY THEM AT THE PORT\n");
	}*/
	//enemy attack on you
	if (attack->enemyCannonballs >= attack->enemyCannons)
	{
		attack->enemyHit = rand() % attack->enemyCannons + 1;
		attack->damageToMe = attack->enemyHit * 10;
		myShip->life -= attack->damageToMe;
		attack->enemyCannonballs -= attack->enemyCannons;
	}
	else if (attack->enemyCannonballs > 0)
	{
		attack->hit = rand() % attack->enemyCannonballs;
		attack->damageToMe = attack->enemyHit * 10;
		myShip->life -= attack->damageToMe;
		attack->enemyCannonballs = 0;
	}
	else //enemy has no ammo
	{
		attack->enemyLife = 0;
	}

	//print results of attack
	printf("Life : %d/%d\n", myShip->life, myShip->hp);
	printf("Cannonballs left : %d\n", myShip->cannonballs);
	printf("Enemy Life : %d/%d\n", attack->enemyLife, attack->enemyHP);

	if (myShip->life >= .25 * myShip->hp && attack->enemyLife >= .25 * attack->enemyHP)
	{
		printf("BOTH SHIPS ARE STILL SAILING. ATTACK AGAIN? (yes or no)\n");
		scanf("%s", Answer);
		if (!strcmp(Answer, "yes"))
		{
			attackWave(myShip, attack);
		}
		else
		{
			printf("YOU ARE BACK AT PORT\n");
			strcpy(myShip->Location, "PORT");
		}
	
	}
	else if (myShip->life > attack->enemyLife && myShip->life > 0 || myShip->life >= .25 * myShip->hp && attack->enemyLife < .25 * attack->enemyHP)
	{
		printf("YOU SUCCESSFULLY LOOTED THE ENEMY SHIP, GAINED %d GOLD, AND ARE BACK AT PORT\n", attack->enemyGold);
		myShip->gold += attack->enemyGold;
		myShip->hp += attack->enemyHP * .1;
		strcpy(myShip->Location, "PORT");
		printShipStatus(myShip);
	}
	else 
	{
		printf("YOUR SHIP HAS BEEN BOARDED. HALF OF YOUR GOLD HAS BEEN PILLAGED. BACK TO PORT AND BETTER LUCK NEXT TIME.\n");
		myShip->gold -= .5 * myShip->gold;
		strcpy(myShip->Location, "PORT");
		printShipStatus(myShip);
	}
}
double shipSpeed(PirateShip *myShip)
{
	myShip->weight = SHIPWEIGHT + (myShip->cannons * CANNONWEIGHT) + (myShip->cannonballs * CANNONBALLWEIGHT);
	printf("Input Wind Speed in Knots --> \n");
	scanf("%d", myShip->shipSpeed);
	//buoyancy = xxxxxxx
	//shipspeed = shipspeed -=buoyancy
	return myShip->shipSpeed;
}

void attackShip(PirateShip *myShip, AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	char Attack[20];
	if (!strcmp(myShip->Location, "SEA"))
	{
		attack->enemyShipLvl = rand() % 3 +1;
	
		if (attack->enemyShipLvl == 1)
		{
			strcpy(attack->EnemyFlagColor, "yellow");
			strcpy(attack->EnemyLocation, "SEA");
			attack->enemyGold = rand() % 1001;
			attack->enemyLife = rand() % 91 + 10;
			attack->enemyHP = attack->enemyLife;
			attack->enemyCannons = rand() % 4 + 1;
			attack->enemyCannonballs = rand() % 30 + 1;
		}
		else if (attack->enemyShipLvl == 2)
		{
			strcpy(attack->EnemyFlagColor, "red");
			strcpy(attack->EnemyLocation, "SEA");
			attack->enemyGold = rand() % 4000 + 1001;
			attack->enemyLife = rand() % 200+ 101;
			attack->enemyHP = attack->enemyLife;
			attack->enemyCannons = rand() % 4 + 4;
			attack->enemyCannonballs = rand() % 40 + 31;
		}
		else	//if enemy ship lvl == 0
		{
			strcpy(attack->EnemyFlagColor, "blue");
			strcpy(attack->EnemyLocation, "SEA");
			attack->enemyGold = rand() % 10000 + 5001;
			attack->enemyLife = rand() % 200+ 301;
			attack->enemyHP = attack->enemyLife;
			attack->enemyCannons = rand() % 5 + 8;
			attack->enemyCannonballs = rand() % 50 + 71;
		}
		printEnemy(attack);
		printf("Attack? (yes or no) : \n");
		scanf("%s", Attack);
		if (!strcmp(Attack, "yes"))
		{
			attackWave(myShip, attack);	//recursion
		}
		else
		{
			printf("YOU ARE AT SEA\n");
			strcpy(myShip->Location, "SEA");
		}
	
	
	}
	else
	{
		printf("YOU ARE NOT AT SEA\n");
	}
	//find and attack random 0-500hp
	//win = get gold random amount between x and x, x% of defeated ships hp depending on ship level 1,2,3
	//chance of winning varies random between x and x for levels 1,2,3
	//level 1 = 10-100hp, 0-3 cannons, 0 - 1000 gold, holds 0-30 cannonballs
	//level 2 = 101-300hp, 4-7 cannons, 1001 - 5000 gold, holds 31-70 cannonballs
	//level 3 = 301-500hp, 8-12 cannons, 5001 - 15,000 gold, holds 71 - 120 cannonballs
}

void goToPort(PirateShip *myShip)
{
	strcpy(myShip->Location, "PORT");
	printf("YOU ARE AT PORT\n");
}
void goToSea (PirateShip *myShip)
{
	strcpy(myShip->Location, "SEA");
	printf("YOU ARE AT SEA\n");
}

void buyCannons(PirateShip *myShip, int number)
{
	if (!strcmp(myShip->Location, "PORT"))
	{
		if (number * CANNONPRICE < myShip->gold)
		{
			myShip->gold -= (number * CANNONPRICE);
			myShip->cannons += number;
			printf("YOU HAVE BOUGHT %d CANNONS\n", number);
		}
		else
		{
			printf("YOU DO NOT HAVE ENOUGH GOLD. GO ATTACK SOME SHIPS.\n");
		}
	}
	else
	{
		printf("YOU ARE NOT AT PORT\n");
	}
}
void buyCannonballs(PirateShip *myShip, int number)
{
	if (!strcmp(myShip->Location, "PORT"))
	{
		if (number * CANNONBALLPRICE < myShip->gold)
		{
			myShip->gold -= (number * CANNONBALLPRICE);
			myShip->cannonballs += number;
			printf("YOU HAVE BOUGHT %d CANNONBALLS\n", number);
		}
		else
		{
			printf("YOU DO NOT HAVE ENOUGH GOLD. GO ATTACK SOME SHIPS.\n");
		}
	}
	else
	{
		printf("YOU ARE NOT AT PORT\n");
	}
}

void printShipStatus(PirateShip *myShip)
{
	printf("Location : %s\n", myShip->Location);
	printf("Flag Color : %s\n", myShip->FlagColor);
	printf("Life : %d/%d\n", myShip->life, myShip->hp);
	if (!strcmp(myShip->Location, "SEA"))
	{
		printf("Ship Speed : %d\n", myShip->shipSpeed);
		printf("Total Ship Weight : %d\n", myShip->weight);
	}
	printf("# of Cannons : %d\n", myShip->cannons);
	printf("# of Cannonballs : %d\n", myShip->cannonballs);
	printf("Gold Pieces : %d\n", myShip->gold);
	//fix level
	
	if (myShip->hp <= 100 || myShip->cannons <= 3)
	{
		myShip->level = 1;
	}
	else if (myShip->hp > 300 && myShip->cannons > 7)
	{
		myShip->level = 3;
	}
	else
	{
		myShip->level = 2;
	}
	printf("Ship Level : %d\n", myShip->level);
}

void pirateLife(PirateShip *myShip, AttackStats *attack)
{
	/*gfx_open(XSIZE, YSIZE, "Target Window");
	gfx_clear;*/
	while(1)
	{
		int number = 0;
		printf("=======================================\n");
		if (myShip->cannonballs <= 0 && myShip->gold < 10)
		{
			printf("YOU ARE POOR AND DO NOT HAVE THE SUPPLIES TO ATTACK. YOUR CREW COMMITS MUTINY AND YOU WALK THE PLANK.\n");
			strcpy(myShip->Action, "end");
		}
		else if (myShip->hp >= 300 && myShip->gold > 10000)
		{
			printf("YOU ARE A SUCCESSFUL PLUNDERING PIRATE! ENJOY YOUR INFAMY IN YOUR PALACE IN THE CARRIBBEAN.\n");
			strcpy(myShip->Action, "end");
		}
		else
		{
			printf("What Would You Like To Do? \ngotoport\ngotosea\nbuycannons\nbuycannonballs\nattackships\nshipstats\nrest\nend\n");
			printf("=======================================\n");
			scanf("%s", myShip->Action);
		}
		if (!strcmp(myShip->Action, "gotoport"))
		{
			goToPort(myShip);
		}
		else if (!strcmp(myShip->Action, "gotosea"))
		{
			goToSea(myShip);
		}
		else if (!strcmp(myShip->Action, "buycannons"))
		{
			printf("Cannon Price : %d\n", CANNONPRICE);
			printf("Input # of Cannons : \n");
			scanf("%d", &number);
			buyCannons(myShip, number);
		}
		else if (!strcmp(myShip->Action, "buycannonballs"))
		{
			printf("Cannonball Price : %d\n", CANNONBALLPRICE);
			printf("Input # of Cannonballs : \n");
			scanf("%d", &number);
			buyCannonballs(myShip, number);
		}
		else if (!strcmp(myShip->Action, "attackships"))
		{
			attackShip(myShip, attack);
		}
		else if (!strcmp(myShip->Action, "shipstats"))
		{
			printShipStatus(myShip);
		}
		else if (!strcmp(myShip->Action, "rest"))
		{
			rest(myShip);
		}
		else if (!strcmp(myShip->Action, "end"))
		{
			printf("YOUR PIRATE LIFE HAS ENDED\n");
			printShipStatus(myShip);
			break;
		}
		else
		{
			printf("PLEASE TYPE A VALID RESPONSE\n");
		}
	}
}
void printStart(PirateShip *myShip)
{
	printf("WELCOME TO THE PIRATE LIFE!\n");
	printShipStatus(myShip);
}
int playerShot(AttackStats *attack)
{
	time_t t;
	srand(time(&t));
	int r = 30;					//radius
	int x = 50, y = YMID;		//starting coordinates
	int d = 0;		//distance from center target
	double dx = 0.;		//change in coordinates
	char c;
	double deltat = 10000;
	//Open screen
	//gfx_open(XSIZE, YSIZE, "Target Window");
	//gfx_clear;
	//gfx_clear_color(213, 47, 94);
	drawEnemy(attack);
	
	//change crosshair target speed
	if(attack->enemyShipLvl == 1)		//level 1 enemy
	{
		dx = 1;
	}
	else if (attack->enemyShipLvl == 2)		//level 2 enemy
	{
		dx = 2;
	}
	else		//level 3 enemy
	{
		dx = 3;
	}
	
	while (1)
	{
		gfx_clear();
		//gfx_clear_color(213, 47, 94);
		drawEnemy(attack);
		//draw white target circle
		gfx_color(255, 255, 255);
		gfx_circle(XMID, YMID, r);
		//draw moving green crosshair circle
		//gfx_color(82, 199, 104);
		gfx_color(0, 153, 0);
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
			if (c == 1)
			{
				d = abs(x-XMID);
				return d;
				break;
			}
		}
	}	
}
void drawEnemy(AttackStats *attack)
{
	XPoint base[4];
	XPoint sail[3];
	base[0].x = XMID - 70;
	base[0].y = YMID - 20;
	base[1].x = XMID + 70;
	base[1].y = YMID - 20;
	base[2].x = XMID + 40;
	base[2].y = YMID + 20;
	base[3].x = XMID - 40;
	base[3].y = YMID + 20;
	
	sail[0].x = XMID;
	sail[0].y = YMID - 100;
	sail[1].x = XMID + 70;
	sail[1].y = YMID - 25;
	sail[2].x = XMID - 40;
	sail[2].y = YMID - 25;
	
	
	gfx_color(17, 0, 127);							//ocean blue
	gfx_fill_rectangle(0, YSIZE/2, XSIZE, YSIZE/2);
	gfx_color(204, 229, 255);						//sky blue
	gfx_fill_rectangle(0, 0, XSIZE, YSIZE/2);
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

void playPirate()
{
	PirateShip BlackPearl = {0.0, 0.0, 0.0, 1001, 125, 125, 2, 4, 100, "Black", "SEA", "null"};
	AttackStats attack;
	printStart(&BlackPearl);
	pirateLife(&BlackPearl, &attack);
}

