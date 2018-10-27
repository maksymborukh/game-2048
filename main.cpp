#include <iostream>
#include "Menu.h"

using namespace std;

int main()
{
	Menu *game = new Menu;
	game->showMenu();
	delete game;
	system("pause");
	return 0;
}