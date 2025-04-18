#include <stdio.h>
#include <stdbool.h>


bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  *sum = 0;
  int temp;
  // open a file whose name is filename for reading
  FILE * f = fopen(filename, "r");
  // if fopen fails, return false. Do NOT fclose
  if(f == NULL)
  {
    return(false);
  }
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  int condition;
  
  while(fscanf(f, "%d", &temp) == 1)
    {
    *sum += temp;
    }
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  fclose(f);
  //
  return true;
}



bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  FILE * f = fopen(filename, "w");
  if(f == NULL)
  {
    return(false);
  }
  // if fopen succeeds, write sum as an integer using fprintf
  fprintf(f, "%d\n", sum);
  // fprintf should use one newline '\n'
  // fclose, return true
  fclose(f);
  //
  return true;
}