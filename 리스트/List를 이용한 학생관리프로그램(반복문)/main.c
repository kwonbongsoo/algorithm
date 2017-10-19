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
		puts("1. 데이터 생성 및 입력");
		puts("2. 데이터 출력");
		puts("3. 데이터 검색");
		puts("4. 데이터 삭제");
		puts("5. 데이터 수정");
		puts("6. 프로그램 종료 및 모든 데이터 삭제");
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
		default:puts("잘못입력하셨습니다");
			continue;
		}
		system("pause");
	}
}