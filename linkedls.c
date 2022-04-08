#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}
node;

void printls(node *list);
void reales_ls(node *list);
int add_to_list(int element,node *root);

int main(void){

    node *list = NULL;
    int result = add_to_list(5 ,list);
    
    if(result == 0){
      printls(list);
      reales_ls(list);
      return 0;
  }
  else{
      return 1;
  }

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
void printls(node *list){
    for(node *tem = list;tem != NULL;tem = tem->next){
        printf("%i\n",tem->number);
    }
}

void reales_ls(node *list){
    for(node *tem = list;tem !=NULL;tem = tem->next){
        free(tem);
    }
}