
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

NODE* TimTenNV(LIST list, char ten[]);
int TimViTriNODE(LIST list, NODE* node);
NODE* TimNVLuongCaoNhat(LIST list);

int DemTheoLuong(LIST list, double luong);
void XuatNVLuongLonHonX(LIST list, double luong);

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
	cout << nv.MaNV << '\t' << nv.Ho << '\t' << nv.TenLot << '\t' << nv.Ten << '\t' << nv.Ngay << '/' << nv.Thang << '/' << nv.Nam << '\t' << nv.DiaChi << '\t' << setiosflags(ios::fixed) << setprecision(2) << nv.Luong;
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

NODE* TimTenNV(LIST list, char ten[])
{
	NODE* result = NULL;

	NODE* p;

	p = list.pHead;

	while (p != NULL)
	{
		if (strcmp(p->info.Ten, ten) == 0)
			result = p;
			
		p = p->pNext;
	}
	
	return result;
}

int TimViTriNODE(LIST list, NODE *node)
{
	int i = 1;

	NODE* p = list.pHead;

	while (p != NULL && p != node)
	{
		i++;
		p = p->pNext;
	}

	if (p == NULL)
		return -1;

	return i;
}

NODE* TimNVLuongCaoNhat(LIST list)
{
	NODE* res = list.pHead;
	NODE* p = list.pHead;

	while (p != NULL)
	{
		if (res->info.Luong < p->info.Luong)
			res = p;

		p = p->pNext;
	}

	return res;
}

int DemTheoLuong(LIST list, double luong)
{
	int dem = 0;
	NODE* p = list.pHead;

	while (p != NULL)
	{
		if (p->info.Luong >= luong)
			dem++;

		p = p->pNext;
	}

	return dem;
}

void XuatNVLuongLonHonX(LIST list, double luong)
{
	LIST res;
	TaoDSRong(res);

	NODE* p = list.pHead;

	while (p != NULL)
	{
		if (p->info.Luong >= luong)
		{
			NODE* new_node = TaoNODE(p->info);
			ChenNODECuoi(res, new_node);
		}

		p = p->pNext;
	}

	if (KiemTraDSRong(res) == true)
		cout << "\nKhong tim thay nhan vien co muc luong >= " << luong << endl;
	else
	{
		cout << "\nTim thay " << DemTheoLuong(list, luong) << " nhan vien co muc luong >= " << luong;
		cout << "\nDanh sach nhan vien chi tiet:\n";
		XuatDS(res);
	}
}
