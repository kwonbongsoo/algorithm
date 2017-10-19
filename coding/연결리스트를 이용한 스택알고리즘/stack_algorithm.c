#include <stdio.h>
#include <Windows.h>
#include <malloc.h>
#include <stdlib.h>
void gotoxy(int x, int y){
 COORD pos = {x,y};
 SetConsoleCursorPosition
  (GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
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
  char empty[30];
  *Head = Getnode();
  printf("입력:");
  gets(empty);
  (*Head)->data = atoi(empty);
 }
}
void delete_data(List ** Head){
 if(*Head)
  delete_data(&(*Head)->link);
 else
  free(*Head);
}
List * Stackpush(List ** Head){
 if((*Head)->link)
  Stackpush(&(*Head)->link);
 else
  return *Head;
}
void Alldelete(List ** Head){
 if(*Head){
  Alldelete(&(*Head)->link);
 }else
  return;
 free(*Head);
}
void start(){
 List * Head = NULL;
 List * tmp = NULL;
 char empty[50];
 int select;
 int y=25;
 gotoxy(30,y);
 y--;
 for(printf("Stack 메모리 현황\n");y>14;y--){
  gotoxy(30,y);
  printf("\tFFFFFF : EMPTY");
 }
 y=24;
 gotoxy(0,0);
 printf("Stack 구조 프로그램 v1.0\n");
 printf("1. Push\t2. Pop\t3. 종료\n");
 while(1){
  gotoxy(0,3);
  printf("                                            ");
  gotoxy(0,2);
  printf("선택:     \b\b\b\b\b");
  gets(empty);
  select = atoi(empty);
  switch(select){
  case 1:insert_data(&Head);
   if(y>=15&&y<=24){
    gotoxy(25,y);
    tmp = Stackpush(&Head);
    printf("Top ▶ %d:    %d     ",&*tmp,tmp->data);
   }y--;
   break;
  case 2:delete_data(&Head);
   y++;
   if(&*Head){
    if(y<=24 && y>=15){
     gotoxy(25,y);
     printf("     \tFFFFFF : EMPTY                         ");
    }else if(y>24)
     y=24;
   }
   break;
  case 3:Alldelete(&Head);
   return;
  }
 }
}
void main(){
 start();
}
