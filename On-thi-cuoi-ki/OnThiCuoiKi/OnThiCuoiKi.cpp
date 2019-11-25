#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "cautruc.h"
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
	LIST l;
	int somenu = 20;
	int menu;
	char filename[10];
	
	TaoDSRong(l);
	do
	{
		cout << "\nNhap vao ten tap tin de mo: ";
		cin >> filename;

		if (TaoDSNhanVien(l, filename))
			break;

		cout << "\nKhong the mo tap tin '" << filename << "'! Vui long kiem tra lai ten tap tin!";
	}
	while (l.pHead == NULL);
	
	do
	{
		system("cls");
		menu = ChonMenu(somenu);
		XuLyMenu(l, menu);
	}
	while (menu > 0);
	
}
