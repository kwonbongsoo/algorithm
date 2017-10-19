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
			printf("데이터 숫자 입력>>");
			gets(tmp);
			num=atoi(tmp);
			if(num==0){
				puts("잘못 입력하셨습니다");
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
		printf("데이터 값: %d 데이터 주소 값: %d\n",head->num,head);
		if(head->next != NULL)
			printData(head->next);
	}else
		puts("생성된 데이터가 없습니다");
}
Node * searchData(Node *head,int num){
	if(head){
		if(head->num!=num)
			searchData(head->next,num);
		else {
			printf("데이터 값: %d 데이터 주소 값: %d\n", head->num, head);
			return head;
		}
	}else
		puts("데이터가 존재 하지 않습니다");
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
		puts("데이터가 없습니다");
	
}
void modifyData(Node * head) {
	int num = 0;
	Node * tmp = NULL;
	num = insertNum();
	tmp = searchData(head, num);
	puts("수정할 데이터");
	tmp->num = insertNum();
}
void allDelete(Node ** head) {
	Node * tmp;
	if (*head) {
		allDelete(&(*head)->next);
		printf("입력된 데이터:%d 메모리 주소 :%d 삭제\n", (*head)->num, *head);
		free(*head);
		*head = NULL;
	}
}