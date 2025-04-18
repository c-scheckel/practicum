// ***
// *** You MUST modify this file
// ***

#include "hw5.h"

void StudentPrint(Student *stu, int num)
{
    printf("There are %d students\n", num);
    for (int ind = 0; ind < num; ind++)
    {
        printf("ID = %d, Name = %s\n", stu[ind].ID, stu[ind].name);
    }
}

// count the number of '\n' to determine the number of records
int countNewLine(FILE *fptr)
{
    int numline = 0;
    while (!feof(fptr))
    {
        int onechar = fgetc(fptr);
        if (onechar == '\n')
        {
            numline++;
        }
    }
    return numline;
}

/* This is the first function you need to implement */
bool StudentRead(char *filename, Student **stu, int *numelem)
{
    /* 1.1: open the file to read */
    FILE *fptr = fopen(filename, "r");
    if(fptr == NULL){
    return false;
     }
    // the name of the file to open is stored in filename
    // if fopen fails, return false
    // do not use fclose since fopen already fails

    /* end of 1.1: open the file to read */

    int numline = countNewLine(fptr);

    // return to the beginning of the file
    // you can use fseek or
    // fclose followed by fopen
    // You need to check whether fseek or fopen fails
    // Do not use rewind because it does not report whether it fails
    int rtv; // return value
    rtv = fseek(fptr, 0, SEEK_SET);
    if (rtv == -1) // fseek fails
    {
        fclose(fptr);
        return false;
    }

    /* 1.2 allocate memory for the data */
    Student *stuptr = malloc(numline * sizeof(Student));
    if(stuptr == NULL){
        fclose(fptr);
        return false;
    }
    
    // stuptr is an array of type Student
    // refer to hw5.h to understand the type Student
    // the number of elements in this array is numline
    // use the malloc function
    // check whether memory allocation fails

    /* end of 1.2: allocate memory for the data */

    /* 1.3: read data from the file */
    int i;
    for(i = 0; i < numline; i++){
        fscanf(fptr, "%d %s", &stuptr[i].ID, stuptr[i].name);
    }
        
    // read the data from the file
    // store the data to the array stuptr
    // fclose the file after read of data is done
    fclose(fptr);
    /* end of 1.3: read data */

    *numelem = numline;
    *stu = stuptr;
    return true;
}

/* This is the second function you need to implement */
bool StudentWrite(char *filename, Student *stu, int numelem)
{
    // open the file to write
    // the name of file to open is stored in string filename
    // if fopen fails, return false
    // do not use fclose since fopen already fails
    // stu is an array of type Student
    // refer to hw5.h to understand the type Student
    // the number of elements in array stu is numelem
    FILE *fptr = fopen(filename, "w");
    if(fptr == NULL){
    return false;
     }
    // write the data from array stu to the opened file
    // fclose the file in the end
    int i;
    for(i = 0; i < numelem; i++){
        fprintf(fptr, "%d %s\n", stu[i].ID, stu[i].name);
}
    fclose(fptr);
    return true;
}

/* This is the third function you need to implement */
void sortStudents(Student *stu, int numelem, int (*compar)(const void *, const void *))
{
    /* Fill in to call qsort function to sort array stu */
    qsort(stu, numelem, sizeof(Student), compar);
    // stu: an array of Students. numelem: number of elements in the array. compar: comparison function
    // refer to hw5.h to understand the type Student
}

/* This is the fourth function you need to implement */
int compareID(const void *p1, const void *p2)
{
    /* Fill in to compare p1 and p2 by id */
    Student id1 = *(const Student*)p1;
    Student id2 = *(const Student*)p2;
    // return a negative value if the ID of the first student is smaller
    if(id1.ID < id2.ID) return -1;
    // return a positive value if the ID of the first student is larger
    if(id1.ID > id2.ID) return 1;
    // return zero if the IDs of the two students are the same
    if(id1.ID == id2.ID) return 0;
    else{
    return 0;
     }
}

/* This is the fifth function you need to implement */
int compareName(const void *p1, const void *p2)
{
    /* Fill in to compare p1 and p2 by name */
    Student name1 = *(const Student*)p1;
    Student name2 = *(const Student*)p2;
    // use strcmp function to compare two strings
    // return a negative value if the name of the first student is alphabetically earlier
    // return a positive value if the name of the first student is alphabetically later
    // return zero if the names of the two students are the same
    int value = strcmp(name1.name, name2.name);
    return value;
}

/* This is the sixth function you need to implement */
bool areStudentsSorted(Student *stu, int numelem, int (*compar)(const void *, const void *))
{
    int i;
    for(i = 0; i < numelem - 1; i++){
        if ((compar(&stu[i], &stu[i+1])) > 0){
            return false;
        }
    }
    return true;
        
    /* Fill in to check if the stu array is sorted according to compar */
    // return true if the stu array is sorted according to compar
    // return false otherwise
    // refer to hw5.h to understand the type Student
}
