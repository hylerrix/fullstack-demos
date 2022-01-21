#include <stdio.h>

#include "../Huffman.h"

void Handle_CodeFile(HUFFMAN_TABLE *Huf, int *alphaHuffindex, char *sourceFilename, char *enciName) {

	unsigned int ch;
	FILE *fpIn;
	FILE *fpOut;

	// 只读方式打开源文件
	fpIn = fopen(sourceFilename, "r");
	// 只写方式打开目标文件 lft.enci
	fpOut = fopen(enciName, "w");

    // 监测是否有文件打开错误
    if (fpIn == NULL || fpOut == NULL) {
        printf("文件打开失败");
        return;
    }

    // 获取指针指向源文件当前内容的字符
	ch = (unsigned int)fgetc(fpIn);

	while(!feof(fpIn)) {
		// 将当前字符在 HUFFMAN_TABLE 结构体变量中相应的编码格式写入目标文件
		fputs(Huf[alphaHuffindex[ch]].huffmancode, fpOut);
		// 重新获取指针指向源文件当前内容的字符
		ch = (unsigned int)fgetc(fpIn);
	}

    // 关闭源文件和目标文件
	fclose(fpOut);
	fclose(fpIn);
}


// 将 lft.enci 解码到 lft.txt
void Handle_DecodeFile(HUFFMAN_TABLE *Huf, char* enciName, int alphaAccount) {

	unsigned int ch;
	int i = 0;
	int root = 2*(alphaAccount-1);
	char *deenciName = "lft.deenci";
	// 获取每一个 HUFFMAN_TABLE 结构体变量编码长度的累加值
	int strlen = Handle_GetHuffStringLen(Huf, alphaAccount);
	int q = 0;

	FILE *fpIn;
	FILE *fpOut;

    // 只读方式打开目标文件
	fpIn = fopen(enciName, "r");
	// 只写方式打开解码后文件
	fpOut = fopen(deenciName, "w");

    // 监测是否有文件打开错误
    if (fpIn == NULL || fpOut == NULL) {
        printf("文件打开失败");
        return;
    }

    // 获取指针指向目标文件当前内容的字符
	ch = (unsigned int)fgetc(fpIn);

	while(!feof(fpIn)) {
	    // 如果当前 HUFFMAN_TABLE 结构体变量的左孩子存在，即不是叶子节点
		if (-1 != Huf[root].leftChild) {
			// 判断指针指向目标文件当前内容的编码是否为一，如果是则在下次循环进入该节点左孩子
			root = ch == '1' ? Huf[root].leftChild : Huf[root].rightChild;
			// 获取指针指向目标文件当前内容的字符
			ch = (unsigned int)fgetc(fpIn);
		} else {
		// 如果当前 HUFFMAN_TABLE 结构体变量的左孩子不存在，即是叶子节点
		    // 将指针指向目标文件当前内容的字符输出到解码文件中
			fputc(Huf[root].alpha, fpOut);
			// 重新返回 HUFFMAN_TABLE 结构体变量的根节点
			root = 2*(alphaAccount-1);
		}
	}

    // 将最后一个结点的字符输入驿码后的文件
	fputc(Huf[root].alpha, fpOut);

	fclose(fpIn);
	fclose(fpOut);
}
