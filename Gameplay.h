#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "Field.h"

class Gameplay
{
private:
	Field * f;
public:
	Gameplay();
	Gameplay(int, int);
	~Gameplay();

	void play();
	void addEl();
	bool lose();
	bool add(int);
	void writeChange();
};

#endif // !GAMEPLAY_H