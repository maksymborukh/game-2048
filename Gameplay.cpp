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
	addEl();
	f->printField();
	
	while (true)
	{
		switch (_getch())
		{
		case 72: //UP
			if (!lose())
			{
				if (add(72))
				{
					system("cls");
					addEl();
					writeChange();
					f->printField();
				}
			}
			else
			{
				std::cout << "lose";
			}
			break;
		case 80: //DOWN
			if (!lose())
			{
				if (add(80))
				{
					system("cls");
					addEl();
					writeChange();
					f->printField();
				}
			}
			else
			{
				std::cout << "lose";
			}
			break;
		case 75: //LEFT
			if (!lose())
			{
				if (add(75))
				{
					system("cls");
					addEl();
					writeChange();
					f->printField();
				}
			}
			else
			{
				std::cout << "lose";
			}
			break;
		case 77: //RIGHT
			if (!lose())
			{
				if (add(77))
				{
					system("cls");
					addEl();
					writeChange();
					f->printField();
				}
			}
			else
			{
				std::cout << "lose";
			}
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


	block = rand() % 2 + 1;
	positionH = rand() % f->getHeight();
	positionW = rand() % f->getWidth();
	while (f->getElMatr(positionH, positionW) != 0)
	{
		block = rand() % 2 + 1;
		positionH = rand() % f->getHeight();
		positionW = rand() % f->getWidth();

	}
	f->setElMatr(positionH, positionW, block * 2);

	string r = std::to_string(f->getElMatr(positionH, positionW));
	f->setElField(positionH * 5 + 3, positionW * 12 + 5, r[0]);

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
//need to rewrite

bool Gameplay::add(int c)
{
	bool b = false;
	int elij;
	int elij1;
	int index;
	int s = 0;
	switch (c)
	{
	case 72://UP
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = 0; j < f->getWidth() - 1; j++)
			{
				elij = f->getElMatr(j, i);
				if (elij != 0)
				{
					for (int k = j + 1; k < f->getWidth(); k++)
					{
						elij1 = f->getElMatr(k, i);
						if (elij1 != 0)
						{
							if (elij == elij1)
							{
								f->setElMatr(j, i, elij + elij1);
								f->setElMatr(k, i, 0);
								b = true;
							}
							k = f->getWidth();
						}
					}
				}
			}
		}

		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = 0; j < f->getWidth(); j++)
			{
				elij = f->getElMatr(j, i);
				if ((s != 1) && (elij == 0))
				{
					index = j;
					j = index;
					s = 1;
				}
				if ((s == 1) && (elij != 0))
				{
					f->setElMatr(index, i, elij);
					f->setElMatr(j, i, 0);
					if (j != f->getWidth() - 1)
					{
						j = 0;
					}
					b = true;
					s = 0;
				}

			}
			s = 0;
		}
		break;
	case 75://LEFT
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = 0; j < f->getWidth() - 1; j++)
			{
				elij = f->getElMatr(i, j);
				if (elij != 0)
				{
					for (int k = j + 1; k < f->getWidth(); k++)
					{
						elij1 = f->getElMatr(i, k);
						if (elij1 != 0)
						{
							if (elij == elij1)
							{
								f->setElMatr(i, j, elij + elij1);
								f->setElMatr(i, k, 0);
								b = true;
							}
							k = f->getWidth();
						}
					}
				}
			}
		}
		
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = 0; j < f->getWidth(); j++)
			{
				elij = f->getElMatr(i, j);
				if ((s != 1) && (elij == 0))
				{
					index = j;
					j = index;
					s = 1;
				}
				if ((s == 1) && (elij != 0))
				{
					f->setElMatr(i, index, elij);
					f->setElMatr(i, j, 0);
					if (j != f->getWidth() - 1)
					{
						j = 0;
					}
					b = true;
					s = 0;
				}
				
			}
			s = 0;
		}
		/*
			for (int i = 0; i < f->getHeight(); i++)
			{
				for (int j = 0; j < f->getWidth() - 1; j++)
				{
					elij = f->getElMatr(i, j);
					elij1 = f->getElMatr(i, j + 1);
					if ((elij != 0) && (elij == elij1))
					{
						f->setElMatr(i, j, elij + elij1);
						f->setElMatr(i, j + 1, 0);
						b = true;
					}
				}
			}
		}*/
		break;
	case 77: //RIGHT
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = f->getWidth() - 1; j >= 0; j--)
			{
				elij = f->getElMatr(i, j);
				if (elij != 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						elij1 = f->getElMatr(i, k);
						if (elij1 != 0)
						{
							if (elij == elij1)
							{
								f->setElMatr(i, j, elij + elij1);
								f->setElMatr(i, k, 0);
								b = true;
							}
							k = -1;
						}
					}
				}
			}
		}
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = f->getWidth() - 1; j >= 0; j--)
			{
				elij = f->getElMatr(i, j);

				if ((s == 1) && (elij != 0))
				{
					f->setElMatr(i, index, elij);
					f->setElMatr(i, j, 0);
					if (j != 0)
					{
						j = f->getWidth() - 1;
					}
					b = true;
					s = 0;
				}
				if ((elij == 0) && (s != 1))
				{
					index = j;
					j = index;
					s = 1;
				}
			}
			s = 0;
		}
		break;
	case 80://DOWN
		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = f->getWidth() - 1; j >= 0; j--)
			{
				elij = f->getElMatr(j, i);
				if (elij != 0)
				{
					for (int k = j - 1; k >= 0; k--)
					{
						elij1 = f->getElMatr(k, i);
						if (elij1 != 0)
						{
							if (elij == elij1)
							{
								f->setElMatr(j, i, elij + elij1);
								f->setElMatr(k, i, 0);
								b = true;
							}
							k = -1;
						}
					}
				}
			}
		}

		for (int i = 0; i < f->getHeight(); i++)
		{
			for (int j = f->getWidth() - 1; j >= 0; j--)
			{
				elij = f->getElMatr(j, i);
				if ((s != 1) && (elij == 0))
				{
					index = j;
					j = index;
					s = 1;
				}
				if ((s == 1) && (elij != 0))
				{
					f->setElMatr(index, i, elij);
					f->setElMatr(j, i, 0);
					if (j != f->getWidth() - 1)
					{
						j = f->getWidth() - 1;
					}
					b = true;
					s = 0;
				}

			}
			s = 0;
		}
		break;
	default:
		break;
	}
	return b;
}

void Gameplay::writeChange()
{
	f->createField();
	string r;
	int len;
	for (int i = 0; i < f->getHeight(); i++)
	{
		for (int j = 0; j < f->getWidth(); j++)
		{

			r = std::to_string(f->getElMatr(i, j));
			len = r.length();
			if (f->getElMatr(i, j) != 0)
			{
				int position = len / 2;
				for (int k = 0; k < len + 1; k++)
				{

					f->setElField(i * 5 + 3, j * 12 + 5 - position + k, r[k]);
				}
			}
		}
	}
}
