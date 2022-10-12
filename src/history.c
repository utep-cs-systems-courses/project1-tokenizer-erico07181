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
        node->id = 0;
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
        printf("Tmp ID: %i", tmp->id);
        node->id = tmp->id += 1;
        node->next = NULL;
        printf("New node str: %s\n", node->str);
    }
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  printf("Id begin %i \n", id);
    char err = '\n';
  char *errP = &err;
  if(list->root){
    Item *curr_node = list->root;
    int old = id;
    
    while(curr_node && id>0){
        printf("In while\n");
      curr_node = curr_node->next;
      id--;
    }
    printf("%i\n", id);
    if(id == 0 && curr_node != 0){
        printf("here bro\n");
        return (*curr_node).str;
    }
    else{
      printf("ID out of range\n");
      return errP;
    }
  }
  else{
    printf("No history yet!\n");
    return errP;
  }
}
/*Print the entire contents of the list. */
void print_history(List *list){
    if(list->root){
        int loc = 0;
        Item *curr_node = list->root;
        while(curr_node){
            printf("%d: %s", loc, curr_node->str);
            curr_node = curr_node->next;
            loc++;
        }
    }
    else{
        printf("No history to be displayed :(\n");
    }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
    if(list->root){
        Item *curr_node = list->root;
        Item *next_node = curr_node;
        while(curr_node != 0){
            next_node = curr_node->next;
            free(curr_node->str);
            free(curr_node);
            curr_node = next_node;
        }
    }
    free(list);
}
