#include "Menu.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <string>

using namespace std;


Menu::Menu()
{
	g = new Gameplay(4,4);
}

Menu::~Menu()
{
	delete g;
}

void Menu::showMenu()
{
	vector<string> el = { "Play", "Players", "Score","Exit" };
	for (int i = 0; i < el.size(); i++)
	{
		cout << el[i] << endl;
	}
	int c = 0;
	while (true)
	{
		switch (_getch())
		{
		case 72:
			system("cls");
			c = c - 1;
			if (c == -1)
			{
				c = 3;
			}
			for (int i = 0; i < el.size(); i++)
			{
				if (i == c)
				{
					cout << "->" + el[i] << endl;
				}
				else
				{
					cout << el[i] << endl;
				}
			}
			break;
		case 80:
			system("cls");
			c = c + 1;
			if (c == 4)
			{
				c = 0;
			}
			for (int i = 0; i < el.size(); i++)
			{
				if (i == c)
				{
					cout << "->" + el[i] << endl;
				}
				else
				{
					cout << el[i] << endl;
				}
			}
			break;
		case 13: //ENTER
			switch (c)
			{
			case 0:
				play();
				break;
			case 1:
				players();
				break;
			case 2:
				score();
				break;
			case 3:
				exit(0);
				break;
			}
		}
	}
}

void Menu::score()
{
	system("cls");
	cout << "Score:" << endl;
}

void Menu::players()
{
	system("cls");
	cout << "Players:" << endl;
}

void Menu::play()
{
	system("cls");
	g->play();
}
