struct NhanVien
{
	char maNV[10];
	char hoTen[30];
	unsigned int namsinh;
	char diaChi[30];
	unsigned int luong;
};

typedef NhanVien Data;

struct BSNode
{
	Data data;
	BSNode *left;
	BSNode *right;
};

typedef BSNode *BSTree;

void CreateBST(BSTree &root);
BSNode *CreateNode(Data data);
int InsertNode(BSTree &root, Data data);
int GetDataFromFile(char *filename, BSTree &root);
void PreOrder(BSTree root);
void InOrder(BSTree root);
void PosOrder(BSTree root);

void PosOrder(BSTree root)
{
	if (root)
	{
		PosOrder(root->left);
		PosOrder(root->right);
		XuatNV(root->data);
	}
}

void InOrder(BSTree root)
{
	if (root)
	{
		InOrder(root->left);
		XuatNV(root->data);
		InOrder(root->right);
	}
}

void PreOrder(BSTree root)
{
	if (root)
	{
		XuatNV(root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

// OUTPUT
//    0: Doc du lieu khong thanh cong
//    1: Doc du lieu thanh cong
int GetDataFromFile(char *filename, BSTree &root)
{
	ifstream input(filename);
	if (!input)
		return 0;

	Data data;
	int kq;

	CreateBST(root);
	input >> data.maNV;
	input >> data.hoTen;
	input >> data.namsinh;
	input >> data.diaChi;
	input >> data.luong;
	kq = InsertNode(root, data);

	if (kq != 1)
		return 0;

	while (!input.eof())
	{
		input >> data.maNV;
		input >> data.hoTen;
		input >> data.namsinh;
		input >> data.diaChi;
		input >> data.luong;
		kq = InsertNode(root, data);
		if (kq != 1)
			return 0;
	}

	input.close();
	return 1;
}

// OUTPUT:
//    - 0: Nut da ton tai
//    - -1: Cap phat dong khong thanh cong
//    - 1: Tao nut thanh cong
int InsertNode(BSTree &root, Data data)
{
	if (root)
	{
		if (strcmp(root->data.maNV, data.maNV) == 0)
			return 0;

		if (strcmp(root->data.maNV, data.maNV) > 0)
			return InsertNode(root->left, data);
		else
			return InsertNode(root->right, data);
	}

	root = CreateNode(data);
	if (!root)
		return -1;
	return 1;
}

BSNode *CreateNode(Data data)
{
	BSNode *p = new BSNode;
	if (p)
	{
		p->data = data;
		p->left = nullptr;
		p->right = nullptr;
	}

	return p;
}

void CreateBST(BSTree &root)
{
	root = nullptr;
}
