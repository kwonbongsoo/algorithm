#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
#include "test.h"
int main(){
	Node *head = NULL;
	Node *tail = NULL;
	char tmp[10];
	int num=0;
	int select = 0;
	while(select!=6){
		system("cls");
		puts("========================");
		puts("1. ������ �Է� �� ����");
		puts("2. ������ ���");
		puts("3. ������ �˻�");
		puts("4. ������ ����");
		puts("5. ������ ����");
		puts("6. ���α׷� ����");
		puts("========================");
		printf(">>");
		gets(tmp);
		select=atoi(tmp);
		system("cls");
		switch (select) {
		case 1:insertData(&head, &tail);
			break;
		case 2:puts("=======================================");
			printData(head);
			puts("=======================================");
			break;
		case 3:num = insertNum();
			searchData(head, num);
			break;
		case 4:num = insertNum();
			deleteData(&head, num);
			break;
		case 5:modifyData(head);
			break;
		case 6:allDelete(&head);
			return 0;
		default:puts("�����͸� �߸� �Է��ϼ̽��ϴ�.");
			continue;
		}
		system("pause");
	}
}