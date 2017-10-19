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
	puts("�̸� �Է�");
	tmp->name = insertChar();
	puts("�ּ� �Է�");
	tmp->add = insertChar();
	puts("�޴��� ��ȣ �Է�");
	tmp->phone = insertChar();
	puts("���� �Է�");
	tmp->age = insertData();
	changeScore(tmp);

	//while (head->next != tail && head->next->sum > tmp->sum)
	//	head = head->next;  //�ؿ��ų� �����ų� ������
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
		printf("�̸�:%-4s\t����:%-4s\t �ּ�:%-4s\n����:%-4d\t��������:%-4d\t��������:%-4d\n��������:%-4d\t��Ž����:%-4d\t�� ��:%0.2f\n�� ��:%0.2f\t �� ��:%c\n", head->name, head->phone,head->add,head->age,head->english, head->korea, head->math, head->science, head->sum, head->avg,head->grade);
		puts("=======================================================");
		head = head->next;
	}
}
Node * searchData(Node * head, Node * tail) {
	Node * search = NULL;
	char name[30];
	puts("�˻��� �̸� �Է�");
	printf(">>");
	gets(name);
	head = head->next;
	for (; head != tail; head = head->next) {
		if (strcmp(name, head->name) == 0) { //strcmp ������ ���Ҷ� �����Ͱ� NULL ��� �׼��� ������ ���. ã�Ƴ�
			printf(" = = = = = = = = = = = = = =\n");
			printf("�л� �̸� :%s\n", head->name);
			printf("�л� �ּ� :%s\n", head->add);
			printf("�л� ���� :%d\n", head->age);
			printf("���� ���� :%d\n", head->korea);
			printf("���� ���� :%d\n", head->english);
			printf("���� ���� :%d\n", head->math);
			printf("��Ž ���� :%d\n", head->science);
			printf("�հ� ���� :%.2f\n", head->sum);
			printf("��� ���� :%.2f\n", head->avg);
			printf("�л� ��� :%c ���\n", head->grade);
			printf(" = = = = = = = = = = = = = =\n");
			search = head;
			return search;
		}
	}
	if (head->next == tail)
		puts("������ �����Ͱ� �����ϴ�.");
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
			puts("1. �̸� ����");
			puts("2. �ּ� ����");
			puts("3. ����ȣ ����");
			puts("4. ���� ����");
			puts("5. ���� ����");
			puts("6. ������");
			puts(" = = = = = = = = = = = = = =");
			printf(">>");
			select = insertData();

			switch (select) {
			case 1:puts("������ �̸� �Է�");
				find->name = modifyChar(find->name);
				break;
			case 2:puts("������ �ּ� �Է�");
				find->add = modifyChar(find->add);
				break;
			case 3:puts("������ ����ȣ �Է�");
				find->phone = modifyChar(find->phone);
				break;
			case 4:puts("������ ���� �Է�");
				find->age = insertData();
				break;
			case 5:changeScore(find);
				break;
			case 6:return;
			default:puts("�߸��Է��ϼ̽��ϴ�");
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
	puts("�������� �Է�");
	find->english = insertData();
	puts("�������� �Է�");
	find->korea = insertData();
	puts("��Ž���� �Է�");
	find->science = insertData();
	puts("�������� �Է�");
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
		printf("%s ������ ����\n", delete->name);
		free(delete->add);
		delete->add = NULL;
		free(delete->name);
		delete->name = NULL;
		free(delete->phone);
		delete->phone = NULL;
		free(delete);
		delete = NULL;
	}
	puts("head ����");
	free(first);
	first = NULL;
	puts("tail ����");
	free(tmp);
	tmp = NULL;
}
void deleteData(Node * head, Node * tail) {
	Node * delete = NULL;
	for (delete = searchData(head, tail); head->next != delete;head = head->next);
	if (delete) {
		head->next = delete->next;
		printf("%s�� �̸�,�ּ�,���� ����\n", delete->name);
		free(delete->name);
		free(delete->add);
		free(delete->phone);
		delete->add = NULL;
		delete->phone = NULL;
		delete->name = NULL;
		delete->next = NULL;
		free(delete);
		delete = NULL;
		puts("����ü �Ҵ� ����");
		puts("���� �Ϸ�");
	}
}