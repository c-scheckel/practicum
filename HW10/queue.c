#include "queue.h"
#include "tile_game.h"
#include <stdlib.h>

void enqueue(struct queue *q, struct game_state state) {
  uint64_t serialized = serialize(state);
  insert_at_tail(&q->data, (size_t) serialized);
}

struct game_state dequeue(struct queue *q) { 
  size_t serialized = remove_from_head(&q->data); 
  return deserialize(serialized);}

int solved(struct game_state state){
  uint8_t final[4][4] ={
    {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}
    };
for( int i = 0; i <4; i++){
for(int j=0; j< 4; j++){
if (state.tiles[i][j] != final[i][j]) return 0;
}
}
return 1;
  }

int number_of_moves(struct game_state start) {
  struct queue go;
  go.data.head = NULL;
  enqueue(&go, start);
  size_t cap = 100;
  size_t count = 0;
  uint64_t *visit = malloc(cap * sizeof(uint64_t));

  visit[count++] = serialize(start);

  while (go.data.head != NULL){
    struct game_state cur = dequeue(&go);
    struct game_state next;
    next = cur;
    move_up(&next);
    if(next.num_steps > cur.num_steps){
      if(solved(next)){
        free(visit);
        return next.num_steps;}
      uint64_t serialized = serialize(next);
      int visited = 0;
      for(size_t i = 0; i < count; i++){
        if(visit[i] == serialized){
          visited = 1;
          break;
        }
      }
      if(!visited){
        if(count == cap){
          cap *=2;
          visit = realloc(visit, cap * sizeof(uint64_t));
        }
          visit[count++] = serialized;
          enqueue(&go, next);
      }
    }
    next = cur;
          move_down(&next);
    
     if(next.num_steps > cur.num_steps){
      if(solved(next)){
        free(visit);
        return next.num_steps;}
      uint64_t serialized = serialize(next);
      int visited = 0;
      for(size_t i = 0; i < count; i++){
        if(visit[i] == serialized){
          visited = 1;
          break;
        }
      }
      if(!visited){
        if(count == cap){
          cap *=2;
          visit = realloc(visit, cap * sizeof(uint64_t));
        }
          visit[count++] = serialized;
          enqueue(&go, next);
      }
      }
          next = cur;
          move_left(&next);

      if(next.num_steps > cur.num_steps){
      if(solved(next)){
        free(visit);
        return next.num_steps;}
      uint64_t serialized = serialize(next);
      int visited = 0;
      for(size_t i = 0; i < count; i++){
        if(visit[i] == serialized){
          visited = 1;
          break;
        }
      }
      if(!visited){
        if(count == cap){
          cap *=2;
          visit = realloc(visit, cap * sizeof(uint64_t));
        }
          visit[count++] = serialized;
          enqueue(&go, next);
      }
      }
          next = cur;
          move_right(&next);

         if(next.num_steps > cur.num_steps){
      if(solved(next)){
        free(visit);
        return next.num_steps;}
      uint64_t serialized = serialize(next);
      int visited = 0;
      for(size_t i = 0; i < count; i++){
        if(visit[i] == serialized){
          visited = 1;
          break;
        }
      }
      if(!visited){
        if(count == cap){
          cap *=2;
          visit = realloc(visit, cap * sizeof(uint64_t));
        }
          visit[count++] = serialized;
          enqueue(&go, next);
      }
         }
      }
      
    free(visit);
  free_list(go.data);
        return -1;
      }

