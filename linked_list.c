#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}
node;

node *list = NULL;
int search(int a);
int add_to_list(int element);
void printls(void);
void reales_ls(void);

int main(void){
    int num_of_elm;
    int num;
    int result;
    printf("Enter the number of element you want to store: ");
    scanf("%i",&num_of_elm);
    for(int i = 0; i<num_of_elm;i++){
        printf("Enter the number: ");
        scanf("%i\n",&num);
        result = add_to_list(num);
        if(result != 0){
            printf("System Error.");
            reales_ls();
            return 0;
        }
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


int search(int a){
    for(node *tem = list;tem != NULL;tem = tem->next){
        if(tem->number == a){
            printf("Found");
            return 0;
        }
    printf("Not Found");
    return 0;    
    }
}