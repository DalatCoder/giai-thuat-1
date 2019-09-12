#include <iostream>
#include <fstream>

using namespace std;

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
	int menu, soMenu = 15;
	LIST ls;
	CreateEmptyList(ls); // Khoi tao danh sach trong

	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, ls);
	} while (menu > 0);
}