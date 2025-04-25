// MODIFY ONLY THIS FILE
// Fill in the function following the instructions in the README

#include "practica_b.h"

ListNode *last(ListNode *list){
	ListNode * cur = list;
	while(cur != NULL){
		cur = cur -> next;
	}
	return cur;
}

ListNode *new(int digit){
  ListNode *retnode = malloc(sizeof(ListNode));
  retnode-> digit = digit;
  retnode-> next = NULL;
  return retnode; }

ListNode *helper(ListNode *list){
	ListNode *first = last(list);
        int digit = first->digit;
        
}




ListNode *add(ListNode *num1, ListNode *num2)
{ 

		
    return NULL;
}

