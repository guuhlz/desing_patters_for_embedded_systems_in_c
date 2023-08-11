#ifndef CACHEDQUEUE_H_
#define CACHEDQUEUE_H_

#include "queue.h"

typedef struct CachedQueue CachedQueue;

struct CachedQueue {
  Queue *queue; //classe base
  // novos atributos
  char filename[80];
  int number_elements_on_disk;
  // agrecacao na subclasse
  Queue* output_queue;
  
  //funcoes virtuais herdadas
  int (*is_full)(CachedQueue* const me);
  int (*is_empty)(CachedQueue* const me);
  int (*get_size)(CachedQueue* const me);
  void (*insert)(CachedQueue* const me, int k);
  int (*remove)(CachedQueue* const me);
  //novas funcoes virtuais
  void (*flush)(CachedQueue* const me);
  void (*load)(CachedQueue* const me);
  
};

//construtor
void cached_queue_init(CachedQueue* const me, char *fname, 
                int(*is_full_function)(CachedQueue* const me),
                int (*is_empty_function)(CachedQueue* const me),
                int (*get_size_function)(CachedQueue* const me),
                void (*insert_function)(CachedQueue* const me, int k),
                int (*remove_function)(CachedQueue* const me),
                void (*flush_function)(CachedQueue* const me),
                void (*load_function)(CachedQueue* const me));

void cached_queue_cleanup(CachedQueue * const me);

// operacoes
int(cached_queue_is_full)(CachedQueue* const me);
int (cached_queue_is_empty)(CachedQueue* const me);
int (cached_queue_get_size)(CachedQueue* const me);
void (cached_queue_insert)(CachedQueue* const me, int k);
int (cached_queue_remove)(CachedQueue* const me);
void (cached_queue_flush)(CachedQueue* const me);
void (cached_queue_load)(CachedQueue* const me);

CachedQueue *cached_queue_create(void);
void cached_queue_destroy(CachedQueue* const me);

#endif
