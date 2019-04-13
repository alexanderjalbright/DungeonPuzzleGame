#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int intFloorY = 0;
int intFloorX = 0;
int intFloor[32][46];
int CurrentPosY;
int CurrentPosX;
int OldPosY;
int OldPosX;
int intExit = 0;
int intGame = 0;
int intMoveNum = 0;



void main()
{
	int intItems = 0;
	printf("Welcome to ASCII Sandbox!\n");
	printf("Created by: Alex Albright, Tyler Dudley, and Nick Johnson.\n\n");
	
	do {
		printf("Enter the number for the item you wish to perform: \n");
		printf("1. How to Play\n");
		printf("2. Play\n");

		scanf("%d", &intItems);

		switch (intItems) {
			case 1:
				HowTo();
				break;
			case 2:
				intGame = 1;
				intMoveNum = 0;
				Setup();
				while (intGame == 1 && intMoveNum < 106) {
					PrintMap();
					Move();
				}
				if (intMoveNum == 106) {
					PrintMap();
					Winner();
				}
				break;
		}
	} while (intExit == 0);
	return;
}

int HowTo() {
	printf("***************************************\n");
	printf("*             HOW TO PLAY             *\n");
	printf("***************************************\n");
	printf("* ROCKS   WALLS   SAND   FINISH   YOU *\n");
	printf("*  ###     XXX     ...     $$$    \\O/ *\n");
	printf("*  # #     XXX     ...     $$$     |  *\n");
	printf("*  ###     XXX     ...     $$$    / \\ *\n");
	printf("***************************************\n");
	printf("*Pick up all of the sand out of the   *\n");
	printf("*  sand box without backtracking.     *\n");
	printf("*You must collect all of the sand.    *\n");
	printf("*You must end on the finish spot!     *\n");
	printf("***************************************\n");
	printf("*  TYPE      *          TO MOVE       *\n");
	printf("*    W       *            UP          *\n");
	printf("*  A S D     *    LEFT   DOWN   RIGHT *\n");
	printf("***************************************\n");
	printf("*    TYPE V TO RETURN TO THE MENU     *\n");
	printf("***************************************\n"); 
	printf("\n\n");
	






	return 0;
}

int Setup()
{
	int intBlockNum = 0;
	int intBlockPosY = 0;
	int intBlockPosX = 0;
	printf("Setting up game map!\n");
	CurrentPosY = 17;
	CurrentPosX = 43;
	OldPosY = 0;
	OldPosX = 0;
	
	//1 is wall
	//2 is tile
	//3 is character

	//First Floor
	for (intFloorY = 0; intFloorY < 3; intFloorY++) {
		for (intFloorX =0; intFloorX < 45; intFloorX++) {
			intFloor[intFloorY][intFloorX] = 1;
		}
	}

	//Second through tenth Floor

	for (intFloorY = 3; intFloorY < 30; intFloorY++) {
		for (intFloorX = 0; intFloorX < 45; intFloorX++) {
			if (intFloorX < 3 || intFloorX > 41) {
				intFloor[intFloorY][intFloorX] = 1;
			}
			else {
				intFloor[intFloorY][intFloorX] = 2;
			}
		}

	}

	//Last Floor
	for (intFloorY = 30; intFloorY < 33; intFloorY++) {
		for (intFloorX = 0; intFloorX < 45; intFloorX++) {
			intFloor[intFloorY][intFloorX] = 1;
		}
	}

	//Character Start
	intFloor[CurrentPosY][CurrentPosX] = 4;
	intFloor[CurrentPosY-1][CurrentPosX] = 7;
	intFloor[CurrentPosY-2][CurrentPosX] = 8;
	intFloor[CurrentPosY][CurrentPosX-1] = 5;
	intFloor[CurrentPosY][CurrentPosX+1] = 6;
	intFloor[CurrentPosY-1][CurrentPosX-1] = 4;
	intFloor[CurrentPosY-1][CurrentPosX+1] = 4;
	intFloor[CurrentPosY-2][CurrentPosX-1] = 6;
	intFloor[CurrentPosY-2][CurrentPosX+1] = 5;

	//Blocks
	for (intBlockNum = 0; intBlockNum < 11; intBlockNum++) {
		switch (intBlockNum) {
		case 0:
			intBlockPosY = 8;
			intBlockPosX = 8;
			break;
		case 1:
			intBlockPosY = 8;
			intBlockPosX = 11;
			break;
		case 2:
			intBlockPosY = 8;
			intBlockPosX = 20;
			break;
		case 3:
			intBlockPosY = 11;
			intBlockPosX = 26;
			break;
		case 4:
			intBlockPosY = 11;
			intBlockPosX = 35;
			break;
		case 5:
			intBlockPosY = 14;
			intBlockPosX = 5;
			break;
		case 6:
			intBlockPosY = 17;
			intBlockPosX = 5;
			break;
		case 7:
			intBlockPosY = 23;
			intBlockPosX = 38;
			break;
		case 8:
			intBlockPosY = 26;
			intBlockPosX = 14;
			break;
		case 9:
			intBlockPosY = 26;
			intBlockPosX = 29;
			break;
		case 10:
			intBlockPosY = 26;
			intBlockPosX = 38;
			break;
		}
		intFloor[intBlockPosY][intBlockPosX] = 3;
		intFloor[intBlockPosY][intBlockPosX - 1] = 3;
		intFloor[intBlockPosY][intBlockPosX - 2] = 3;
		intFloor[intBlockPosY - 1][intBlockPosX] = 3;
		intFloor[intBlockPosY - 1][intBlockPosX - 1] = 4;
		intFloor[intBlockPosY - 1][intBlockPosX - 2] = 3;
		intFloor[intBlockPosY - 2][intBlockPosX] = 3;
		intFloor[intBlockPosY - 2][intBlockPosX - 1] = 3;
		intFloor[intBlockPosY - 2][intBlockPosX - 2] = 3;
	}

	//Finish
	intBlockPosY = 20;
	intBlockPosX = 23;
	intFloor[intBlockPosY][intBlockPosX] = 9;
	intFloor[intBlockPosY][intBlockPosX - 1] = 9;
	intFloor[intBlockPosY][intBlockPosX - 2] = 9;
	intFloor[intBlockPosY - 1][intBlockPosX] = 9;
	intFloor[intBlockPosY - 1][intBlockPosX - 1] = 9;
	intFloor[intBlockPosY - 1][intBlockPosX - 2] = 9;
	intFloor[intBlockPosY - 2][intBlockPosX] = 9;
	intFloor[intBlockPosY - 2][intBlockPosX - 1] = 9;
	intFloor[intBlockPosY - 2][intBlockPosX - 2] = 9;
	
	return 0;
}


int PrintMap()
{
	
	for (intFloorY = 0; intFloorY < 33; intFloorY++) {
		for (intFloorX = 0; intFloorX < 46; intFloorX++) {
			if (intFloor[intFloorY][intFloorX] == 1) {
				printf("X");
			}
			else if (intFloor[intFloorY][intFloorX] == 2) {
				printf(".");
			}
			else if (intFloor[intFloorY][intFloorX] == 3) {
				printf("#");
			}
			else if (intFloor[intFloorY][intFloorX] == 4) {
				printf(" ");
			}
			else if (intFloor[intFloorY][intFloorX] == 5) {
				printf("/");
			}
			else if (intFloor[intFloorY][intFloorX] == 6) {
				printf("\\");
			}
			else if (intFloor[intFloorY][intFloorX] == 7) {
				printf("|");
			}
			else if (intFloor[intFloorY][intFloorX] == 8) {
				printf("O");
			}
			else if (intFloor[intFloorY][intFloorX] == 9) {
				printf("$");
			}
		}
		printf("\n");
	}

	printf("Score: %d\n", intMoveNum);

	return 0;
}


int Move()
{


	// \O/
	//  |
	// / \
		
	char strMove[10];
	char strMoveCheck[6][10];
	int intHeadX = CurrentPosX;
	int intHeadY = CurrentPosY - 2;
	int intBodyX = CurrentPosX;
	int intBodyY = CurrentPosY - 1;
	int intUnderArm1X = CurrentPosX - 1;
	int intUnderArm1Y = CurrentPosY - 1;
	int intUnderArm2X = CurrentPosX + 1;
	int intUnderArm2Y = CurrentPosY - 1;
	int intLeftLegX = CurrentPosX - 1;
	int intLeftLegY = CurrentPosY;
	int intRightLegX = CurrentPosX + 1;
	int intRightLegY = CurrentPosY;
	int intLeftArmX = CurrentPosX - 1;
	int intLeftArmY = CurrentPosY - 2;
	int intRightArmX = CurrentPosX + 1;
	int intRightArmY = CurrentPosY - 2;
	int intOldHeadX = intHeadX;
	int intOldBodyX = intBodyX;
	int intOldUnderArm1X = intUnderArm1X;
	int intOldUnderArm1Y = intUnderArm1Y;
	int intOldUnderArm2X = intUnderArm2X;
	int intOldUnderArm2Y = intUnderArm2Y;
	int intOldLeftLegX = intLeftLegX;
	int intOldRightLegX = intRightLegX;
	int intOldLeftArmX = intLeftArmX;
	int intOldRightArmX = intRightArmX;
	int intOldHeadY = intHeadY;
	int intOldBodyY = intBodyY;
	int intOldLeftLegY = intLeftLegY;
	int intOldRightLegY = intRightLegY;
	int intOldLeftArmY = intLeftArmY;
	int intOldRightArmY = intRightArmY;

	


	printf("--> ");

	scanf("%s", &strMove);


	strcpy(strMoveCheck[0], "w");
	strcpy(strMoveCheck[1], "s");
	strcpy(strMoveCheck[2], "a");
	strcpy(strMoveCheck[3], "d");
	strcpy(strMoveCheck[4], "v");
	strcpy(strMoveCheck[5], strMove);


	OldPosY = CurrentPosY;
	OldPosX = CurrentPosX;
	
	if (strcmp(strMoveCheck[5], strMoveCheck[0]) == 0) {
		
		if (intFloor[CurrentPosY - 3][CurrentPosX] == 3 || intFloor[CurrentPosY - 3][CurrentPosX] == 1 || intFloor[CurrentPosY - 3][CurrentPosX] == 4) {
			printf("You can't move there.\n");
		}
		else {
			CurrentPosY -= 3;
			intHeadY -= 3;
			intBodyY -= 3;
			intLeftLegY -= 3;
			intRightLegY -= 3;
			intLeftArmY -= 3;
			intRightArmY -= 3;
			intUnderArm1Y -= 3;
			intUnderArm2Y -= 3;
			intMoveNum++;
		}

	}
	else if (strcmp(strMoveCheck[5], strMoveCheck[1]) == 0) {
		if (intFloor[CurrentPosY + 3][CurrentPosX] == 3 || intFloor[CurrentPosY + 3][CurrentPosX] == 1 || intFloor[CurrentPosY + 3][CurrentPosX] == 4) {
			printf("You can't move there.\n");
		}
		else {
			CurrentPosY += 3;
			intHeadY += 3;
			intBodyY += 3;
			intLeftLegY += 3;
			intRightLegY += 3;
			intLeftArmY += 3;
			intRightArmY += 3;
			intUnderArm1Y += 3;
			intUnderArm2Y += 3;
			intMoveNum++;
		}
	}
	else if (strcmp(strMoveCheck[5], strMoveCheck[2]) == 0) {
		if (intFloor[CurrentPosY][CurrentPosX - 3] == 3 || intFloor[CurrentPosY][CurrentPosX - 3] == 1 || intFloor[CurrentPosY][CurrentPosX - 3] == 4) {
			printf("You can't move there.\n");
		}
		else {
			CurrentPosX -= 3;
			intHeadX -= 3;
			intBodyX -= 3;
			intLeftLegX -= 3;
			intRightLegX -= 3;
			intLeftArmX -= 3;
			intRightArmX -= 3;
			intUnderArm1X -= 3;
			intUnderArm2X -= 3;
			intMoveNum++;
		}
	}
	else if (strcmp(strMoveCheck[5], strMoveCheck[3]) == 0) {
		if (intFloor[CurrentPosY][CurrentPosX + 3] == 3 || intFloor[CurrentPosY][CurrentPosX + 3] == 1 || intFloor[CurrentPosY][CurrentPosX + 3] == 4) {
			printf("You can't move there.\n");
		}
		else {
			CurrentPosX += 3;
			intHeadX += 3;
			intBodyX += 3;
			intLeftLegX += 3;
			intRightLegX += 3;
			intLeftArmX += 3;
			intRightArmX += 3;
			intUnderArm1X += 3;
			intUnderArm2X += 3;
			intMoveNum++;
		}
	}
	else if (strcmp(strMoveCheck[5], strMoveCheck[4]) == 0) {
		intGame = 0;
	}


	intFloor[OldPosY][OldPosX] = 4;
	intFloor[intOldLeftArmY][intOldLeftArmX] = 4;
	intFloor[intOldRightArmY][intOldRightArmX] = 4;
	intFloor[intOldUnderArm1Y][intOldUnderArm1X] = 4;
	intFloor[intOldUnderArm2Y][intOldUnderArm2X] = 4;
	intFloor[intOldRightLegY][intOldRightLegX] = 4;
	intFloor[intOldLeftLegY][intOldLeftLegX] = 4;
	intFloor[intOldBodyY][intOldBodyX] = 4;
	intFloor[intOldHeadY][intOldHeadX] = 4;
	intFloor[CurrentPosY][CurrentPosX] = 4;
	intFloor[intLeftArmY][intLeftArmX] = 6;
	intFloor[intRightArmY][intRightArmX] = 5;
	intFloor[intUnderArm1Y][intUnderArm1X] = 4;
	intFloor[intUnderArm2Y][intUnderArm2X] = 4;
	intFloor[intRightLegY][intRightLegX] = 6;
	intFloor[intLeftLegY][intLeftLegX] = 5;
	intFloor[intBodyY][intBodyX] = 7;
	intFloor[intHeadY][intHeadX] = 8;

	return 0;
}

int Winner()
{
	if (CurrentPosX == 22 && CurrentPosY == 20) {

		printf("***************************************\n");
		printf("*           CONGRATULATIONS!          *\n");
		printf("*             YOU DID IT!             *\n");
		printf("***************************************\n");
	}
	else {
		printf("******************************************\n");
		printf("*                 ALMOST!                *\n");
		printf("* You didn't finish on the correct spot! *\n");
		printf("******************************************\n");
	}

	return 0;
}