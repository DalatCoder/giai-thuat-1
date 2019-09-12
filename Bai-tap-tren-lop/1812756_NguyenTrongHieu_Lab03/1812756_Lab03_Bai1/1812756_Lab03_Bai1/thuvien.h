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



