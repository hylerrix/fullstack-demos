#include <stdio.h>
#include <string.h>

#include "../Huffman.h"

int Handle_CodingString(HUFFMAN_TABLE *Huf, int alphaAccount, FREQ *freq, int *alphaIndex, char *sourceFilename, char *compName) {

	unsigned int ch;
	unsigned int bitCount = 0;
	int i = 0;
	int j = 0;
	FILE *fpIn;
	FILE *fpOut;
	unsigned char byte;
	int bitIndex = 0;
	int huffCodeIndex;
	char s[256];

    // 以只读方式打开源文件
	fpIn = fopen(sourceFilename, "r");
	// 以只写二进制方式创建压缩文件
	fpOut = fopen(compName, "wb");

	// 监测是否有文件打开错误
	if (fpIn == NULL || fpOut == NULL) {
        printf("文件打开失败");
        return 0;
    }

	printf("......\n");

	// 从源文件中读取一个字符大小的字节数赋值给字符变量
	ch = fgetc(fpIn);

	while(!feof(fpIn)) {
		// 将当前文件读取到的字符变量对应的 HUFFMAN_TABLE 结构体变量的编码赋值给新的字符数组
		printf("%c", Huf[alphaIndex[ch]].alpha);
		strcpy(s, Huf[alphaIndex[ch]].huffmancode);
		for (huffCodeIndex = 0; s[huffCodeIndex]; huffCodeIndex++){
			if (s[huffCodeIndex] == '1') {
				SetBit(byte, bitIndex);
				bitCount++;
			} else {
				ClearBit(byte, bitIndex);
				bitCount++;
			}

			bitIndex++;

			if (bitIndex == 8)
			{
				fwrite(&byte, sizeof(char), 1, fpOut);
				i++;
				bitIndex = 0;
			}
		}
		// 从源文件中读取一个字符赋值给字符变量
		ch = fgetc(fpIn);
	}

	printf("bitIndex: %d\n", bitIndex);

	if (bitIndex != 0) {
		printf("%c----\n", byte);
		fwrite(&byte, sizeof(char), 1, fpOut);
		i++;
	}

	printf("============== bitCount: %d ==============\n", bitCount);
	printf("============== i: %d ==============\n", i);
	fclose(fpOut);
	fclose(fpIn);
	return bitCount;
}

void Handle_DecodingString(HUFFMAN_TABLE *Huf, char *compName, char *lastname, int alphaAccount, int bit) {

	unsigned int ch;
	int i = 0;
	int root = 2*(alphaAccount-1);
	int bitIndex = 0;
	int bitCount = 0;
	int alphcount = 0;
	int j = 0;

	int q = 0;

	FILE *fpIn;
	FILE *fpOut;

	// 以只读二进制方式打开压缩文件
	fpIn = fopen(compName, "rb");
	// 以只写方式打开源文件
	fpOut = fopen(lastname, "w");

	// 监测是否有文件打开错误
	if (fpIn == NULL || fpOut == NULL) {
        printf("文件打开失败");
        return;
    }

	ch = fgetc(fpIn);

	while(!feof(fpIn)) {
	    if (-1 != Huf[root].leftChild) {
			if (bitCount < bit) {
				root = GetBit(ch,bitIndex) ? Huf[root].leftChild : Huf[root].rightChild;
			}
			bitIndex++;
			bitCount++;
			if (bitIndex >= 8) {
				ch = fgetc(fpIn);
				bitIndex=0;
			}
	    } else {
			fwrite(&Huf[root].alpha, sizeof(char), 1, fpOut);
			root = 2*(alphaAccount-1);
	    }
    }

  	if (Huf[root].leftChild == -1){
	fwrite(&Huf[root].alpha, sizeof(char), 1, fpOut);}

	fclose(fpIn);
	fclose(fpOut);
}

// 对比源文件和解码/解压后的文件内容是否相同
void Handle_CompareFile(char *File1, char *File2) {

	FILE *fp1;
	FILE *fp2;
	int i;
	int alphaIndex[256] = {0};
	int sameNum = 0;

	FREQ *freq1;
	FREQ *freq2;

	int alphacount1;
	int alphacount2;

    // 以只读二进制方式打开源文件
	fp1 = fopen(File1, "rt");
	// 以只读二进制方式打开解码/解压后的文件
	fp2 = fopen(File2, "rt");

	// 监测是否有文件打开错误
    if (fp1 == NULL || fp2 == NULL) {
        printf("文件打开失败\n");
        return;
    }

    // 获取源文件内容里不同字符的个数
	alphacount1 = Handle_GetFreq(fp1, &freq1, alphaIndex);
	for (i=0; i<256; i++){
		alphaIndex[i] = 0;
	}

    // 获取解码/解压后的文件内容里不同字符的个数
	alphacount2 = Handle_GetFreq(fp2, &freq2, alphaIndex);

    // 如果两个文件拥有相同的字符种类
	if (alphacount1 == alphacount2) {
        // 遍历查看每个字符种类频率是否相同
		for (i = 0; i < alphacount1; i++) {
			if (freq1[i].alpha == freq2[i].alpha && freq1[i].freq == freq2[i].freq) {
				// 频率相同的字符数量递增一
				sameNum++;
			}
		}
	}

    if (sameNum == alphacount1) {
	    printf("源文件和解码/解压后的文件内容完全相同\n");
	} else {
		printf("源文件和解码/解压后的文件内容不相同哦\n");
	}
}
