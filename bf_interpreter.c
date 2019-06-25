#include <stdio.h>
#include <stdlib.h>

//配列の最大要素
#define ARRMAX 256
//ループの最大ネスト
#define NESTMAX 32
//ソースコードの最大文字数
#define CODEMAX 10000

//命令群
#define GRATER 62   // >
#define LESS 60     // <
#define PLUS 43     // +
#define MINUS 45    // -
#define PERIOD 46   // .
#define COMMA 44    // ,
#define START 91    // [
#define END 93      // ]

typedef struct roop
{
    int start;
    int end;
    int state;
} roop;

int main(int argc, char *argv[])
{
    FILE *fp;   //FILE型構造体

    int NowPointer = 0; //現在いる配列の配列番号
    
    int Array[ARRMAX] = {0};    //bf内の配列
    int Code[CODEMAX] = {0};    //ソースコードを格納
    roop Roop[NESTMAX];

    int i;              //forループで使用
    int RoopNest = 0;   //ループの深さ
    int chr;            //fgetcの返り値を格納
    int len = 0;        //命令の格納に使用

    if(argc == 2){
        fp = fopen(argv[1], "r");
        if (fp == NULL){
            printf("ファイルの読み込みエラー");
            return -1;
        }
    }
    else{
        printf("引数エラー");
        return -1;
    }
    
    while((chr = fgetc(fp)) != EOF)
    {
        if(len < CODEMAX){
            switch(chr){
                case GRATER:
                case LESS:
                case PLUS:
                case MINUS:
                case PERIOD:
                case COMMA:
                case START:
                case END:
                    Code[len] = chr;
                    len++;
                    break;
                default:
                    break;
            }
        }
        else{
            printf("ソースコード格納エラー");
            return -1;
        }
    }

    for(i = 0; i<NESTMAX; i++){
        Roop[i].start = 0;
        Roop[i].end = 0;
        Roop[i].state = 0;
    }

    i = 0;
    while(i < len)
    {
        switch( Code[i] ){
            case GRATER:
                NowPointer++;
                i++;
                break;
            case LESS:
                NowPointer--;
                if(NowPointer < 0){
                    printf("配列の範囲外エラー");
                    exit(-1);
                }
                i++;
                break;
            case PLUS:
                Array[NowPointer]++;
                i++;
                break;
            case MINUS:
                Array[NowPointer]--;
                if(Array[NowPointer] < 0){
                    printf("配列の値エラー");
                    exit(-1);
                }
                i++;
                break;
            case PERIOD:
                printf("%c", Array[NowPointer]);
      
                i++;
                break;
            case COMMA:
                scanf("%d", &chr);
                Array[NowPointer] = chr;
                i++;
                break;
            case START:
                if(Roop[RoopNest].state == 0){
                    RoopNest++;
                    Roop[RoopNest].start = i;
                    Roop[RoopNest].state = 0;
                }
                else if(Roop[RoopNest].state == 1){
                    Roop[RoopNest].state = 0;
                }

                if(Array[NowPointer] == 0){
                    i = Roop[RoopNest].end;
                    break;
                }
                i++;
                break;
            case END:
                if (Array[NowPointer] != 0){
                    Roop[RoopNest].end = i;
                    Roop[RoopNest].state = 1;
                    i = Roop[RoopNest].start;
                }
                else{
                    Roop[RoopNest].start = 0;
                    Roop[RoopNest].end = 0;
                    Roop[RoopNest].state = 0;
                    RoopNest--;
                    i++;
                }
                break;
        }
    }
    return 0;
}
