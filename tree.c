#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next1;;
    struct node *next2;
}
node;
int print_ls(node *tree);
int clean_mr(node *tree);

int main(void){
    node *tree = NULL;

    node *temp = malloc(sizeof(node));
    if(temp == NULL){
        free(temp);
        return 1;
    }
    temp->number = 5;
    temp->next1 = NULL;
    temp->next2 = NULL;

    tree = temp;
    
    temp = malloc(sizeof(node));
    if(temp == NULL){
        free(tree);
        free(temp);
        return 1;
    }
    temp->number = 4;
    temp->next1 = NULL;
    temp->next2 = NULL;

    tree->next1 = temp;

    temp = malloc(sizeof(node));
    if(temp == NULL){
        free(temp);
        free(tree->next1);
        free(tree);
        return 1;
    }
    temp->number = 6;
    temp->next1 = NULL;
    temp->next2 = NULL;

    tree->next2 = temp;

    print_ls(tree);
    clean_mr(tree);

    
}
int print_ls(node *tree){
    if(tree == NULL){
        return 0;
    }
    print_ls(tree->next1);
    printf("%i\n",tree->number);
    print_ls(tree->next2);
    return 0;
}

int clean_mr(node *tree){
    if(tree == NULL){
        return 0;
    }
    clean_mr(tree->next1);
    clean_mr(tree->next2);
    free(tree);
    return 0;
}
