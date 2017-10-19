#include <stdio.h>
#include <malloc.h>
struct Node{
 int data;
 struct Node * link;
};
typedef struct Node Queue;
Queue *  GetNode(){
 Queue * tmp = (Queue *)malloc(sizeof(Queue));
 tmp->link = NULL;
 return tmp;
}
void insert_data(Queue ** front, Queue ** rear,int data){
 Queue * tmp = GetNode();
 if(*front){
  (*rear)->link = tmp;
  *rear = tmp;
 }else
  *front = *rear = tmp;
 (*rear)->data = data;
}
void delete_data(Queue ** front,Queue ** rear){
 if(*front){
  Queue * tmp = *front;
  *front = tmp->link;
  free(tmp);
  if(*front == NULL)
   *rear = NULL;
 }
}
int main(){
 Queue * front = NULL;
 Queue * rear = NULL;
 insert_data(&front,&rear,10);
 insert_data(&front,&rear,20);
 insert_data(&front,&rear,30);
 delete_data(&front,&rear);
 delete_data(&front,&rear);
 delete_data(&front,&rear);
 return 0;
} 
