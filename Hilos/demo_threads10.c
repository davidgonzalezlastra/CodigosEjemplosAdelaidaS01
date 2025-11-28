//Compilación: gcc -Wall -std=c17 -pthread -o demo_threads10 demo_threads10.c
//Para ver los hilos que se generan, ejecutar en otro terminal: 
//ps -efL | grep demo_threads

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define NUM_THREADS 10  //Probar tb por ej con 10
#define MAX_COUNT 10000000L // 10 millones

long int counter = 0;

void *f_counter(void *arg) { //prototipo función hilo
   long id;
   id = *(long *)arg;
   printf ("Iniciando %ld\n", id);

   //para demostrar que hilo puede escribir en la pila de otro 
   /*
   long *id; 
   id = (long *)arg;
   printf ("Iniciando %ld\n", *id);
   */

   //Para demo necesidad de sincronización
   
   long int i, max = MAX_COUNT / NUM_THREADS;
   for (i=0; i<max; i++) {
      counter++; //variable global, sección crítica
   }
   printf("Fin %ld. Contador: %ld\n", id, counter);
   

   //para demostrar que hilo puede escribir en la pila de otro 
   /*
   sleep(1);
   *id = *id +100;
   printf("Finalizado %ld\n", *id);
   */

   //printf("Finalizado %ld\n", id);
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
      //para demostrar que hilo puede escribir en la pila de otro 
      //printf("ID %ld -> %ld\n", t, id[t]);

   }


   //Para demo necesidad de sincronización
   
   float error = (MAX_COUNT - counter) / (float)MAX_COUNT * 100;
   printf("Valor contador: %ld. Esperado: %ld. Error: %3.2f%%\n", counter, MAX_COUNT, error);
   
}