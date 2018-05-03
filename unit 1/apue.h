#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

void err_exit(const char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}

void err_print(const char *msg)
{
    fputs(msg, stderr);
    fputc('\n', stderr);
}

void err_sys(const char *name)
{
    perror(name);
    exit(1);
}

//1. in root
//2. in apue.h dir
//3. cp -r apue.h /usr/include


