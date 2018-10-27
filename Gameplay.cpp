#include "GamePlay.h"
#include "Field.h"
#include "Menu.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <conio.h>

using std::string;

Gameplay::Gameplay()
{
	f = new Field(0, 0);
}

Gameplay::Gameplay(int h, int w)
{
	f = new Field(h, w);
}

Gameplay::~Gameplay()
{
	delete f;
}

void Gameplay::play()
{
	Menu m;
	system("cls");
	f->createField();
	f->printField();
	
	
	while (true)
	{
		switch (_getch())
		{
		case 72: //UP
			if (!lose())
			{
				addEl();
			}
			else
			{
				std::cout << "lose";
			}
			system("cls");
			f->printField();
			break;
		case 80: //DOWN
			if (!lose())
			{
				addEl();
			}
			else
			{
				std::cout << "lose";
			}
			system("cls");
			f->printField();
			break;
		case 75: //LEFT
			if (!lose())
			{
				addEl();
			}
			else
			{
				std::cout << "lose";
			}
			system("cls");
			f->printField();
			break;
		case 77: //RIGHT
			if (!lose())
			{
				addEl();
			}
			else
			{
				std::cout << "lose";
			}
			system("cls");
			f->printField();
			break;
		case 27: //EXIT
			system("cls");
			m.showMenu();
			break;
		}
	}
}

void Gameplay::addEl()
{
	
	srand(time(0));

	int block;
	int positionH;
	int positionW;

	for (int i = 0; i < 2; i++)
	{
		block = rand() % 2 + 1;
		positionH = rand() % f->getHeight();
		positionW = rand() % f->getWidth();
		while(f->getElMatr(positionH, positionW) != 0)
		{
			block = rand() % 2 + 1;
			positionH = rand() % f->getHeight();
			positionW = rand() % f->getWidth();
			
		}
		f->setElMatr(positionH, positionW, block * 2);

		string r = std::to_string(f->getElMatr(positionH, positionW));
		f->setElField(positionH * 5 + 3, positionW * 12 + 5, r[0]);
		//int len = r.length();
		/*if (f->getElMatr(positionH, positionW) != 0)
		{
			int position = len / 2;
			for (int k = 0; k < len + 1; k++)
			{

				f->setElField(positionH * 5 + 3, positionW * 12 + 5 - position + k, r[k]);
			}
		}*/
	}
	
}

bool Gameplay::lose()
{
	for (int i = 0; i < f->getHeight(); i++)
	{
		for (int j = 0; j < f->getWidth(); j++)
		{
			if (f->getElMatr(i, j) == 0)
			{
				return false;
			}
		}
	}
	return true;
}