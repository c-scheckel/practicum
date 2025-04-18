#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) { 
  struct list_node *retnode = malloc(sizeof(struct list_node));
  retnode-> value = value;
  retnode-> next = NULL;
  return retnode; }

void insert_at_head(struct linked_list *list, size_t value) {
  struct list_node **loc = &list->head;
  struct list_node *new = new_node(value);
  new->next = *loc;
  *loc = new;
}

void insert_at_tail(struct linked_list *list, size_t value) {
  struct list_node **loc = &list-> head;
  while(*loc != NULL){
    loc = &((*loc)->next);
  }
  *loc = new_node(value);
}

size_t remove_from_head(struct linked_list *list) {
  struct list_node **loc = &list-> head;
  struct list_node *del = *loc;
  size_t retval = del ->value;
  *loc = del->next;
  free(del);
  return retval; }

size_t remove_from_tail(struct linked_list *list) {
  struct list_node **loc = &list-> head;
  while(*loc != NULL){
    loc = &((*loc)->next);
  }
  struct list_node *del = *loc;
  size_t retval = del ->value;
  *loc = del->next;
  free(del);
  return retval; }

void free_list(struct linked_list list) {
  struct list_node *node = list.head;
  while(node != NULL){
    struct list_node *next = node->next;
    free(node);
    node = next;
  }
  list.head = NULL;
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
