#pragma once
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
#include "Field.h"
class Gameplay
{
private:
	Field *f = new Field(4, 4);
public: //must be protected
	void addEl();
	~Gameplay();
};

#endif // !GAMEPLAY_H