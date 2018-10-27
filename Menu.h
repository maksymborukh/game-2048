#pragma once
#ifndef MENU_H
#define MENU_H

#include "Gameplay.h"

class Menu
{
	Gameplay* g;
public:
	Menu();
	~Menu();
	void showMenu();
	void score();
	void players();
	void play();
};

#endif // !MENU_H