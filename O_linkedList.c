#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int number;
    struct node *next;
}
node;

int main(void){
    node *list;
    int size;
    node *temp;
    node *current;

    printf("Enter the number of data you want to store ");
    scanf(" %i",&size);

    for(int i = 0; i < size; i++){
        temp = malloc(sizeof(node));
        if (temp == NULL){
          if(i == 0){
            free(temp);
            return 1;
          }
          for(node *tem = list;tem != NULL;tem=tem->next){
            free(tem);
            return 1;
          }
        }
        printf("Enter element:  ");
        scanf(" %i",&temp->number);
        temp->next = NULL;
        if(i == 0){
            current = temp;
            list = current;

        }
        else{
        current->next = temp;
        current = temp;

        }
    }
    for(node *tem = list;tem != NULL;tem = tem->next){
      printf("%i ",tem->number);
    }
    printf("\n ");
    printf("\n");

    for(node *tem = list;tem != NULL;tem = tem->next){
      free(tem);
    }


}
