#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../Huffman.h"

void UI_Entrance(void) {

    char sourceName[50];
    char *code;
    char *enciName = "lft.enci";
    char *deenciName = "lft.deenci";
    char *compName = "lft.comp";
    char *decompName = "lft.decomp";

    int choice;
    int alphaAccount = 0;
    int alphaIndex[256] = {0};
    int bitCount = 0;

    FILE *fp;

    HUFFMAN_TABLE *Huf;
    FREQ *freqPoint;

    printf("请输入源文件名称(默认路径在当前目录下)：");
    gets(sourceName);

    fp = fopen(sourceName, "rb");
    if (fp == NULL) {
        printf("读取文件出错\n");
        exit(0);
    }

    // 获取源文件中所有不同种类的字符个数，并同时改变 ASCII 字符数组的值且为 FREQ 结构体变量分配连续空间并初始化
    alphaAccount = Handle_GetFreq(fp, &freqPoint, alphaIndex);

    printf("alphaAccount: %d\n", alphaAccount);

    // 根据统计文件字符后生成的 FREQ 结构体变量后初始化 HUFFMAN_TABLE 结构体变量
    Huf = Build_InitHuffTree(freqPoint, alphaAccount);
    // 根据统计文件字符后生成的 FREQ 结构体变量后创建 HUFFMAN_TABLE 结构体变量内容
    Huf = Build_CreateHuffTree(freqPoint, alphaAccount);

    while (1) {
        // 在读取成功源文件并生成相应哈夫曼树作为压缩准备，显示 UI 层欢迎菜单
        UI_ShowMenu();
        // 选择想要进行的操作
        scanf("%d", &choice);
        printf("================================\n\n");
        switch (choice) {
            // 根据生成后的 HUFFMAN_TABLE 结构体变量对文件字符进行最优编码
            case 1:
                // 分配源文件不同字符个数个字符空间
                code = (char*)malloc(sizeof(char)*alphaAccount);
                // 将该空间传递，完善连续空间中每一个 HUFFMAN_TABLE 结构体变量相应的编码数组
                Build_MakeHuffmanCode(Huf, 2*(alphaAccount-1), 0, code);
                printf("成功对文件字符进行 Huffman 编码\n");
                break;
            // 展示字符编码
            case 2:
                Handle_ShowHuffTree(Huf, alphaAccount);
                printf("成功展示字符编码\n");
                break;
            // 对文件进行编码
            case 3:
                // 对源文件进行编码到目标文件 lft.enci
                Handle_CodeFile(Huf, alphaIndex, sourceName, enciName);
                printf("成功对文件进行编码\n");
                break;
            // 对文件进行解码
            case 4:
                // 将 lft.enci 解码到 lft.txt
                Handle_DecodeFile(Huf, enciName, alphaAccount);
                printf("成功对文件进行解码\n");
                break;
            // 对文件进行压缩
            case 5:
                // 将源文件压缩成 lft.comp ，返回压缩后的数字
                bitCount = Handle_CodingString(Huf, alphaAccount, freqPoint, alphaIndex, sourceName, compName);
                printf("成功对文件进行压缩\n");
                break;
            // 对文件进行解压缩
            case 6:
                // 将 lft.comp 解压成 lft.decomp
                Handle_DecodingString(Huf, compName, decompName, alphaAccount, bitCount);
                printf("成功对文件进行解压缩\n");
                break;
            // 前后文件对比
            case 7:
                // 对比编码前解码后前文件
                Handle_CompareFile(sourceName, deenciName);
                printf("编码前文件解码后文件一致\n");
                // 对比压缩前解压后文件
                Handle_CompareFile(sourceName, decompName);
                printf("压缩前文件解压后文件一致\n");
                break;
            // 退出系统，拜拜咯
            case 8:
                printf("拜拜\n");
                return;
        }
    }
}
