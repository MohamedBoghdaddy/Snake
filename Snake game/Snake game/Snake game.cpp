// Snake game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <windows.h>



using namespace std;
bool gameOver;
const int width = 40;
const int height = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int ntail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitx = rand() % width;
	fruity = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");

	for (int i = 0; i < width + 2; i++)

		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruity && j == fruitx)
				cout << "$";
			else
			{
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{

					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						print = true;
					}

				}
				if (!print)
					cout << " ";
			}

			if (j == width - 1)
				cout << "#";
		}
		cout << endl;

	}

	for (int i = 0; i < width + 2; i++)

		cout << "#";
	cout << endl;
	cout << "SCORE: " << score << endl;

}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
		break; case 'w':
			dir = UP;
		break; case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
void Logic()
{

	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < ntail; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
		//gameOver = true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) x = height - 1;

	for (int i = 0; i < ntail; i++)
		if (tailx[i] == x && taily[i] == y)
			gameOver = true;
	if (x == fruitx && y == fruity)
	{
		score += 10;
		fruitx = rand() % width;
		fruity = rand() % height;
		ntail++;
	}
}


int main()
{
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(40);

	}

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
