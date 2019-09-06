void XuatMenu();
int ChonMenu(int somenu);
void XuLyMenu(int menu);

void XuatMenu()
{
	cout << "\n========= HE THONG CHUC NANG =========\n";
	cout << "\n1. Hello";
	cout << "\n2. World";
	cout << "\n0. Thoat chuong trinh";
}

int ChonMenu(int somenu)
{
	int menu;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang >> ";
		cin >> menu;

		if (0 <= menu && menu <= somenu)
			break;
	}

	return menu;
}

void XuLyMenu(int menu)
{
	switch (menu)
	{
		case 1:
			break;
		case 2:
			break;
		case 0:
			cout << "\nThoat chuong trinh!\n";
			break;
	}

	system("cls");
}

