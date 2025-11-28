#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* Uso de constantes a modo visual para definir que proceso 
es cada un0*/

#define RESET "\033[0m"
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32m"
#define AZUL "\x1b[34m"
#define BLANCO "\x1b[97m"


/**
 * Programa principal
 */

 int main(){
    pid_t pid; 
    pid = fork();

    printf("pid: %d\n",pid); 

    /*Verificación de cada accion a realizar en función de si es padre o hijo 

    */
   if(pid==0){ // es el proceso hijo entonces haz
    printf(VERDE "HIJO: getpid() o sea PID del proceso HIJO: %d\n"RESET,getpid()); usleep(10); 
    printf(VERDE"HIJO: getppid(), o sea PID del proceso padre: %d\n "RESET,getppid()); usleep(10); 
    exit(EXIT_SUCCESS);    
}else if (pid>0) { // estonces es el padre
    printf(BLANCO "PADRE: pid recibido del fork(), es decir PID del proceso del hijo: %d\n" RESET, pid);usleep(10);
    printf(BLANCO "PADRE: getpid() o sea PID del proceso padre: %d\n"RESET, getpid()); usleep(10); 
    printf(BLANCO "PADRE: getppid() o sea PID del padre del padre: %d\n"RESET,getppid()); usleep(10);
    
}else{ // tratamiento de error porque pid <0 
    perror("fork");
    exit (EXIT_FAILURE); 
}

return EXIT_SUCCESS; 


 }