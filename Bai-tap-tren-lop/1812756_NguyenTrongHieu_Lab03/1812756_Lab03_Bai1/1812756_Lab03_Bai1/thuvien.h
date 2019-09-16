#define MAX 100
// typedef int data; ambiguous

struct tagNode
{
	int info;
	tagNode* pNext;
};

typedef tagNode NODE;

struct LIST
{
	NODE* pHead;
	NODE* pTail;
};


// =================================================================================================== //

// Nguyen mau ham
// 1. Doc va xuat file
NODE* GetNode(int data);
void CreateEmptyList(LIST& l);
bool IsEmptyList(LIST l);
void InsertTail(LIST& ls, int x);
int GetDataFromFile(char* filename, LIST& ls);
void DisplayList(LIST ls);

// 2. Tinh toan
int CalcSum(LIST ls); 

// 3. Tim kiem
NODE* FindMax(LIST ls);
NODE* Search_First(LIST ls, int x);
int Search_First_Index(LIST ls, int x);
int Search_Final_Index(LIST ls, int x);

// Dinh nghia ham
NODE* GetNode(int data)
{
	NODE* p;
	p = new NODE;

	if (p != NULL)
	{
		p->info = data;
		p->pNext = NULL;
	}

	// p == NULL neu tao node khong thanh cong
	return p;
}

// Tao danh sach rong
void CreateEmptyList(LIST& l)
{
	l.pHead = l.pTail = NULL;
}

// Kiem tra danh sach co rong hay khong
bool IsEmptyList(LIST l)
{
	return l.pHead == NULL;
}

int GetDataFromFile(char* filename, LIST& ls)
{
	ifstream input(filename);
	if (!input)
	{
		return 0; // Loi mo file
	}

	// Tao danh sach trong
	CreateEmptyList(ls);
	int x;

	input >> x;
	InsertTail(ls, x);

	while (!input.eof())
	{
		input >> x;
		InsertTail(ls, x);
	}

	input.close();
	return 1;
}

void DisplayList(LIST ls)
{
	NODE* p;
	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach rong!";
		return;
	}

	cout << "\nDanh sach lien ket hien tai: \n";
	p = ls.pHead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}

// Chen phan tu vao cuoi list
void InsertTail(LIST &ls, int x)
{
	NODE* new_node = GetNode(x);
	if (!new_node)
	{
		cout << "\nLoi cap phat bo nho! Khong the thuc hien thao tac nay!";
		return;
	}

	// Danh sach trong, phan tu dau tien cung la phan tu cuoi cung
	if (IsEmptyList(ls))
	{
		ls.pHead = new_node;
		ls.pTail = new_node;
	}
	else
	{
		// Tao con tro tu node cuoi cung den node moi tao
		// Cap nhat con tro cuoi cung luu vi tri cua node moi tao
		ls.pTail->pNext = new_node;
		ls.pTail = new_node;
	}
}

int CalcSum(LIST ls)
{
	int sum = 0;
	NODE* p;

	if (IsEmptyList(ls))
	{
		// cout << "\nDanh sach rong!";
		return sum;
	}

	p = ls.pHead;
	while (p != NULL)
	{
		sum += p->info;
		p = p->pNext;
	}

	return sum;
}

NODE* FindMax(LIST ls)
{
	NODE* res; // Node chua gia tri lon nhat trong day
	NODE* cur; // Node hien tai

	cur = ls.pHead;
	res = ls.pHead;

	while (cur != NULL)
	{
		if (cur->info > res->info)
			res = cur;
		cur = cur->pNext;
	}

	return res; // res == NULL neu danh sach rong
}

NODE* Search_First(LIST ls, int x)
{
	NODE* res = ls.pHead;
	while (res != NULL && res->info != x)
		res = res->pNext;
	return res;
}

int Search_First_Index(LIST ls, int x)
{
	NODE* p = ls.pHead;
	int i = 0;

	while (p != NULL && p ->info != x)
	{
		p = p->pNext;
		i++;
	}

	if (!p)
		i = -1; // khong tim thay x

	return i;
}

int Search_Final_Index(LIST ls, int x)
{
	NODE* p = ls.pHead;
	int i = 0, kq = -1;

	while (p != NULL)
	{
		if (p->info == x)
			kq = i;

		p = p->pNext;
		i++;
	}

	return kq;
}

void Insert_Begin(LIST& ls, NODE* node)
{
	if (IsEmptyList(ls))
	{
		ls.pHead = node;
		ls.pTail = node;
	}
	else
	{
		node->pNext = ls.pHead;
		ls.pHead = node;
	}
}

void Insert_End(LIST& ls, NODE* node)
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

void Chen_X_Sau_Y(LIST& ls, NODE* y, NODE* x)
{
	if (y == ls.pTail)
	{
		y->pNext = x;
		ls.pTail = x;
	}
	else
	{
		x->pNext = y->pNext;
		y->pNext = x;
	}
}
