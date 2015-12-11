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

int playGame(int xsize, int ysize, int c);

void printTitleScreen(int xsize, int ysize);

// attack
#ifndef FINALFUNC_H
#define FINALFUNC_H

typedef struct PirateShip_t
{
	double windSpeed, weight, shipSpeed;
	int gold, life, hp, level, cannons, cannonballs;
	char FlagColor[10];
	char Location[10];
	char Action[20];
} PirateShip;

typedef struct AttackStats_t
{
	int enemyShipLvl, enemyGold, enemyLife, enemyHP, enemyCannons, enemyCannonballs, damageToEnemy, hit, enemyHit, damageToMe;
	char EnemyLocation[10];
	char EnemyFlagColor[10];
	char Attack[20];
	bool win;
} AttackStats;

void rest(PirateShip *myShip);

void printShipStatus(PirateShip *myShip);

void printEnemy(AttackStats *attack);

void attackWave(PirateShip *myShip, AttackStats *attack);

double shipSpeed(PirateShip *myShip);

void attackShip(PirateShip *myShip, AttackStats *attack);

void goToPort(PirateShip *myShip);

void goToSea(PirateShip *myShip);

void buyCannons(PirateShip *myShip, int number);

void buyCannonballs(PirateShip *myShip, int number);

void pirateLife(PirateShip *myShip, AttackStats *attack);

void printStart(PirateShip *myShip);

void drawEnemy(AttackStats *attack);

int playerShot(AttackStats *attack);

void playPirate();

#endif

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

