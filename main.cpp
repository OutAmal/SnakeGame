#include <iostream>
#include <time.h>
#include<stdlib.h>
#include <vector>
#include<Windows.h>

using namespace std;


bool gameOver;
int height = 20, weight = 20; 
int xPos, yPos, xGold, yGold, score;
int  xtail[100], ytail[100];
int tailLength=1;


void setup() {
	//srand(time(0));
	gameOver = false;
	xPos = height / 2;
	yPos = weight / 2;
	xGold = 3;
	yGold = 7;
	
	
}
void draw() {
	int k;
	
	system("cls");
	for (int i = 1; i <= height; i++) {

		if (i == 1 || i == 20) {
			for (int j = 1; j <= weight; j++) {
				cout << "#";
			}; cout << endl;
		}
		else {
			for (int j = 1; j <= weight; j++) {
				if (j == 1 || j == 20) {
					cout << "#";
				}
				else { 
					
					if (i == xPos && j == yPos)
						cout << "S";
					

					else if (i == xGold && j == yGold)
						cout << "G";
					else { 
						bool isPrinted = false;
						for (int k = 0; k < tailLength;k++) {
							if (i == xtail[k] && j == ytail[k]) { 
								cout << "O";
								isPrinted = true;
							}
						}
						if (!isPrinted)
						{
							cout << " ";
						}
					}
				}
			};
			//cout << "#                                                        #" << endl; }
			cout << endl;
		}
		
	}
	cout << "Score " << score << endl;
	
}
void input() {
	//Check the mouse left button is pressed or not
	if ((GetKeyState(VK_LEFT) & 0x80) != 0)
	{
		
		yPos--;
		
	}
	//Check ifright button is pressed or not
	if ((GetKeyState(VK_RIGHT) & 0x80) != 0)
	{
		yPos++;
	}
	//Check IF UP button is pressed or not
	if ((GetKeyState(VK_UP) & 0x80) != 0)
	{
		xPos--;
	}
	if ((GetKeyState(VK_DOWN) & 0x80) != 0)
	{
		xPos++;
	}
	
	}
void logic() {
	int xprev = xtail[0];
	int yprev = ytail[0];
	int xprev2, yprev2;
	xtail[0] = xPos;
	ytail[0] = yPos;
	for (int i= 1; i < tailLength; i++) {
		xprev2 = xtail[i] ;
		yprev2 = ytail[i];
		xtail[i] = xprev;
		ytail[i] = yprev;
		xprev = xprev2;
		yprev = yprev2;
	}
	
	
	 
	/*for (int i = 1; i < tailLength; i++) {

		if (xtail[i] == xPos && ytail[i] == yPos) 
		{
			gameOver = true;
		}

	}*/

	if (xPos < 1 || xPos > height-1 || yPos < 1 || yPos> weight-1) {
		gameOver = true;
		
	}
	if (xPos == xGold && yPos == yGold) {
		srand(time(0));
		xGold = (rand() % (height-3)) +2;
		yGold = (rand() % (height - 3)) + 2;
		tailLength++;
		score++;
		
	}
	cout << tailLength;
}
int main() {
	
	setup();
	
	while (!gameOver) {
		
		logic();
        draw();
		input();
		Sleep(10);
		
	}
	cout << "game over!!!!!" << endl;
	cout << "your score is "<< score ;
	return 0;
}