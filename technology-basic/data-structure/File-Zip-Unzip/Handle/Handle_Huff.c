#include <stdio.h>
#include <string.h>

#include "../Huffman.h"

// 展示生成的字符编码
void Handle_ShowHuffTree(HUFFMAN_TABLE *Huf, int alphaAccount)
{

	int i;

	for (i = 0; i < 2*alphaAccount-1; i++) {
        printf("%4d\t", i);
        if (Huf[i].alpha == '\n') {
            printf("%4s\t", "[Enter]");
        } else if (Huf[i].alpha == ' ') {
            printf("%4s\t", "[Space]");
        } else {
            printf("%4c\t", Huf[i].alpha);
        }
        printf("%4d\t", Huf[i].freq);
        printf("%6d\t", Huf[i].leftChild);
        printf("%6d\t", Huf[i].rightChild);
        printf("%4d\t", Huf[i].flag);
        printf("%4s\t\n", Huf[i].huffmancode);
    }

}

// 获取每一个 HUFFMAN_TABLE 结构体变量编码长度的累加值
int Handle_GetHuffStringLen(HUFFMAN_TABLE *Huf,int alphaAccount)
{

	int sum = 0;
	int i;

	// 遍历每一个 HUFFMAN_TABLE 结构体变量的编码长度并累加
	for (i = 0;i < alphaAccount; i++)
		sum += Huf[i].freq * strlen(Huf[i].huffmancode);

    // 返回每一个 HUFFMAN_TABLE 结构体变量编码长度的累加值
	return sum;
}