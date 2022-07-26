#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFSIZE 1024


int main()
{
    pid_t pid;
    int pd[2];
    int len;
    char buf[BUFSIZE];

    if(pipe(pd) < 0)
    {
        perror("pipe()");
        exit(1);
    }

    pid = fork();
    if(pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if(pid == 0)
    {
        close(pd[1]);
        len = read(pd[0], buf, BUFSIZE);
        write(1, buf, len);
        write(1, "\n", 1);
        close(pd[0]);
        exit(0);
    }
    else
    {
        close(pd[0]);
        write(pd[1], "Hello!", 6);
        close(pd[1]);
        wait(NULL);
        exit(0);
    }
}