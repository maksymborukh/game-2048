#pragma once
#ifndef FIELD_H
#define FIELD_H

class Field
{
protected:
	int height;
	int width;
	int heightF;
	int widthF;
	int **matrix;
	char **field;
public:
	Field();
	Field(int, int);
	~Field();

	void fillMatrix();
	void createField();
	void printField();
	void setElField(int, int, char);

	void setElMatr(int, int, int);
	void printMatrix();
	int getElMatr(int, int);
	int getHeight();
	int getWidth();
};

#endif // !Field