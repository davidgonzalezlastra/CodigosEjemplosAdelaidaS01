#include <stdio.h> 

/* Pregunta de examen: Un proceso: Ejecuta el codigo 
    fork(); fork(); fork(); 
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(){
    pid_t pid; 
    pid = fork(); 
    pid = fork(); 
    pid = fork(); 

    printf("PID: %d,PPID: %d\n",getpid(),getppid()); 
    sleep(1);  
    return EXIT_SUCCESS;
}