#define MAX 100

typedef int Data;

struct TagNode
{
	Data data;
	TagNode *pNext;
};

typedef TagNode NODE;

struct Stack
{
	NODE *pHead;
	NODE *pTail;
};


void CreateEmptyStack(Stack &s)
{
	s.pHead = s.pTail = NULL;
}

bool IsEmptyStack(Stack s)
{
	return s.pHead == NULL;
}

void InsertHead(Stack &s, NODE *p)
{
	if (IsEmptyStack(s))
	{
		s.pHead = p;
		s.pTail = p;
	}
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}

NODE *CreateNode(Data data)
{
	NODE*p = new NODE;
	if (p)
	{
		p->data = data;
		p->pNext = NULL;
	}
	return p;
}

int GetDataFromFile(char *filename, Stack &s)
{
	ifstream input(filename);
	if (!input)
		return 0; // Loi mo file

	NODE *new_ele;
	Data data;

	while (!input.eof())
	{
		input >> data;
		new_ele = CreateNode(data);
		if (new_ele)
		{
			InsertHead(s, new_ele);
		}
		else
			return -1; // Loi cap phat vung nho
	}

	input.close();
	return 1;
}

void DisplayStack(Stack s)
{
	cout << endl;
	NODE *p = s.pHead;

	while (p != NULL)
	{
		cout << p->data << '\t';
		p = p->pNext;
	}
	cout << endl;
}

int Count_X(Stack s, Data x)
{
	int res = 0;

	NODE *p = s.pHead;

	while (p != NULL)
	{
		if (p->data == x) res++;
		p = p->pNext;
	}

	return res;
}

void RemoveHead(Stack &s)
{
	if (IsEmptyStack(s)) return;

	NODE *p = s.pHead;
	s.pHead = p->pNext;
	delete p;

	if (s.pHead == NULL)
		s.pTail = NULL;
}

void InsertTail(Stack &s, NODE *p)
{
	if (IsEmptyStack(s))
	{
		s.pHead = p;
		s.pTail = p;
	}
	else
	{
		s.pTail->pNext = p;
		s.pTail = p;
	}
}

Stack Remove_All_X(Stack s, Data data)
{
	Stack res;
	CreateEmptyStack(res);

	NODE *p;	
	p = s.pHead;

	while (p)
	{
		if (p->data != data)
		{
			NODE *new_ele = CreateNode(p->data);

			InsertTail(res, new_ele);
		}
		p = p->pNext;
	}

	return res;
}
