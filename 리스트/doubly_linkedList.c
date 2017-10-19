#include <stdio.h>
#include <malloc.h>
struct Node{
 struct Node * left;
 int data;
 struct Node * right;
};
typedef struct Node Twolist;
Twolist * Getnode(){
 Twolist * tmp = (Twolist *)malloc(sizeof(Twolist));
 tmp->left = NULL;
 tmp->right = NULL;
}
Twolist * insert_data(Twolist ** head,int data){
 Twolist * tmp = NULL;
 if(*head){
   insert_data(&(*head)->right,data);
 }else{
  tmp = Getnode();
  tmp->data = data;
 }
}
int main(){
 Twolist * head = NULL;
 insert_data(&head,10);
}
