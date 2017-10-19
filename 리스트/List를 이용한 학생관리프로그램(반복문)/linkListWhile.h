#ifndef _linkListWhile_h
#define _linkListWhile_h
typedef struct list {
	char grade;
	char *name;
	char *phone;
	char *add;
	int age;
	int english;
	int korea;
	int math;
	int science;
	float avg;
	float sum;

	struct list * next;
}Node;
void insertNode(Node * head, Node * tail);
Node * getNode();
int insertData();
char * insertChar();
void printfData(Node * head, Node *tail);
Node * searchData(Node * head, Node * tail);
void modifyData(Node * head, Node * tail);
char * modifyChar(char * tmp);
void changeScore(Node * find);
void allDelete(Node * head, Node *tail);
void deleteData(Node * head, Node * tail);
#endif