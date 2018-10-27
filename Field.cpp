#include "Field.h"
#include <iostream>

using namespace std;


Field::Field()
{
	height = 0;
	width = 0;
	heightF = height * 5 + 1;
	widthF = width * 12;

	matrix = new int *[height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new int[width];
	}
	field = new char *[heightF];
	for (int i = 0; i < heightF; i++)
	{
		field[i] = new char[widthF];
	}
	fillMatrix();
}

Field::Field(int h, int w)
{
	this->height = h;
	this->width = w;
	this->heightF = height * 5 + 1;
	this->widthF = width * 12;
	matrix = new int *[height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new int[width];
	}
	field = new char *[heightF];
	for (int i = 0; i < heightF; i++)
	{
		field[i] = new char[widthF];
	}
	fillMatrix();
}

void Field::fillMatrix()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Field::createField()
{
	int temp = 5;
	int temp1 = 11;
	for (int i = 0; i < heightF; i++)
	{
		for (int j = 0; j < widthF; j++)
		{
			if (i == 0)
			{
				field[i][j] = '_';
			}
			else if (i == temp)
			{
				field[i][j] = '_';
				if (j == widthF - 1)
				{
					temp = temp + 5;
				}
			}
			else
			{
				field[i][j] = ' ';
			}

			if (j == 0)
			{
				field[i][j] = '|';
			}
			else if (j == temp1)
			{
				field[i][j] = '|';
				temp1 = temp1 + 12;
			}
			if (i == 0)
			{
				field[i][j] = '_';
			}
		}
		temp1 = 11;
	}
}

void Field::printField()
{
	for (int i = 0; i < heightF; i++)
	{
		for (int j = 0; j < widthF; j++)
		{
			cout << field[i][j];
		}
		cout << endl;
	}
}

void Field::setElMatr(int h, int w, int n)
{
	matrix[h][w] = n;
}

void Field::printMatrix()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

void Field::setElField(int h, int w, char n)
{
	field[h][w] = n;
}

int Field::getElMatr(int h, int w)
{
	int t = matrix[h][w];
	return t;
}

int Field::getHeight()
{
	return height;
}

int Field::getWidth()
{
	return width;
}

Field::~Field()
{
	for (int i = 0; i < height; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	for (int i = 0; i < heightF; i++)
	{
		delete[] field[i];
	}
	delete[] field;

}
