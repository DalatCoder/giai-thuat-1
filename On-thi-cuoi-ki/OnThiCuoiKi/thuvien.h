void TaoDSRong(LIST &l)
{
	l.pHead = l.pTail = NULL;
}

NODE*TaoNode(Data nv)
{
	NODE* node = new NODE;

	if (node != NULL)
	{
		node->info = nv;
		node->pNext = NULL;
	}
	
	return node;
}

void ChenCuoi(LIST &l, NODE*p)
{
	if (l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

int TaoDSNhanVien(LIST &l, char *filename)
{
	ifstream in(filename);

	if (!in)
		return 0; // Mo file khong thanh cong

	Data nv;
	NODE* p = NULL;
	TaoDSRong(l);

	while (!in.eof())
	{
		in >> nv.maNV;
		in >> nv.ho;
		in >> nv.tLot;
		in >> nv.ten;
		in >> nv.namSinh;
		in >> nv.queQuan;
		in >> nv.luong;

		p = TaoNode(nv);
		if (p == NULL)
			exit(-1); // Cap phat dong khong thanh cong

		ChenCuoi(l, p);
	}
	
	return 1;
}

void XuatDongKe(char ch)
{
	for (int i = 0; i < 80; i++)
		cout << ch;
	cout << endl;
}

void XuatDongTieuDe()
{
	XuatDongKe('=');
	cout << '|';
	cout << setiosflags(ios::left) << setw(8) << "Ma NV"
		<< '|' << setw(30) << "Ho va ten"
		<< '|' << setw(10) << "Nam sinh"
		<< '|' << setw(15) << "Que quan"
		<< '|' << setw(11) << "Luong";

	cout << '|';
	cout << endl;
	XuatDongKe('=');
}

void Xuat1NV(Data nv)
{
	cout << '|';
	cout << setiosflags(ios::left) << setw(8) << nv.maNV
		<< '|' << setw(10) << nv.ho
		<< setw(10) << nv.tLot
		<< setw(10) << nv.ten
		<< '|' << setw(10) << nv.namSinh
		<< '|' << setw(15) << nv.queQuan
		<< '|' << setiosflags(ios::fixed) << setprecision(0) << setw(11) << nv.luong;
	cout << '|' << endl;
}

void XuatDSNV(LIST l)
{
	cout << endl;
	XuatDongTieuDe();
	for (NODE*p = l.pHead; p != NULL; p = p->pNext)
	{
		Xuat1NV(p->info);
	}
	XuatDongKe('=');
}

NODE *TimMaxLuong(LIST l)
{
	NODE* res = l.pHead;

	for (NODE *p = l.pHead; p != NULL; p = p->pNext)
	{
		if (res->info.luong < p->info.luong)
			res = p;
	}
	
	return res;
}

LIST TaoDSNhanVienCoLuongThoaDieuKien(LIST l, double luong)
{
	LIST res;
	TaoDSRong(res);

	for (NODE*p = l.pHead; p != NULL; p =p->pNext)
	{
		if (p->info.luong > luong)
		{
			NODE* t = TaoNode(p->info);
			ChenCuoi(res, t);
		}
	}
	
	return res;
}

NODE* TimNhanVienDauTien(LIST l, char *ten)
{
	for (NODE*p = l.pHead; p != NULL; p =p->pNext)
	{
		if (strcmp(p->info.ten, ten) == 0)
			return p;
	}
	
	return NULL;
}

NODE*TimNODETruoc(LIST l, NODE *cur)
{
	NODE* pre = l.pHead;

	while (pre->pNext != cur && pre != NULL)
		pre = pre->pNext;
	
	return pre;
}

NODE *TimTenCuoiCung(LIST l, char *ten)
{
	NODE* res = NULL;

	for (NODE* p = l.pHead; p != NULL; p = p->pNext)
		if (strcmp(p->info.ten, ten) == 0)
			res = p;
	
	return res;
}

NODE* HuyNhanVienCuoiCung(LIST &l, char *ten)
{
	NODE* nodeRemoved = NULL;
	NODE* nodeRemovedCopied = NULL;

	nodeRemoved = TimTenCuoiCung(l, ten);
	if (nodeRemoved)
	{
		nodeRemovedCopied = TaoNode(nodeRemoved->info);
		if (nodeRemoved == l.pHead)
			l.pHead = nodeRemoved->pNext;
		else
		{
			NODE* preNodeRemoved = TimNODETruoc(l, nodeRemoved);
			preNodeRemoved->pNext = nodeRemoved->pNext;

			if (preNodeRemoved->pNext == NULL)
				l.pTail = preNodeRemoved;
		}

		delete nodeRemoved;
	}
	
	return nodeRemovedCopied;
}

void SapTangDanQueQuan_NamSinh(LIST &l)
{
	for (NODE *p = l.pHead; p != l.pTail; p=p->pNext )
	{
		for (NODE *q = p->pNext; q!= NULL; q= q->pNext)
		{
			bool isSwap = (strcmp(p->info.queQuan, q->info.queQuan) > 0) || 
				(strcmp(p->info.queQuan, q->info.queQuan) == 0 && p->info.namSinh > q->info.namSinh);

			if (isSwap)
			{
				Data t = p->info;
				p->info = q->info;
				q->info = t;
			}
		}
	}
}

LIST TaoDSNhanVienTrungHo(LIST l, char *ho)
{
	LIST res;

	TaoDSRong(res);

	for(NODE*p = l.pHead; p != NULL; p=p->pNext)
		if (strcmp(p->info.ho, ho) == 0)
		{
			NODE* t = TaoNode(p->info);
			ChenCuoi(res, t);
		}
	
	return res;
}

LIST TaoDSNhanVienCoNamSinhThoaDieuKien(LIST l, int namSinh)
{
	LIST res;
	TaoDSRong(res);

	for (NODE*p = l.pHead; p != NULL; p=p->pNext)
		if (p->info.namSinh >= namSinh)
		{
			NODE* t = TaoNode(p->info);
			ChenCuoi(res, t);
		}
	
	return res;
}

void SapXep_Giam_MaNV(LIST &l)
{
	for (NODE* p = l.pHead; p != l.pTail; p = p->pNext)
	{
		NODE* max = p;
		for (NODE* q = p->pNext; q != NULL; q = q->pNext)
		{
			if (strcmp(q->info.maNV, max->info.maNV) > 0)
				max = q;
		}

		Data t = max->info;
		max->info = p->info;
		p->info = t; 
	}
}

