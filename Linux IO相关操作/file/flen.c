#include<stdio.h>
#include<stdlib.h>

#define BUFSIZE 1024
//操作文件位置指针 
// 
//fseek重定义 流上的指针位置
//ftell 返回一个文件指针当前位置值
int main(int argc, char **argv)
{
    FILE *fp;

    if(argc < 2)
    {   
        fprintf(stderr, "Usage:%s <file>\n",argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "r");
    if(fp == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);//SEEK_CUR	 SEEK_SET
    printf("%ld\n", ftell(fp));

    fclose(fp);

    exit(0);
}
