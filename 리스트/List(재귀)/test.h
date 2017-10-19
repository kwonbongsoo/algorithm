#ifndef _TEST_H
#define _TEST_H
typedef struct list{
	int num;
	struct list *next;
}Node;
Node * getNode();
int insertNum();
void insertData(Node **head, Node **tail);
void printData(Node *head);
Node * searchData(Node *head,int num);
void deleteData(Node **head);
void modifyData(Node * head);
void allDelete(Node ** head);
#endif