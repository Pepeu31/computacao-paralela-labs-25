#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    int n = 4;

    for(int i = 0; i < n; i++){
        pid_t pid = fork();
        if(pid == 0){
            printf("Eu sou o filho %d, e meu pid é %d \n", getpid(), getppid());
            exit(0);
        }    
    }

    for(int i = 0; i < n; i++){
        wait(NULL);
    }
        return 0;
}