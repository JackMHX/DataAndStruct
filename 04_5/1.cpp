#include <iostream>
#include <vector>

using namespace std;

typedef struct TreeNode* AvlTree;
typedef struct TreeNode* position;

struct TreeNode
{
	int data;
	AvlTree left;
	AvlTree right;
	int height;
};

AvlTree Insert(int x, AvlTree t);
position singleRotateWithLeft(position a);//左单旋
position singleRotateWithright(position b);//右单旋
position doubleRotateWithLeft(position a);//左右旋
position doubleRotateWithright(position b);//右左旋
int maxheight(int a, int b);
int Height(position p);

//左单旋
position singleRotateWithLeft(position a) {
	/*position p = t->left;
	t->left = p->right;
	p->right = t;
	t->height = maxheight(Height(t->left), Height(t->right)) + 1;
	p->height = maxheight(Height(p->left), Height(p->right)) + 1;
	return p;*/
	//swap
	position b = a->left;
	a->left = b->right;
	b->right = a;
	//refresh height of a and b 
	a->height = maxheight(Height(a->left), Height(a->right)) + 1;
	b->height = maxheight(Height(b->left), Height(b->right)) + 1;
	return b;
}
//右单旋
position singleRotateWithright(position b) {
	position a = b->right;
	b->right = a->left;
	a->left = b;
	a->height = maxheight(Height(a->left), Height(a->right)) + 1;
	b->height = maxheight(Height(b->left), Height(b->right)) + 1;
	return a;
}
//左右旋
position doubleRotateWithLeft(position a) {
	a->left = singleRotateWithright(a->left);
	return singleRotateWithLeft(a);
}
//右左旋
position doubleRotateWithright(position b) {
	b->right = singleRotateWithLeft(b->right);
	return singleRotateWithright(b);
}

int Height(position p) {
	//空树的高度是-1
	if (p == NULL) { return -1; }
	return p->height;
}

int maxheight(int a,int b) {
	return a > b ? a : b;
}

AvlTree Insert(int x, AvlTree t) {
	//空节点要创建一个节点
	if (t == NULL) {
		t = new TreeNode;
		t->data = x;
		t->left = NULL;
		t->right = NULL;
		t->height = 0;
	}
	//x<t 向左子数插入
	else if (x < t->data) 
	{
		t->left = Insert(x, t->left);
		//如果是这种情况就需要调整
		if (Height(t->left) - Height(t->right) == 2) {
			if (x < t->left->data) 
			{
				t = singleRotateWithLeft(t);//左单旋
			}
			else
			{
				t = doubleRotateWithLeft(t);//左右旋
			}
		}
	}
	//向右子树插入
	else if (x>t->data)
	{
		t->right = Insert(x, t->right);
		//加了以后高度相差2 就要调整
		if (Height(t->right) - Height(t->left) == 2) {
			if (x>t->right->data)
			{
				t = singleRotateWithright(t);//右单旋
			}
			else
			{
				t = doubleRotateWithright(t);//右左旋
			}
		}
	}
	//x的值是相等的就不插入
	//更新树的高度,选左右子树高度大的那个
	t->height = maxheight(Height(t->left), Height(t->right)) + 1;
	return t;
}

int main() {
	int n, x;
	AvlTree t = NULL;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		t = Insert(x, t);
	}
	cout << t->data;
	system("pause");
}
//
//#include <cstdio>
//#include <cstdlib>
//#include <iostream>
//using namespace std;
//
//typedef struct TreeNode *AvlTree;
//typedef struct TreeNode *Position;
//struct TreeNode
//{
//	int Data;
//	AvlTree Left;
//	AvlTree Right;
//	int Height;
//};
//
//AvlTree Insert(int x, AvlTree T);   //插入新节点，必要时调整
//Position SingleRotateWithLeft(Position a);    //左单旋
//Position SingleRotateWithRight(Position b);   //右单旋
//Position DoubleRotateWithLeft(Position a);    //左右旋
//Position DoubleRotateWithRight(Position b);   //右左旋
//
//int Max(int x1, int x2);      //返回两个int中较大的
//int Height(Position P);     //返回一个节点的高度
//
//int main()
//{
//	int n, x;
//	AvlTree T = NULL;
//
//	cin>>n;
//	for (int i = 0; i < n; i++)
//	{
//		cin>>x;
//		T = Insert(x, T);
//	}
//	printf("%d\n", T->Data);    //打印根节点的值
//
//	return 0;
//}
//
//AvlTree Insert(int x, AvlTree T)
//{
//	if (T == NULL)
//	{
//		T = (AvlTree)malloc(sizeof(struct TreeNode));
//		T->Data = x;
//		T->Left = T->Right = NULL;
//		T->Height = 0;
//	}
//	else if (x < T->Data)   //向左子树插入
//	{
//		T->Left = Insert(x, T->Left);
//		if (Height(T->Left) - Height(T->Right) == 2)    //需调整
//		{
//			if (x < T->Left->Data)
//				T = SingleRotateWithLeft(T);
//			else
//				T = DoubleRotateWithLeft(T);
//		}
//	}
//	else if (x > T->Data)   //向右子树插入
//	{
//		T->Right = Insert(x, T->Right);
//		if (Height(T->Right) - Height(T->Left) == 2)    //需调整
//		{
//			if (x > T->Right->Data)
//				T = SingleRotateWithRight(T);
//			else
//				T = DoubleRotateWithRight(T);
//		}
//	}
//	/*else值为x的节点已经存在树中，无需插入*/
//
//	/*更新节点高度*/
//	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
//	return T;
//}
//
//Position SingleRotateWithLeft(Position a)
//{
//	Position b = a->Left;
//	a->Left = b->Right;
//	b->Right = a;
//	//更新a, b节点高度
//	a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
//	b->Height = Max(Height(b->Left), Height(b->Right)) + 1;
//
//	return b;      /*新的根节点*/
//}
//
//Position SingleRotateWithRight(Position b)
//{
//	Position a = b->Right;
//	b->Right = a->Left;
//	a->Left = b;
//	//更新a,b节点高度
//	a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
//	b->Height = Max(Height(b->Left), Height(b->Right)) + 1;
//	return a;       /*新的根节点*/
//}
//
//Position DoubleRotateWithLeft(Position a)
//{
//	a->Left = SingleRotateWithRight(a->Left);
//	return SingleRotateWithLeft(a);
//}
//
//Position DoubleRotateWithRight(Position b)
//{
//	b->Right = SingleRotateWithLeft(b->Right);
//	return SingleRotateWithRight(b);
//}
//
//int Max(int x1, int x2)
//{
//	return (x1 > x2) ? x1 : x2;
//}
//
//int Height(Position P)
//{
//	if (P == NULL)  //空节点高度为-1
//		return -1;
//	return P->Height;
//}