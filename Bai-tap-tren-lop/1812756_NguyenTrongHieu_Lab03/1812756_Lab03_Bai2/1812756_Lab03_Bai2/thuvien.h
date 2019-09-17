#define MAX 100

struct Date
{
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct Name
{
	char ho[11];
	char tLot[11];
	char ten[11];
};

struct NhanVien
{
	char maNV[8];
	Name name;
	Date date;
	char diaChi[16];
	unsigned int luong;
};

typedef NhanVien Data;

struct tagNode
{
	Data info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};

void CreateEmptyList(LIST& ls)
{
	ls.pHead = ls.pTail = NULL;
}

NODE* CreateNode(Data data)
{
	NODE* p = new NODE;

	if (p)
	{
		p->info = data;
		p->pNext = NULL;
	}

	return p;
}

bool IsEmptyList(LIST ls)
{
	return ls.pHead == NULL;
}

void Insert_Tail(LIST& ls, NODE* node)
{
	if (IsEmptyList(ls))
	{
		ls.pHead = node;
		ls.pTail = node;
	}
	else
	{
		ls.pTail->pNext = node;
		ls.pTail = node;
	}
}

int GetDataFromFile(char* filename, LIST& ls)
{
	ifstream input(filename);
	NODE* p;
	Data nhanvien;

	if (!input)
		return 0; // Loi doc file

	while (!input.eof())
	{

		input >> nhanvien.maNV;
		input >> nhanvien.name.ho;
		input >> nhanvien.name.tLot;
		input >> nhanvien.name.ten;
		input >> nhanvien.date.ngay;
		input >> nhanvien.date.thang;
		input >> nhanvien.date.nam;
		input >> nhanvien.diaChi;
		input >> nhanvien.luong;

		p = CreateNode(nhanvien);
		if (!p)
		{
			cout << "\nLoi cap phat vung nho!\n";
			exit(-1);
		}

		Insert_Tail(ls, p);
	}

	input.close();
	return 1;
}

void XuatDuongKe(char kitu)
{
	const int chieuDai = 89;
	cout << '|';
	for (int i = 0; i < chieuDai; i++)
		cout << kitu;
	cout << '|' << endl;
}

void XuatTieuDe()
{
	XuatDuongKe('=');
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << "Ma NV"
		<< '|' << setw(11) << "Ho"
		<< setw(11) << "tLot"
		<< setw(11) << "Ten"
		<< '|' << setw(13) << "NTN Sinh"
		<< '|' << setw(16) << "Dia chi"
		<< '|' << setw(13) << "Luong";
	cout << '|' << endl;
	XuatDuongKe('=');
}

void Xuat_1_NV(Data &nv)
{
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << nv.maNV
		<< '|' << setw(11) << nv.name.ho
		<< setw(11) << nv.name.tLot
		<< setw(11) << nv.name.ten
		<< '|' << setw(2) << nv.date.ngay
		<< '/' << setw(2) << nv.date.thang
		<< '/' << setw(7) << nv.date.nam
		<< '|' << setw(16) << nv.diaChi
		<< '|' << setw(13) << nv.luong;
	cout << '|' << endl;
}

void Xuat_DS_NV(LIST ls)
{
	XuatTieuDe();

	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach hien tai rong\n";
		return;
	}

	NODE* node = ls.pHead;
	int i = 1;

	while (node)
	{
		Xuat_1_NV(node->info);
		i++; // Cach 3 dong xuat 1 duong ke don '-------------------'
		if (i % 3 == 0)
			XuatDuongKe('-');
		node = node->pNext;
	}

	XuatDuongKe('=');
}

NODE* Get_Final_Employee_With_Name(LIST ls, char name[])
{

	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return NULL;
	}

	NODE* kq, * p;

	kq = NULL;
	p = ls.pHead;

	while (p)
	{
		if (strcmp(p->info.name.ten, name) == 0)
			kq = p;
		p = p->pNext;
	}

	return kq;
}

NODE* Get_First_Employee_With_Name(LIST ls, char name[])
{

	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return NULL;
	}

	NODE* p;
	p = ls.pHead;

	while (p)
	{
		if (strcmp(p->info.name.ten, name) == 0)
			return p;
		p = p->pNext;
	}

	return p;
}

NODE* Max_Salary(LIST ls)
{
	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return NULL;
	}

	NODE* kq, * p;

	kq = ls.pHead;
	p = ls.pHead->pNext;

	while (p)
	{
		if (kq->info.luong < p->info.luong)
			kq = p;
		p = p->pNext;
	}

	return kq;
}

LIST Filter_Employee(LIST ls, unsigned int luong)
{
	LIST kq;
	CreateEmptyList(kq);
	
	if (!IsEmptyList(ls))
	{
		NODE* p, *node;
		p = ls.pHead;

		while (p)
		{
			if (p->info.luong >= luong)
			{
				node = CreateNode(p->info);
				Insert_Tail(kq, node);
			}
			p = p->pNext;
		}
	}

	return kq;
}

int Get_List_Length(LIST ls)
{
	if (IsEmptyList(ls)) return 0;
	int i = 0;

	NODE* p;
	p = ls.pHead;

	while (p)
	{
		i++;
		p = p->pNext;
	}

	return i;
}

int Count_Salary_Greater_Than(LIST ls, unsigned int luong)
{
	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return -1;
	}

	int count;
	NODE* p;

	count = 0;
	p = ls.pHead;

	while (p)
	{
		if (p->info.luong >= luong) count++;
		p = p->pNext;
	}

	return count;
}

NODE* Search_Node_Before(LIST ls, NODE* cur)
{
	if (IsEmptyList(ls)) return NULL;
	NODE* prev, *p;

	prev = NULL;
	p = ls.pHead;

	while (p)
	{
		if (p == cur)
			break;
		prev = p;
		p = p->pNext;
	}
	
	return prev;
}

/*
 NODE* Remove_Node(LIST &ls, NODE* p)
{
	 if (IsEmptyList(ls)) return NULL;
	 NODE* t;

	 // P la node dau
	 if (p == ls.pHead)
	 {
		 ls.pHead = ls.pHead->pNext;
		 delete p;
		 return ls.pHead;
	 }

	 t = Search_Node_Before(ls, p);
	 t->pNext = p->pNext;
	 delete p;

	 // P la node cuoi
	 if (t->pNext == NULL)
		 ls.pTail = t;

	 return t;
}
*/

 bool IsAddressExist(LIST ls, char diaChi[])
 {
	 NODE* p;
	 p = ls.pHead;

	 while (p)
	 {
		 if (strcmp(p->info.diaChi, diaChi) == 0)
			 return true;
		 p = p->pNext;
	 }
	 return false;
 }

 LIST Xoa_TatCa_NODE_Co_DiaChi(LIST ls, char diaChi[])
 {
	 LIST kq;
	 CreateEmptyList(kq);

	 if (!IsEmptyList(ls))
	 {
		 NODE* p, *node;
		 p = ls.pHead;

		 while (p)
		 {
			 if (strcmp(p->info.diaChi, diaChi) != 0)
			 {
				 node = CreateNode(p->info);
				 Insert_Tail(kq, node);
			 }
			 p = p->pNext;
		 }
	 }

	 return kq;
 }

 LIST Remove_Node(LIST ls, NODE *node)
 {
	 LIST list;
	 CreateEmptyList(list);

	 if (!IsEmptyList(ls))
	 {
		 NODE* p, * t;
		 p = ls.pHead;

		 while (p)
		 {
			 if (p != node)
			 {
				 t = CreateNode(p->info);
				 Insert_Tail(list, t);
			 }
			 p = p->pNext;
		 }
	 }

	 return list;
 }

 void Swap(NODE** a, NODE** b)
 {
	 NODE** c;
	 c = a;
	 a = b;
	 b = c;
 }

 LIST Get_List_Coppy(LIST src)
 {
	 LIST new_list;
	 CreateEmptyList(new_list);

	 if (!IsEmptyList(src))
	 {
		 NODE* p = src.pHead;
		 while (p)
		 {
			 NODE* t = CreateNode(p->info);
			 Insert_Tail(new_list, t);
		 }
	 }

	 return new_list;
 }


