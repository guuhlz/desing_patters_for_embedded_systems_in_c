#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main (int argc, char *argv[])
{
  int j,k,h,t;
  
  Queue *myQ;
  myQ = queue_create();

  k = 1000;

  for(j=0; j<QUEUE_SIZE;j++){
    h = myQ->head;
    myQ->insert(myQ,k);
    printf("inserindo %d na posicao %d, size=%d\n",k--,h,myQ->get_size(myQ));
  };

  printf("Inserido %d elementos\n",myQ->get_size(myQ) );

  for(j=0; j<QUEUE_SIZE;j++){
    t = myQ->tail;
    myQ->remove(myQ);
    printf("removendo %d na posicao %d, size=%d\n",myQ->buffer[j],t,myQ->get_size(myQ));
  };

  printf("Ultimo item removido = %d\n",k);
  return 0;
}
