#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    pid_t pid; 
    pid = fork(); 
    if(pid>0 ){// proceso padre 
        printf("Soy el proceso padre y espero 20 segundos antes de terminar, no se nada de mi hijo.\n"); 
        sleep(20);
        }
        else if (pid==0)
        {
            exit(0);
        }
        else { // pid <0 error 
            perror("fork"); 
            exit(EXIT_FAILURE); 

        }
        return EXIT_SUCCESS; 
        
}