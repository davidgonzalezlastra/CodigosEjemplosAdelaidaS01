//Compilación: gcc -Wall -std=c17 -pthread -o demo_threads demo_threads.c
//En otro terminal: ps -efL | grep demo_threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM_THREADS 2
#define MAX_COUNT 10000000L //10 millones

long int counter = 0;

void *f_counter(void *arg) {
   long id;

   id = *(long *)arg;

   printf ("Iniciando %ld\n", id);

   
   long int i, max = MAX_COUNT / NUM_THREADS;
   for (i=0; i<max; i++) {
      counter++; //variable global, sección crítica
   }
   printf("Fin %ld. Contador: %ld\n", id, counter);
   
   sleep(2);
   printf("Finalizado %ld\n", id);
   pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;
   long id[NUM_THREADS];

   for (t=0; t < NUM_THREADS; t++) {
      id[t] = t;
      rc = pthread_create(&threads[t], NULL, f_counter, (void *)&id[t]);
      if (rc) {
         printf("ERROR: %d\n", rc);
         exit(-1);
      }
   }

   //puts("Voy a mi bola\n");

   for (t = 0; t < NUM_THREADS; t++) {
      pthread_join(threads[t], NULL);
   }

   
   float error = (MAX_COUNT - counter) / (float)MAX_COUNT * 100;
   printf("Valor contador: %ld. Esperado: %ld. Error: %3.2f%%\n", counter, MAX_COUNT, error);
   
}