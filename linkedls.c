#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}
node;
int add_to_list(int element,node *root);
int main(void){

    node *list = NULL;

    int result = add_to_list(5 ,list);
    

    if(result == 0){
      printf("%i \n",list->number);

      free(list);
      return 0;
  }
  return 0;

}

int add_to_list(int element,node *root){
    node *temp = malloc(sizeof(node));
    if(temp == NULL){
        free(temp);
        return 1;
    }
    temp->number = element;
    if(root == NULL){
        temp->next= NULL;
        root = temp;
    }
    else{
        temp->next = root;
        root = temp;
        free(temp);
    }
    
  return 0;
}
