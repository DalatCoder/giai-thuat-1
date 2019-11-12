
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

