#include <stdio.h>

#include "../Huffman.h"

void UI_ShowMenu(void) {
    printf("\n================================\n");
    printf("=======  哈夫曼编译码器  =======\n");
    printf("================================\n\n");
    printf("1.对文件字符进行哈夫曼编码\n");
    printf("2.展示字符编码\n");
    printf("3.对文件进行编码\n");
    printf("4.对文件进行解码\n");
    printf("5.对文件进行压缩\n");
    printf("6.对文件进行解压缩\n");
    printf("7.前后文件对比\n");
    printf("8.退出\n\n");
    printf("================================\n\n");
    printf("您要执行的操作为: ");
}