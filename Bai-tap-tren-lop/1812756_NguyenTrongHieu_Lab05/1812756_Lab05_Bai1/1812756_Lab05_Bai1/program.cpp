#include <iostream>
#include <fstream>

using namespace std;

#include "bnstree.h"
#include "thuvien.h"
#include "menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
	return 0;
}

void ChayChuongTrinh()
{
	BSTree root = nullptr;
	int menu, soMenu = 13;
	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu > 0);
}
