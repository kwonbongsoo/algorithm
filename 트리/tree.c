#include <stdio.h>
#include <stdlib.h>

typedef struct Treedata
{
	int data;
	struct Treedata * Left;
	struct Treedata * Right;
}Tree;
void InsertNode(Tree ** root,int data);
void DispNode(Tree * root);
void DispNode1(Tree * root);
void DispNode2(Tree * root);
void Deletesearch(Tree ** root,int deletedata,Tree ** tmp);
void deletedata(Tree ** root,Tree ** tmp, Tree ** fronttmp);
void Deletefront(Tree ** root,Tree ** tmp,Tree ** fronttmp);
int main()
{
	Tree * root = NULL;
	Tree * fronttmp = NULL;
	Tree * tmp = NULL;
	InsertNode(&root,10);
	InsertNode(&root,20);
	InsertNode(&root,5);
	InsertNode(&root,3);
	InsertNode(&root,6);
	InsertNode(&root,15);
	InsertNode(&root,15);
	InsertNode(&root,22);
	InsertNode(&root,21);
	InsertNode(&root,23);
	DispNode2(root);
	Deletesearch(&root,20,&tmp);
	Deletefront(&root,&tmp,&fronttmp);
	printf(" = = = = = = = = = 삭제 = = = = = = = = = \n");
	DispNode2(root);
}
void InsertNode(Tree ** root,int data)
{
	if(*root == NULL)
	{
		*root = (Tree *)malloc(sizeof(Tree));
		(*root)->data = data;
		(*root)->Left = NULL;
		(*root)->Right = NULL;
		return;
	}
	else
	{
		if((*root)->data > data)
		{
			InsertNode(&(*root)->Left,data);
		}
		else
		{
			if((*root)->data < data)
			{
				InsertNode(&(*root)->Right,data);
			}
			else
			{
				printf("이미 같은값이 있습니다 공간생성을 생성하지 않았습니다.\n");
				return;
			}
		}
	}
}
void DispNode(Tree * root)//후위순회
{
	if(root != NULL)
	{
		DispNode(root->Left);
		DispNode(root->Right);
		printf("%d\n",root->data);
	}
}
void DispNode1(Tree * root) //전위 순회
{
	if(root != NULL)
	{
		printf("%d\n",root->data);
		DispNode1(root->Left);
		DispNode1(root->Right);
	}
}
void DispNode2(Tree * root) //중위 순회
{
	if(root != NULL)
	{
		DispNode2(root->Left);
		printf("%d\n",root->data);
		DispNode2(root->Right);
	}
}
void Deleteserch(Tree ** root,int deletedata,Tree ** tmp)
{
		if(*root != NULL)
		{
			if(deletedata == (*root)->data)
			{
				*tmp = *root;
				return;
			}
			else
			{
				Deletesearch(&(*root)->Left,deletedata,&(*tmp));
				Deletesearch(&(*root)->Right,deletedata,&(*tmp));
			}
		}
}
void Deletefront(Tree ** root,Tree **tmp,Tree ** fronttmp)
{
	if(*root != NULL)
	{
		if((*root)->Left == *tmp)
		{
			*fronttmp = (*root)->Left;
			return;
		}
		else
		{
			if((*root)->Right == *tmp)
			{
				*fronttmp = (*root)->Right;
				return;
			}
			else
			{
				Deletefront(&(*root)->Left,&(*tmp),&(*fronttmp));
				Deletefront(&(*root)->Right,&(*tmp),&(*fronttmp));
			}
		}
	}
}
void deletedata(Tree ** root,Tree ** tmp, Tree ** fronttmp)
{
	Tree * sujung = NULL;
	if((*tmp)->data > (*root)->data)
	{
		sujung = (*tmp)->Left;
		(*fronttmp)->Right = sujung;
		if(sujung->Right != NULL)
		{
			while(sujung)
				sujung = sujung->Right;
			sujung->Right = (*tmp)->Right;
			free(*tmp);
		}
		else
		{
			(*fronttmp)->Right = sujung;
			sujung->Right = (*tmp)->Right;
			free(*tmp);
		}
	}
	else
	{
		sujung = (*tmp)->Right;
		if(sujung->Left != NULL)
		{
			while(sujung)
				sujung = sujung->Left;
			sujung->Left = (*tmp)->Left;
			free(*tmp);
		}
	}
