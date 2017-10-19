#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include "test.h"

Node * getNode(){
	 Node *tmp=(Node *)malloc(sizeof(Node));
	 tmp->num = 0;
	 tmp->next = NULL;
	 return tmp;
}
int insertNum(){
	int num=0;
	char tmp[20];
	while(num==0){
			printf("������ ���� �Է�>>");
			gets(tmp);
			num=atoi(tmp);
			if(num==0){
				puts("�߸� �Է��ϼ̽��ϴ�");
			}
		}
	return num;
}
void insertData(Node **head,Node **tail){
	if (*head) {
		insertData(&(*head)->next, &(*tail));
	}
	else {
		*head = getNode();
		*tail = *head;
		(*head)->num = insertNum();
	}
}
void printData(Node *head){
	if(head){
		printf("������ ��: %d ������ �ּ� ��: %d\n",head->num,head);
		if(head->next != NULL)
			printData(head->next);
	}else
		puts("������ �����Ͱ� �����ϴ�");
}
Node * searchData(Node *head,int num){
	if(head){
		if(head->num!=num)
			searchData(head->next,num);
		else {
			printf("������ ��: %d ������ �ּ� ��: %d\n", head->num, head);
			return head;
		}
	}else
		puts("�����Ͱ� ���� ���� �ʽ��ϴ�");
}
void deleteData(Node **head,int num){
	Node *tmp1 = NULL;
	if (*head) {
		if ((*head)->num != num)
			deleteData(&(*head)->next,num);
		else {
			tmp1 = (*head)->next;
			free(*head);
			*head = tmp1;
		}
	}
	else
		puts("�����Ͱ� �����ϴ�");
	
}
void modifyData(Node * head) {
	int num = 0;
	Node * tmp = NULL;
	num = insertNum();
	tmp = searchData(head, num);
	puts("������ ������");
	tmp->num = insertNum();
}
void allDelete(Node ** head) {
	Node * tmp;
	if (*head) {
		allDelete(&(*head)->next);
		printf("�Էµ� ������:%d �޸� �ּ� :%d ����\n", (*head)->num, *head);
		free(*head);
		*head = NULL;
	}
}