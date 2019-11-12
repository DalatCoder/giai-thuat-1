
struct NhanVien
{
	char MaNV[8]; // '\0'
	char Ho[11];
	char TenLot[11];
	char Ten[11];
	int Ngay;
	int Thang;
	int Nam;
	char DiaChi[16];
	double Luong;
};

struct NODE
{
	NhanVien info;
	NODE* pNext;
};

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};


//////////////////////////////////////////////////////
/// NGUYEN MAU HAM 
//////////////////////////////////////////////////////

void TaoDSRong(LIST& list);
NODE* TaoNODE(NhanVien nv);
int KiemTraDSRong(LIST list);
void ChenNODECuoi(LIST& list, NODE* p);
int TaoDSTuFile(LIST& list, char tenFile[]);

void Xuat1NV(NhanVien nv);
void XuatDS(LIST list);


//////////////////////////////////////////////////////
/// DINH NGHIA HAM
//////////////////////////////////////////////////////

void TaoDSRong(LIST& list)
{
	list.pHead = NULL;
	list.pTail = NULL;
}

NODE* TaoNODE(NhanVien nv)
{
	NODE* p = new NODE;

	if (p != NULL)
	{
		p->info = nv;
		p->pNext = NULL;
	}

	return p;
}

int KiemTraDSRong(LIST list)
{
	return list.pHead == NULL;
}

void ChenNODECuoi(LIST& list, NODE* p)
{
	if (KiemTraDSRong(list) == true)
	{
		list.pHead = p;
		list.pTail = p;
	}
	else
	{
		list.pTail->pNext = p;
		list.pTail = p;
	}
}

int TaoDSTuFile(LIST& list, char tenFile[])
{
	ifstream input(tenFile);

	if (!input)
		return 0; // Mo file khong thanh cong

	// Khoi tao danh sach rong
	TaoDSRong(list);
	
	NODE* p;
	NhanVien nv;
	char ch;

	while(!input.eof())
	{
		input >> nv.MaNV;
		input >> nv.Ho;
		input >> nv.TenLot;
		input >> nv.Ten;
		input >> nv.Ngay; //     11/03/2000
		input >> ch;
		input >> nv.Thang;
		input >> ch;
		input >> nv.Nam;
		input >> nv.DiaChi;
		input >> nv.Luong;

		p = TaoNODE(nv);
		if (p == NULL)
			exit(-1);

		ChenNODECuoi(list, p);
	}

	input.close();
	return 1; // Mo file thanh cong
}

void Xuat1NV(NhanVien nv)
{
	cout << nv.MaNV << '\t' << nv.Ho << '\t' << nv.TenLot << '\t' << nv.Ten << '\t' << nv.Ngay << '/' << nv.Thang << '/' << nv.Nam << '\t' << nv.DiaChi << '\t' << nv.Luong;
	cout << endl;
}

void XuatDS(LIST list)
{
	NODE* p;

	p = list.pHead;

	cout << endl;
	while (p != NULL)
	{
		Xuat1NV(p->info);
		p = p->pNext;
	}
	cout << endl;
}


