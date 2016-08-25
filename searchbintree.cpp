#include<iostream>

using namespace std;

typedef struct binTreeNode
{
	binTreeNode(int d) :data(d), left(NULL), right(NULL)
	{}
	int data;
	binTreeNode * left;
	binTreeNode * right;

}bNode;

class searchBinTree
{
public:
	searchBinTree() :root(NULL)
	{}
	bNode* search(int val, bNode * cur, bNode *& prev)
	{
		if (cur == NULL) 
			return NULL;
		if (val == cur->data)return cur;
		prev = cur;
		if (val <cur->data)
			search(val, cur->left, prev);
		else
		{
			search(val, cur->right, prev);
		}
	}
	bool insert(int val, bNode *&cur)
	{
		bNode * n = NULL;
		if (search(val, cur, n) == NULL)
		{
			bNode * buy = new bNode(val);
			if (cur == NULL)
			{
				cur = buy;
				return true;
			}
			else if (n->data > val)
			{
				buy->left = n->left;
				n->left = buy;
			}
			else
			{
				buy->right = n->right;
				n->right = buy;
			}
		}
		return true;
	}
	bool create(int * a, int n)
	{
		for (int i = 0; i<n; i++)
		{
			insert(a[i], root);
		}
		return true;
	}

private:
	bNode * root;
};
int main()
{
	int a[] = { 1,2,4,3,5,6,7,8,9};
	searchBinTree sbt;
	sbt.create(a, sizeof(a)/sizeof(a[0]));
	return 0;
}