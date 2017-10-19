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
		puts("1. 데이터 입력 및 생성");
		puts("2. 데이터 출력");
		puts("3. 데이터 검색");
		puts("4. 데이터 삭제");
		puts("5. 데이터 수정");
		puts("6. 프로그램 종료");
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
		default:puts("데이터를 잘못 입력하셨습니다.");
			continue;
		}
		system("pause");
	}
}