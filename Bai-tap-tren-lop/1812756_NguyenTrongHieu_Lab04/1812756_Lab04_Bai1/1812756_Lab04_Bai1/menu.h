void XuatMenu()
{
	cout << "\nHe thong chuc nang\n";
	cout << "\n1. Them mot node o dau stack.";
	cout << "\n2. Huy mot node o dau stack.";
	cout << "\n3. Dem so lan xuat hien cua X trong stack.";
	cout << "\n4. Xoa toan bo nhung node co du lieu X trong stack.";
	cout << "\n5. Xem du lieu.";
	cout << "\n0. Thoat chuong trinh.";
}

int ChonMenu(int soMenu)
{
	int chon;

	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nChon chuc nang trong khoang: [1.." << soMenu << "] >> ";
		cin >> chon;

		if (0 <= chon && chon <= soMenu)
			break;
	}

	return chon;
}

void XuLyMenu(int menu, Stack &s)
{
	Data data;
	NODE *p;
	Stack res;

	switch (menu)
	{
	case 1:
		cout << "\n1. Them mot node o dau stack.";
		cout << "\nStack truoc khi chen 1 phan tu moi: ";
		DisplayStack(s);
		cout << "\nNhap vao 1 gia tri: ";
		cin >> data;

		p = CreateNode(data);
		InsertHead(s, p);

		cout << "\nStack sau khi chen 1 phan tu moi: ";
		DisplayStack(s);

		break;
	case 2:
		cout << "\n2. Huy mot node o dau stack.";
		cout << "\nStack ban dau: ";
		DisplayStack(s);

		RemoveHead(s);

		cout << "\nStack sau khi xoa 1 phan tu: ";
		DisplayStack(s);
		break;
	case 3:
		cout << "\n3. Dem so lan xuat hien cua X trong stack.";
		cout << "\nStack ban dau: ";
		DisplayStack(s);

		cout << "\nNhap phan tu can dem: ";
		cin >> data;

		cout << "\nSo lan xuat hien cua phan tu " << data << " trong danh sach: " << Count_X(s, data);
		break;
	case 4:
		cout << "\n4. Xoa toan bo nhung node co du lieu X trong stack.";
		cout << "\nStack ban dau: ";
		DisplayStack(s);

		cout << "\nNhap vao 1 phan tu: ";
		cin >> data;
		res = Remove_All_X(s, data);

		cout << "\nStack sau khi xoa tat ca phan tu bang X: ";
		DisplayStack(res);
		break;
	case 5:
		cout << "\n5. Xem du lieu.";
		cout << "\nStack hien tai: \n";
		DisplayStack(s);
		break;
	case 0:
		cout << "\n0. Thoat chuong trinh.";
		break;
	}

	cout << endl;
	system("pause");
}

