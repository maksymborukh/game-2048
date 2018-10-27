#include "GamePlay.h"
#include "Field.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using std::string;

void Gameplay::addEl()
{
	f->createField();//not here
	f->printField();// -||-


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
			positionH = rand() % f->getHeight() + 1;
			positionW = rand() % f->getWidth() + 1;
			
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
	f->printField();//-||-
	
}

Gameplay::~Gameplay()
{
	delete f;
}
