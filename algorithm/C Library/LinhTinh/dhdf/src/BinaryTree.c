
#include "src\DnA.h"
typedef	int	DATA;
typedef	struct	_btreenode{
	DATA	data;
	struct _btreenode	*l_link;
	struct _btreenode	*r_link;
}BTreeNode;

BTreeNode	*CreateNode(void);
int	SetLeft(BTreeNode *, BTreeNode *);
int	SetRight(BTreeNode *, BTreeNode *);
DATA	GetData(BTreeNode *);
int		SetData(BTreeNode *, DATA);
int		PrintData(BTreeNode *);

int main(void){
	BTreeNode	*root;
	BTreeNode	*temp;
	DATA	_array[10]={0,1,2,3,4,5,6,7,8,9};
	int i;

	root = CreateNode();
	SetData(root, _array[0]);
	temp = CreateNode();
	SetData(temp, i);
	SetLeft(root, temp);

	temp = CreateNode();
	SetData(temp, 3);
	SetRight(root, temp);

	temp = CreateNode();
	SetData(temp, 4);
	SetLeft(root->l_link, temp);

	temp = CreateNode();
	SetData(temp, 5);
	SetRight(root->l_link, temp);

	temp = CreateNode();
	SetData(temp, 6);
	SetLeft(root->r_link, temp);

	temp = CreateNode();
	SetData(temp, 7);
	SetRight(root->r_link, temp);

	Print(root);
	return 0;
}

int main_1(void){
	BTreeNode	*root;
	BTreeNode	*temp;

	root = CreateNode();
	SetData(root, 1);

	temp = CreateNode();
	SetData(temp, 2);
	SetLeft(root, temp);

	temp = CreateNode();
	SetData(temp, 3);
	SetRight(root, temp);

	temp = CreateNode();
	SetData(temp, 4);
	SetLeft(root->l_link, temp);

	temp = CreateNode();
	SetData(temp, 5);
	SetRight(root->l_link, temp);

	temp = CreateNode();
	SetData(temp, 6);
	SetLeft(root->r_link, temp);

	temp = CreateNode();
	SetData(temp, 7);
	SetRight(root->r_link, temp);

	Print(root);
	return 0;
}

int	Print(BTreeNode *cur){
	if( cur == NULL ){
		return 0;
	}
	printf("%d	", cur->data );
	if(cur->l_link)	Print(cur->l_link);
//	printf("%d	", cur->data );
	if(cur->r_link)	Print(cur->r_link);
//	printf("%d	", cur->data );
	return 0;
}

int	SetLeft(BTreeNode *parent, BTreeNode *child){
	parent->l_link = child;
	return 0;
}
int	SetRight(BTreeNode *parent, BTreeNode *child){
	parent->r_link = child;
	return 0;
}
int	SetData(BTreeNode *p, DATA	arg){
	p->data = arg;
	return 0;
}
DATA	GetData(BTreeNode *p){
	return	p->data;
}
BTreeNode	*CreateNode(void){
	BTreeNode	*bt;
	bt = New(BTreeNode);
	bt->l_link = NULL;
	bt->r_link = NULL;
	return bt;
}
