#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cachedqueue.h"
#include "queue.h"


void cached_queue_init(CachedQueue* const me, char *fname, 
                int(*is_full_function)(CachedQueue* const me),
                int (*is_empty_function)(CachedQueue* const me),
                int (*get_size_function)(CachedQueue* const me),
                void (*insert_function)(CachedQueue* const me, int k),
                int (*remove_function)(CachedQueue* const me),
                void (*flush_function)(CachedQueue* const me),
                void (*load_function)(CachedQueue* const me)){

  // inicializacao classe base
  me->queue = queue_create();

  //iniciarlizacao atributos subclass
  me->number_elements_on_disk = 0;
  strcpy(me->filename,fname);

  //inicializacao agregatores
  me->output_queue = queue_create();

  //inicializacao funcoes virtuais da subclasse
  me->is_full = is_full_function;
  me->is_empty = is_empty_function;
  me->get_size = get_size_function;
  me->insert = insert_function;
  me->remove = remove_function;
  me->flush = flush_function;
  me->load = load_function;
}

void cached_queue_cleanup(CachedQueue *const me){
  queue_cleanup(me->queue);
}

int(cached_queue_is_full)(CachedQueue* const me){
  return me->queue->is_full(me->queue) && me->output_queue->is_full(me->output_queue);
}
int (cached_queue_is_empty)(CachedQueue* const me){
  return me->queue->is_empty(me->queue) && 
         me->output_queue->is_empty(me->output_queue) &&
         me->number_elements_on_disk == 0;
}
int (cached_queue_get_size)(CachedQueue* const me){
  return me->queue->get_size(me->queue) +
         me->output_queue->get_size(me->output_queue) +
         me->number_elements_on_disk;
}
void (cached_queue_insert)(CachedQueue* const me, int k){
  if(me->queue->is_full(me->queue)) me->flush(me);
  me->queue->insert(me->queue,k);
}
int (cached_queue_remove)(CachedQueue* const me){
  if(!me->output_queue->is_empty(me->output_queue)){
    return me->output_queue->remove(me->output_queue);
  }
  else if(me->number_elements_on_disk > 0){
    me->load(me);
    return me->queue->remove(me->queue);
  } else {
    return me->queue->remove(me->queue);
  }
}

void (cached_queue_flush)(CachedQueue* const me){

}
void (cached_queue_load)(CachedQueue* const me){

}


CachedQueue *cached_queue_create(void){
  CachedQueue* me = (CachedQueue*) malloc(sizeof(CachedQueue));
  if(me!=NULL){
    cached_queue_init(me, 
                      "end://arquivo.dat", 
                      cached_queue_is_full,
                      cached_queue_is_empty,
                      cached_queue_get_size,
                      cached_queue_insert,
                      cached_queue_remove,
                      cached_queue_flush,
                      cached_queue_load);
  }
  return me;
}
void cached_queue_destroy(CachedQueue* const me){
  if(me!=NULL){
    cached_queue_cleanup(me);
  }
  free(me);
}
