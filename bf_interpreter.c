#include <stdio.h>
#include <stdlib.h>

#define MAX 256

int NowPointer = 0;     //現在の配列番号
int array[MAX];         //配列
int rooparr[MAX];       //[]内を格納する配列
int Roop = 0;           //[]内の実行回数
int RoopFlag = 0;       //[]内かどうかの判別用
int RoopPointer = 0;    //[]用配列の配列番号

void zeroclear(int array[]);    //配列の初期化
void inc_arr();     //配列のインクリメント(>)
void dec_arr();     //配列のデクリメント(<)
void inc();         //要素のインクリメント(+)
void dec();         //要素のデクリメント(-)
void dis();         //表示(.)
void scn();         //読み込み(,)
void roop();        //ループ処理([ ])
void process();     //ループ処理以外をまとめた処理

int main(int argc, char *argv[])
{
    FILE *fp;   //FILE型構造体
    char filename[MAX];
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
        if (chr == (int)('['))
        {
            RoopFlag = 1;
            Roop += array[NowPointer];
        }
        else if (chr == (int)(']'))
        {
            RoopFlag = 0;
            roop();
            Roop = 0;
            RoopPointer = 0;
            zeroclear(rooparr);
        }
        else{
            process(chr);
        }
    }

    fclose(fp);

    return 0;
}

/*関数群*/

void zeroclear(int array[])
{
    int i;
    for (i = 0; i < MAX; i++)
        array[i] = 0;
}

void inc_arr()
{
    if(RoopFlag == 0){
        NowPointer++;
        if (NowPointer >= MAX)
            printf("Array Length over.");
    }
    else{
        rooparr[RoopPointer] = (int)('>');
        RoopPointer++;
    }
}

void dec_arr()
{
    if(RoopFlag == 0){
        NowPointer--;
        if (NowPointer < 0)
            printf("Array Length over.");
    }
    else{
        rooparr[RoopPointer] = (int)('<');
        RoopPointer ++;
    }
}

void inc(){
    if(RoopFlag == 0)
        array[NowPointer]++;
    else{
        rooparr[RoopPointer] = (int)('+');
        RoopPointer++;
    }
}

void dec()
{
    if (RoopFlag == 0)
        array[NowPointer]--;
    else{
        rooparr[RoopPointer] = (int)('-');
        RoopPointer++;
    }
}

void dis(){
    if (RoopFlag == 0)
        putchar(array[NowPointer]);
    else{
        rooparr[RoopPointer] = (int)('.');
        RoopPointer++;
    }
}

void scn(){
    if (RoopFlag == 0)
        array[NowPointer] = getchar();
    else{
        rooparr[RoopPointer] = (int)(',');
        RoopPointer++;
    }
}

void process(int chr){
    if (chr == (int)('>'))
    {
        inc_arr();
    }
    else if (chr == (int)('<'))
    {
        dec_arr();
    }
    else if (chr == (int)('+'))
    {
        inc();
    }
    else if (chr == (int)('-'))
    {
        dec();
    }
    else if (chr == (int)('.'))
    {
        dis();
    }
    else if (chr == (int)(','))
    {
        scn();
    }
}

void roop(){
    int i;
    int j;
    int chr;
    
    for(i = 0; i < Roop; i++){
        for(j = 0; j <= RoopPointer; j++)
        {
            chr = rooparr[j];
            process(chr);
        }
    }
}