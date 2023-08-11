#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/* struct Queue{
  int buffer[QUEUE_SIZE];
  int head;
  int size;
  int tail;
  int (*is_full)(Queue* const me);
  int (*is_empty)(Queue* const me);
  int (*get_size)(Queue* const me);
  void (*insert)(Queue* const me, int k);
  int (*remove)(Queue* const me);
}; */


void queue_init(Queue *const me, 
                int (*is_full_function)(Queue *const), 
                int (*is_empty_function)(Queue *const), 
                int (*get_size_function)(Queue *const), 
                void (*insert_function)(Queue *const, int k), 
                int (*remove_function)(Queue *const)){

  me->head = 0;
  me->size = 0;
  me->tail = 0;
  me->is_full = is_full_function;
  me->is_empty = is_empty_function;
  me->get_size = get_size_function;
  me->insert = insert_function;
  me->remove = remove_function;

}

void queue_cleanup(Queue* const me){

}

int(queue_is_full)(Queue* const me){
  return (me->head + 1) % QUEUE_SIZE == me->tail;
}
int (queue_is_empty)(Queue* const me){
  return (me->head == me->tail);
}
int (queue_get_size)(Queue* const me){
  return me->size;
}
void (queue_insert)(Queue* const me, int k){
  if(!me->is_full(me)){
    me->buffer[me->head]= k;
    me->head = (me->head+1) % QUEUE_SIZE;
    ++me->size;
  }
}
int (queue_remove)(Queue* const me){
  int value = -9999;
  if(!me->is_empty(me)){
    value = me->buffer[me->tail];
    me->tail= (me->tail+1) % QUEUE_SIZE;
    --me->size;
  }
  return value;
}

Queue *queue_create(void){
  Queue *me = (Queue*)malloc(sizeof(Queue));
  if(me!=NULL){
    queue_init(me,queue_is_full,queue_is_empty,queue_get_size,queue_insert,queue_remove);
  }
  return me;
}
void queue_destroy(Queue* const me){
  if(me!=NULL){
    queue_cleanup(me);
  }
  free(me);
}
