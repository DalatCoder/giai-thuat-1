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
	char filename[50];
	int kq;

	CreateBST(root);

	while (true)
	{
		system("cls");
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;

		kq = GetDataFromFile(filename, root);

		if (kq == 0) cout << "\nMo tap tin " << filename << " khong thanh cong!\n";
		else break;

		system("pause");

	}

	cout << "\nMo tap tin " << filename << " thanh cong!\n";
	cout << "\nCay hien tai: \n";
	InOrder(root);

	do
	{
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, root);
	} while (menu > 0);
}
