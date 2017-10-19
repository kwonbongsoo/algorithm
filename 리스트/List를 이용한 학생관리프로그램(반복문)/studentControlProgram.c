#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
struct Node{
 char * name;
 char * addr;
 int age;
 int kor;
 int eng;
 int math;
 struct Node * link;
};
typedef struct Node List;
List * Getnode(){
 List * tmp = (List *)malloc(sizeof(List));
 tmp->link = NULL;
 return tmp;
}
void insert_data(List ** Head){
 if(*Head)
  insert_data(&(*Head)->link);
 else{
  char name[20],addr[30];
  List * tmp = Getnode();
  system("cls");
  printf("학생 이름 입력:");
  gets(name);
  tmp->name = (char *)malloc(strlen(name)+1);
  strcpy(tmp->name,name);
  printf("%s 학생 주소 입력:",tmp->name);
  gets(addr);
  tmp->addr = (char *)malloc(strlen(addr)+1);
  strcpy(tmp->addr,addr);
  printf("%s 학생 나이 입력:",tmp->name);
  gets(name);
  tmp->age = atoi(name);
  printf("%s 학생 국어 점수:",tmp->name);
  gets(name);
  tmp->kor = atoi(name);
  printf("%s 학생 수학 점수:",tmp->name);
  gets(name);
  tmp->math = atoi(name);
  printf("%s 학생 영어 점수:",tmp->name);
  gets(name);
  tmp->eng = atoi(name);
  printf("학생 정보 입력 완료\n");
 }
}
int start(){
 char  select[10];
 int choice,data;
 List * Head = NULL;
 while(1){
  system("cls");
  printf(" < < < = = = = 메 뉴 = = = = > > > \n");
  printf("\n1.학생 등록\n");
  printf("2.학생 검색\n");
  printf("3.학생 목록\n");
  printf("4.학생 수정\n");
  printf("5.학생 삭제\n");
  printf("6.종료\n");
  printf("선택:");
  gets(select);
  choice = atoi(select);
  switch(choice){
  case 1:insert_data(&Head);
   break;
  }
  system("pause");
 }
}
void main(){
 start();
}
