# bf_interpreter

C言語を用いて作成した Brainf*ck のインタプリタです．

## 導入

以下のコマンドを入力します．

`$ gcc bf_interpreter.c -o bf`

## 実行方法

以下のコマンドを入力します．
xxxxx.b は任意のBrainf*ckのコードです．

`$ ./bf.exe xxxxx.b`

## 独自機能

追加のコマンドライン引数に任意の整数を与えることで,初期配列に値を格納することが可能です．

### 一例

以下のコードは配列 a[0] と a[1] の値を加算し，表示するコードです．  
このとき，加算結果が10未満である必要があります．

`>[-<+>]++++++++[-<++++++>]<.`

追加のコマンドライン引数に2と3を与えました．

    $ ./bf.exe sample.b 2 3
    5


---    

Brainf*ck's interpreter written in C.

## Install

Enter the following command to create an executable file.

`$ gcc bf_interpreter.c -o bf`

## How to use

Enter the following commad ( xxxxx.b is any brain f*ck file ) .

`$ ./bf.exe xxxxx.b`

## Unique function

You can assign values ​​to the initial array by giving integers to command line arguments.

### Example

The following code is a code that displays the result of adding the values ​​of a[0] and a[1].  
( The sum must be less than 10 )

`>[-<+>]++++++++[-<++++++>]<.`

Display the result of running the program with 2 and 3 command line arguments.

    $ ./bf.exe sample.b 2 3
    5
