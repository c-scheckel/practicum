#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "assert.h"
#include "string.h"

typedef struct _list_node
{
    int digit;
    struct _list_node *next;
} ListNode;

ListNode *add(ListNode *num1, ListNode *num2);

#endif