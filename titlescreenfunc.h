#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include "gfx4.h"

// title screen
int checkZone(int X, int Y);

void printMenu();

void printBox(int x, int y, char * title, int xt, int yt);

void printBackground(int x, int y);

void printTitle();

void playGame(int c);

void printTitleScreen(int xsize, int ysize);

void printShip();

// attack

void playPirate();

// treasure
struct Blocks {
	int x;
	int y;
	int width;
	int color;
	int treasure;
	int current;
};

void pickColor(int c);

void initializeBoard(struct Blocks board[], int length, int x0, int y0, int w);

void initializeX(struct Blocks board[], int length, int x0);

void initializeY(struct Blocks board[], int length, int x0);

void initializeTreasure(struct Blocks board[], int length);

void randTreasure(struct Blocks board[], int length);

void initializeWidth(struct Blocks board[], int length, int width);

void initializeColor(struct Blocks board[], int length);

void initializePosition(struct Blocks board[], int length);

void printBoard(struct Blocks board[], int length);

void printCoin(int x, int y);

void printX(int x, int y);

void printUpcoming(int x);

void printText();

int newColor();

void printBlock(int x, int y, int width, int color);

int move(struct Blocks board[], int length, int currentPosition, int nextColor, char c);

int isTrapped(struct Blocks board[], int length, int currentPosition);

int checkFour(struct Blocks board[], int length, int currentPosition);

int checkThree(struct Blocks board[], int length, int currentPosition);

int checkTwo(struct Blocks board[], int length, int currentPosition);

int treasureHunt();

// rum

void drawBlackHair();

void drawFace();

void drawLips();

void drawMushtache();

void drawTeeth();

void drawBeard();

void drawEyebrows();

void drawNostril();

void drawEye();

void drawBrownHair();

void drawHat();

void printRum();

