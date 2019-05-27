#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int NowPointer = 0;

void zeroclear(int array[])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        array[i] = 0;
    }
}

int main(int argc, char *argv[])
{
    FILE *fp;   //FILE型構造体
    char filename[MAX];
    int array[MAX];
    char chr;

    printf("Please input Filename:");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("File Load Error.");
        return -1;
    }

    zeroclear(array);

    while ((chr = fgetc(fp)) != EOF)
    {
        
        if(chr == (int)('>'))
        {
            NowPointer ++;
            if(NowPointer >= MAX){
                printf("Array Length over.");
            }
        }
        else if (chr == (int)('<'))
        {
            NowPointer --;
            if (NowPointer < 0)
            {
                printf("Array Length over.");
            }
        }
        else if (chr == (int)('+'))
        {
            array[NowPointer] ++;
        }
        else if (chr == (int)('-'))
        {
            array[NowPointer] --;
        }
        else if (chr == (int)('.'))
        {
            putchar(array[NowPointer]);
        }
    }

    fclose(fp);

    return 0;
}