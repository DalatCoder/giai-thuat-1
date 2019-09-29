typedef int Data;

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
    cout << root->data << '\t';
  }
}

void InOrder(BSTree root)
{
  if (root)
  {
    InOrder(root->left);
    cout << root->data << '\t';
    InOrder(root->right);
  }
}

void PreOrder(BSTree root)
{
  if (root)
  {
    cout << root->data << '\t';
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
  input >> data;
  kq = InsertNode(root, data);

  if (kq != 1)
    return 0;

  while (!input.eof())
  {
    input >> data;
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
    if (root->data == data)
      return 0;

    if (root->data > data)
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
