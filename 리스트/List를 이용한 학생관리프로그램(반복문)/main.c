#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "linkListWhile.h"
#include <malloc.h>
#pragma warning(disable: 4996)
int main() {
	int data = 0;
	Node * head = getNode();
	Node * tail = getNode();
	head->next = tail;
	tail->next = tail;
	while (1) {
		system("cls");
		puts("======================================");
		puts("1. ������ ���� �� �Է�");
		puts("2. ������ ���");
		puts("3. ������ �˻�");
		puts("4. ������ ����");
		puts("5. ������ ����");
		puts("6. ���α׷� ���� �� ��� ������ ����");
		puts("======================================");
		data = insertData();
		system("cls");
		switch (data) {
		case 1:insertNode(head, tail);
			break;
		case 2:puts("=======================================================");
			printfData(head,tail);
			break;
		case 3: 
			searchData(head, tail);
			break;
		case 4: deleteData(head, tail);
			break;
		case 5:modifyData(head,tail);
			break;
		case 6:allDelete(head,tail);
			return 0;
		default:puts("�߸��Է��ϼ̽��ϴ�");
			continue;
		}
		system("pause");
	}
}