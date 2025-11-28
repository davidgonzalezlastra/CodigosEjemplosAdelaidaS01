#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int counter = 0;

int main() {
   pid_t pid = 0;
   int i = 0;
   int status = -1;

   for (i = 0; i < 100; i++) {
      counter++;
   }

   pid = fork();
   printf ("mi PID is %d, mi padre es %d, pid = %d\n", getpid(), getppid(), pid);

   for (i=0; i<100; i++) {
      counter++;
   }

   if (pid == 0) {
      printf("Hijo: valor del contador: %d\n", counter);
      sleep(20);
      exit(3);
   }

   waitpid(pid, &status, 0);
   printf("Padre: valor del contador: %d, status finalización hijo: %d\n", counter, WEXITSTATUS(status));
}