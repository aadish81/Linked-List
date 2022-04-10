#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}
node;
node *list = NULL;
int add_to_list(int element);
void printls(void);
void reales_ls(void);

int main(void){

    int result = add_to_list(5689);

    if(result != 0){
      return 1;
    }
    

    printls();
    reales_ls();
    return 0;
    

}

int add_to_list(int element){
    node *temp = malloc(sizeof(node));
    if(temp == NULL){
        free(temp);
        return 1;
    }
    temp->number = element;
    if(list == NULL){
        temp->next= NULL;
        list = temp;
    }
    else{
        temp->next = list;
        list = temp;
        
    }
    return 0;
}
void printls(void){
    for(node *tem = list;tem != NULL;tem = tem->next){
        printf("%i\n",tem->number);
    }

}

void reales_ls(void){
    for(node *tem = list;tem !=NULL;tem = tem->next){
        free(tem);
    }
}