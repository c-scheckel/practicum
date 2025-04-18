#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grid_traversal.h"

char** read_grid_from_file(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file");
        return NULL;
    }

    fscanf(file, "%d %d", rows, cols);


    char** grid; 
    
    // Allocate memory for the grid here with the correct dimensions
    grid = malloc(*rows * sizeof(char*));
    int i;
    for(i = 0; i< *rows; i++){
        grid[i] = malloc(*cols * sizeof(char));
    }


    for (i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            fscanf(file, " %c", &grid[i][j]);
        }
    }

    fclose(file);
    return grid;
}

void free_grid(char **grid, int rows) {
    
    // Free the memory allocated for the grid here
    int i;
    for( i= 0; i < rows; i++){
        free(grid[i]);
    }
    free(grid);
}


bool lexicographically_smallest_path_util(char **grid, int rows, int cols, int x, int y, char* path, int pos) {

    // First write your base case : If the destination is reached return an appriopriate value
    if(grid[x][y] == END){
        path[pos] = '\0';
        printf("%s\n", path);
        return true;
    }

    // Implement the recursive step here.
    int east = y +1;
    if(east < cols){ 
        char move = grid[x][east];
        if(move == SPACE || move == END){
        path[pos] = EAST;
        if(lexicographically_smallest_path_util(grid, rows, cols, x, east, path, pos+1)) return true;
    }
        path[pos] = '\0';
    }
    int south = x+1;
    if(south < rows){
        char move = grid[south][y];
        if(move == SPACE || move == END){
        path[pos] = SOUTH;
        if(lexicographically_smallest_path_util(grid, rows, cols, south, y, path, pos+1)) return true;
    }    
        path[pos] = '\0';
    }
    path[pos] = '\0';
    return false;
    /*
    Below is the description of this function from the readme. You should think about how to implement this logic.

    This function uses recursion to find the lexicographically smallest path 
    from the START cell to the END cell, and print the path as a sequence of moves. 
    Only moves to the right (East) and down (South) are allowed. 
    Since we are travelling from the upper leftmost square to the lower rightmost 
    square and we can only move south or east, any valid path will have the 
    same number of south and east moves regardless of obstacles in the grid. Thus, 
    the lexicographical smallest path is the valid path where we always move east when 
    we can, and move south only when we have to. Thus, using recursion, you need to find 
    the path where you move east until you cannot move east anymore (because of an obstacle 
    or because you reached the boudanries of your grid), then move south just enoough until 
    you can move east again (if you can), until you reach the END square. 
    */

    /* Hint :
    You should first check if you can move east, then check if you can move south.
    If a path in invalid because of an obstacle, you should cancel this path.
    Cancelling the path is equivalent to cancelling the last move you made, 
    or cancelling the last 2 moves, or 3... etc, as many as you need. This is called backtracking.
    */
   

    // If no path is valid, return appropriate value (think about what would be 
    // useful for`lexicographically_smallest_path` to know when no path is found)

}



void lexicographically_smallest_path(char **grid, int rows, int cols) {
    
    // Initialize an array of characters of size 100 to store the path
    char path[100];
    // Intialize a position tracker to append characters to the path correctly
    int pos = 0;

    // Make sure the START and the END squares are in the grid. If they are not print NA and return
    int foundS = (grid[0][0] == START);
    int foundE = 0;
    int i = 0;
    int j;
    while(!foundE && i < rows){
        for(j = 0; j < cols; j++){
            if(grid[i][j] == END){
                foundE = 1;
                break;
            }
        }
        i++;
    }
    if(!foundS || !foundE){
        printf("NA\n");
        return;}
    // Call the utility function `lexicographically_smallest_path_util` with the correct parameters 
    // You can either look for the START square or hardcode it since we always start from the top left corner
    if (!lexicographically_smallest_path_util(grid, rows, cols, 0, 0, path, pos)) {
    printf("-1\n"); 
    }
    // Check if the utility function found a path, and print the path if it did
    // If no path is found, print -1
    // Reminder for printing : To use printf("%s", ...) to print an array of characters in C, 
    // you need to add a null character at the end of the array to make it a string
}
