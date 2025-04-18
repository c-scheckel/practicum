// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  // You may initialize the elements to a number of your choice (e.g., 0)
  for(int i = 0; i < n; i++)
    {
      arr[i] = 1;
    }

  // counting to k,
  // mark the eliminated element; you choose the mark (e.g., 1)
  // print the index of the marked element
  // repeat until only one element is unmarked
  int count = 0;
  int index = 0;
  int subcount;
  int lastValid;
  while(count < n - 1)
    {
      subcount = 1;
      while(subcount < k + 1)
        {
          if(arr[index] && subcount == k)
            {
              lastValid = index;
              printf("%d\n", lastValid);
              arr[index] = 0;
              subcount++;
            } 
          else if(arr[index])
            {
              subcount++;
            }
          if(index < n - 1)
            { 
              index++;
            }
          else
          {
            index = 0;
          }
        }
      count++;
    }  
  // print the last remaining index
  lastValid = 0;
  while(!arr[lastValid])
    {
      lastValid++;
    }
  printf("%d\n", lastValid);


  // release the memory of the array
  free (arr);
}

