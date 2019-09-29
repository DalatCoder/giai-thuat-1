
int DemSoNut(BSTree root)
{
	if (root == NULL)
		return 0;
	else return 1 + DemSoNut(root->left) + DemSoNut(root->right);
}

BSTree Search(char maNV[], BSTree root)
{
	if (root != NULL)
	{
		if (strcmp(root->data.maNV, maNV) == 0)
			return root;
		else if (strcmp(root->data.maNV, maNV) < 0)
			return Search(maNV, root->right);
		else
			return Search(maNV, root->left);
	}
	return NULL;
}

Data DeleteMin(BSTree &root)
{
	Data k;
	if (root->left == NULL)
	{
		k = root->data;
		root = root->right;
		return k;
	}
	else
		return DeleteMin(root->left);
}

int DeleteNode(char maNV[], BSTree &root)
{
	if (root != NULL)
	{
		if (strcmp(maNV, root->data.maNV) < 0)
			DeleteNode(maNV, root->left);
		else
		if (strcmp(maNV, root->data.maNV) > 0)
			DeleteNode(maNV, root->right);
		else
		if ((root->left == NULL) && (root->right == NULL))
			root = NULL;
		else
		if (root->left == NULL)
			root = root->right;
		else
		if (root->right == NULL)
			root = root->left;
		else
			root->data = DeleteMin(root->right);
		return 1;
	}
	return 0;
}

