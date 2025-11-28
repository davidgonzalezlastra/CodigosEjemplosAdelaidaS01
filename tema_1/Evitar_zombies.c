
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(){
    int estado; 
    pid_t pid; 

    pid = fork(); 
    if (pid>0){
        pid_t pid_acabado; 
        pid_acabado = wait(&estado); 
        printf("Soy el proceso padre, mi proceso hijo ha terminado"); 
        printf("Y yo ahora espero 10 segundos antes de terminar\n"); 
        printf("pid_acabado:%d\n",pid_acabado); 
        printf("Estado:%d\n",estado); 
        sleep(20); 
    }
    else if (pid ==0)
    {
        printf("pid del hijo: %d\n",getpid()); 
        sleep(5); 
        exit(0); 
    }
    else
    {
        perror("fork"); 
        exit(EXIT_FAILURE); 
    }
    return EXIT_SUCCESS; 
    
    
}