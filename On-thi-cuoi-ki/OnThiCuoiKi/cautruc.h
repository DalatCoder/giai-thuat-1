struct NhanVien
{
	char maNV[8];
	char ho[10];
	char tLot[10];
	char ten[10];
	int namSinh;
	char queQuan[20];
	double luong;
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

