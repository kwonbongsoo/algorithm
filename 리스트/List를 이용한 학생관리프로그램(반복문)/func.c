#include <stdio.h>
#include "linkListWhile.h"


Node * getNode() {
	Node * new = (Node *)malloc(sizeof(Node));
	new->add = NULL;
	new->next = NULL;
	new->phone = NULL;
	new->name = NULL;
	new->english = 0;
	new->korea = 0;
	new->math = 0;
	new->science = 0;
	new->avg = 0;
	new->sum = 0;
	new->age = 0;
	new->grade = '0';

	return new;
}
void insertNode(Node * head, Node * tail) {
	Node *tmp = NULL;
	tmp = getNode();
	puts("이름 입력");
	tmp->name = insertChar();
	puts("주소 입력");
	tmp->add = insertChar();
	puts("휴대폰 번호 입력");
	tmp->phone = insertChar();
	puts("나이 입력");
	tmp->age = insertData();
	changeScore(tmp);

	//while (head->next != tail && head->next->sum > tmp->sum)
	//	head = head->next;  //밑에거나 위에거나 같은거
	for (; head->next != tail && head->next->sum > tmp->sum; head = head->next);
	tmp->next = head->next;
	head->next = tmp;
}
int insertData() {
	int num = 0;
	char tmp[30];
	printf(">>");
	gets(tmp);
	num = atoi(tmp);
	return num;
}
char * insertChar() {
	char tmp[30];
	char *tmp1 = NULL;
	printf(">>");
	gets(tmp);
	tmp1 = (char *)malloc(sizeof(tmp) + 1);
	strcpy(tmp1, tmp);
	return tmp1;
}
void printfData(Node * head, Node *tail) {
	head = head->next;
	while (head != tail) {
		printf("이름:%-4s\t폰번:%-4s\t 주소:%-4s\n나이:%-4d\t영어점수:%-4d\t국어점수:%-4d\n수학점수:%-4d\t과탐점수:%-4d\t총 점:%0.2f\n평 균:%0.2f\t 학 점:%c\n", head->name, head->phone,head->add,head->age,head->english, head->korea, head->math, head->science, head->sum, head->avg,head->grade);
		puts("=======================================================");
		head = head->next;
	}
}
Node * searchData(Node * head, Node * tail) {
	Node * search = NULL;
	char name[30];
	puts("검색할 이름 입력");
	printf(">>");
	gets(name);
	head = head->next;
	for (; head != tail; head = head->next) {
		if (strcmp(name, head->name) == 0) { //strcmp 변수를 비교할때 포인터가 NULL 경우 액세스 오류가 뜬다. 찾아냄
			printf(" = = = = = = = = = = = = = =\n");
			printf("학생 이름 :%s\n", head->name);
			printf("학생 주소 :%s\n", head->add);
			printf("학생 나이 :%d\n", head->age);
			printf("국어 점수 :%d\n", head->korea);
			printf("영어 점수 :%d\n", head->english);
			printf("수학 점수 :%d\n", head->math);
			printf("과탐 점수 :%d\n", head->science);
			printf("합계 점수 :%.2f\n", head->sum);
			printf("평균 점수 :%.2f\n", head->avg);
			printf("학생 등급 :%c 등급\n", head->grade);
			printf(" = = = = = = = = = = = = = =\n");
			search = head;
			return search;
		}
	}
	if (head->next == tail)
		puts("생성된 데이터가 없습니다.");
	return search;
}
void modifyData(Node * head, Node * tail) {
	Node * find = NULL;
	int select = 0;
	find = searchData(head, tail);
	system("pause");
	if (find) {
		while (1) {
			system("cls");
			puts(" = = = = = = = = = = = = = =");
			puts("1. 이름 수정");
			puts("2. 주소 수정");
			puts("3. 폰번호 수정");
			puts("4. 나이 수정");
			puts("5. 점수 수정");
			puts("6. 나가기");
			puts(" = = = = = = = = = = = = = =");
			printf(">>");
			select = insertData();

			switch (select) {
			case 1:puts("수정할 이름 입력");
				find->name = modifyChar(find->name);
				break;
			case 2:puts("수정할 주소 입력");
				find->add = modifyChar(find->add);
				break;
			case 3:puts("수정할 폰번호 입력");
				find->phone = modifyChar(find->phone);
				break;
			case 4:puts("수정할 나이 입력");
				find->age = insertData();
				break;
			case 5:changeScore(find);
				break;
			case 6:return;
			default:puts("잘못입력하셨습니다");
				continue;
			}system("pause");
		}
	}
}
char * modifyChar(char * tmp) {
	char temp[50];
	printf(">>");
	gets(temp);
	free(tmp);
	tmp = NULL;
	tmp = (char *)malloc(sizeof(temp) + 1);
	strcpy(tmp, temp);
	return tmp;
}
void changeScore(Node * find) {
	puts("영어점수 입력");
	find->english = insertData();
	puts("국어점수 입력");
	find->korea = insertData();
	puts("과탐점수 입력");
	find->science = insertData();
	puts("수학점수 입력");
	find->math = insertData();
	find->sum = find->english + find->math + find->korea + find->science;
	find->avg = find->sum / 4;
	if (find->avg >= 90)
		find->grade = 'A';
	else if (find->avg <= 89 && find->avg >= 70)
		find->grade = 'B';
	else if (find->avg <= 69 && find->avg >= 60)
		find->grade = 'C';
	else if (find->avg <= 59 && find->avg >= 50)
		find->grade = 'D';
	else if (find->avg <= 49 && find->avg >= 40)
		find->grade = 'F';
	else
		find->grade = 'Z';
}
void allDelete(Node * head, Node *tail) {
	Node * first = NULL;
	Node * tmp = NULL;
	Node * delete = NULL;
	first = head;
	tmp = head->next;
	while (tmp != tail) {
		delete = tmp;
		tmp = tmp->next;
		printf("%s 데이터 삭제\n", delete->name);
		free(delete->add);
		delete->add = NULL;
		free(delete->name);
		delete->name = NULL;
		free(delete->phone);
		delete->phone = NULL;
		free(delete);
		delete = NULL;
	}
	puts("head 삭제");
	free(first);
	first = NULL;
	puts("tail 삭제");
	free(tmp);
	tmp = NULL;
}
void deleteData(Node * head, Node * tail) {
	Node * delete = NULL;
	for (delete = searchData(head, tail); head->next != delete;head = head->next);
	if (delete) {
		head->next = delete->next;
		printf("%s의 이름,주소,폰번 해제\n", delete->name);
		free(delete->name);
		free(delete->add);
		free(delete->phone);
		delete->add = NULL;
		delete->phone = NULL;
		delete->name = NULL;
		delete->next = NULL;
		free(delete);
		delete = NULL;
		puts("구조체 할당 해제");
		puts("삭제 완료");
	}
}