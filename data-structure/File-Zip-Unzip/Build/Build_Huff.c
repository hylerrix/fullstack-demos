#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Huffman.h"

// 初始化 HUFFMAN_TABLE 结构体变量的空间、字母及其频率和标志
HUFFMAN_TABLE *Build_InitHuffTree(FREQ *freq,int alphaAccount)
{

	HUFFMAN_TABLE *Huf;
	int i;

    // 为 HUFFMAN_TABLE 结构体变量分配 (2 * 源文件不同种类字符数量 - 1) 个该结构体自身大小的连续空间
	Huf = (HUFFMAN_TABLE *)malloc(sizeof(HUFFMAN_TABLE)*(2*alphaAccount-1));

    // 遍历连续的 FREQ 结构体变量，将每一个变量内保存的字母及其频率初始化给 HUFFMAN_TABLE 结构体变量
	for (i = 0; i < alphaAccount; i++) {
        // 初始化当前位置下 HUFFMAN_TABLE 结构体变量所代表字母

		printf("%-8c---- ", freq[i].alpha);

		Huf[i].alpha = freq[i].alpha;
        // 初始化当前位置下 HUFFMAN_TABLE 结构体变量所代表字母的频率
        printf("频率: %-8d \n", freq[i].freq);
		Huf[i].freq = freq[i].freq;
        // 初始化当前位置下 HUFFMAN_TABLE 结构体变量的左右孩子的标志为负一，用来表示叶子节点
		Huf[i].rightChild = Huf[i].leftChild = -1;
        // 初始化当前位置下 HUFFMAN_TABLE 结构体变量的总标志为负一
		Huf[i].flag = 0;
        // 为前位置下 HUFFMAN_TABLE 结构体变量分配源文件不同种类字符数量个字符空间作为之后编码内容的存储
		Huf[i].huffmancode = (char*)calloc(sizeof(char), alphaAccount);
	}

	return Huf;
}

// 创建 HUFFMAN_TABLE 结构体变量的连接关系
HUFFMAN_TABLE *Build_CreateHuffTree(FREQ *freq, int alphaAccount)
{

	HUFFMAN_TABLE *Huf;
	int i;
	int leftChild;
	int rightChild;

    // 遍历每一个，遍历源文件不同种类字符数量次，新增结点作为父节点
	for (i = 0 ; i < alphaAccount-1; i++) {
        // 从未访问过的选取最小频率的 HUFFMAN_TABLE 结构体变量，选取过后将其总标志改为一代表已经访问过，返回其在连续空间的最小位置
		leftChild = Handle_SelectMinFreq(Huf, alphaAccount+i);
        // 从未访问过的选取次小频率的 HUFFMAN_TABLE 结构体变量，选取过后将其总标志改为一代表已经访问过，返回其在连续空间的最小位置
		rightChild = Handle_SelectMinFreq(Huf, alphaAccount+i);
        // 该新增的父节点不代表任何字母
		Huf[alphaAccount+i].alpha = (unsigned char)NULL;
        // 该新增的父节点的字母频率为两个刚选出来的最小频率字母的频率之和
		Huf[alphaAccount+i].freq = Huf[leftChild].freq + Huf[rightChild].freq;
        // 将最小频率左孩子在 HUFFMAN_TABLE 结构体变量连续空间的最小位置连接到父节点上
		Huf[alphaAccount+i].leftChild = leftChild;
        // 将次小频率右孩子在 HUFFMAN_TABLE 结构体变量连续空间的位置连接到父节点上
		Huf[alphaAccount+i].rightChild = rightChild;
        // 设置父节点的总标志为零，代表未被访问过
		Huf[alphaAccount+i].flag = 0;
        // 设置父节点的编码内容为空
		Huf[alphaAccount+i].huffmancode = NULL;
	}

	return Huf;
}

// 根据每一个 HUFFMAN_TABLE 结构体变量的字母频率，递归完善该变量的的编码格式内容，递归前从哈弗曼树根节点出发
void Build_MakeHuffmanCode(HUFFMAN_TABLE *Huf, int root, int codeIndex, char *code)
{

    // 如果当前 HUFFMAN_TABLE 结构体变量的左孩子不存在，即是叶子节点
	if (-1 == Huf[root].leftChild) {
        // 当前编码数组位置的值记录为零
		code[codeIndex] = 0;
        // 将整个字符串的编码数组赋值给该 HUFFMAN_TABLE 结构体变量作为其编码
		strcpy(Huf[root].huffmancode, code);
	} else {
    // 如果当前 HUFFMAN_TABLE 结构体变量的左孩子存在，即不是叶子节点
        // 当前编码数组位置的值记录为一
		code[codeIndex] = '1';
        // 递归进入左子树
		Build_MakeHuffmanCode(Huf, Huf[root].leftChild, codeIndex+1, code);
        // 当前编码数组位置的值记录为零
		code[codeIndex] = '0';
        // 递归进入右子树
		Build_MakeHuffmanCode(Huf, Huf[root].rightChild, codeIndex+1, code);
	}

}
