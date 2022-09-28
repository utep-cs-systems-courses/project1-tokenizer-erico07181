#include "stdlib.h"
#include <string.h>
#include <stdio.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history(){
    List *head = malloc(sizeof(List));
    return head;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
    //If the root of list is null, we should make the str the new root of list

    char *p = malloc(64 * sizeof(char));
    strcpy(p, str);
    Item *node = malloc(sizeof(Item));
    node->str = p;
    if(list->root == NULL){
        list->root = node;
        printf("Head? %s\n" ,node->str);
    }
    //If the root is NOT null, we should make root next equal to str
    else{
        Item *tmp = list->root;
        while(tmp->next != NULL){
            printf("Traverse \n");
            tmp = tmp->next;
        }
        tmp->next = node;
        node->next = NULL;
        printf("New node str: %s\n", node->str);
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id);

/*Print the entire contents of the list. */
void print_history(List *list){
    while(list != NULL){

    }
}

/*Free the history list and the strings it references. */
void free_history(List *list);
