#include <stdio.h>
#include <stdbool.h>


bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //
  FILE * f = fopen(filename, "r");
  if(f == NULL)
  {
    return(false);
  }
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  int onechar;
  do{
    onechar = fgetc(f);

    if(onechar >= 0 && onechar < size)
    {
      counts[onechar]++;
    }
  }while(onechar>-1);
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  fclose(f);
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}


void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  for(int ind = 0; ind < size; ind++)
  {
    if(counts[ind])
    {
      printf("%d, ", ind);
      if((ind >= 'A' && ind <= 'Z') || (ind >= 'a' && ind <= 'z'))
      {
        printf("%c, ", ind);
      }
      else{
        printf(" , ");
      }
      printf("%d\n", counts[ind]);
    }
  }
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
