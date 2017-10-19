#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
struct Node{
 int data;
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
  int data;
  List * tmp = Getnode();
  *Head = tmp;
  printf("데이터 입력:");
  scanf("%d",&data);
  tmp->data = data;
 }
}
void modify_data(List ** Head,int data){
 if(*Head == NULL){
  printf("데이터가 존재하지 않습니다\n");
  return;
 }
 if((*Head)->data == data){
  printf("수정데이터:");
  scanf("%d",&data);
  (*Head)->data = data;
 }else
  modify_data(&(*Head)->link,data);
}
void search_data(List * Head,int data){
 if(Head == NULL){
  printf("데이터가 존재하지 않습니다\n");
  return;
 }
 if(Head->data == data)
  printf("데이터:%d   데이터 주소값:%p\n",Head->data,Head);
 else
  search_data(Head->link,data);
}
void print_data(List * Head){
 if(Head){
  printf("%d\n",Head->data);
  print_data(Head->link);
 }
}
void delete_data(List ** Head,int data){
 if(*Head == NULL){
  printf("데이터가 존재하지 않습니다\n");
  return;
 }
 if((*Head)->data == data){
  List * tmp = (*Head)->link;
  printf("삭제한 데이터:%d\n",(*Head)->data);
  free(*Head);
  *Head = tmp;
 }
 else
  delete_data(&(*Head)->link,data);
}
void alldelete_data(List ** Head){
 if(*Head){
  alldelete_data(&(*Head)->link);
  free(*Head);
 }
}
int start(){
 char  select[10];
 int choice,data;
 List * Head = NULL;
 while(1){
  system("cls");
  printf(" = = = = = = = 연결리스트 간단 프로그램 = = = = = = = = \n");
  printf("  1.삽입\n");
  printf("  2.수정\n");
  printf("  3.검색\n");
  printf("  4.출력\n");
  printf("  5.삭제\n");
  printf("  6.종료\n");
  printf(">");
  gets(select);
  choice = atoi(select);
  switch(choice){
  case 1:insert_data(&Head);
   break;
  case 2:printf("기존데이터:");
   gets(select);
   data = atoi(select);
   modify_data(&Head,data);
   break;
  case 3:printf("검색할 데이터:");
   gets(select);
   data = atoi(select);
   search_data(Head,data);
   break;
  case 4:print_data(Head);
   break;
  case 5:printf("삭제할 데이터:");
   gets(select);
   data = atoi(select);
   delete_data(&Head,data);
   break;
  case 6:alldelete_data(&Head);
   return 0;
  default:continue;
  }
  system("pause");
 }
}
void main(){
 start();
}
