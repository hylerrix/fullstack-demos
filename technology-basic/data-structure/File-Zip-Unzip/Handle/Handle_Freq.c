#include <stdio.h>
#include <stdlib.h>

#include "../Huffman.h"

int Handle_GetFreq(FILE *fp, FREQ **freq, int *alphaIndex)
{

	int i;
	int ch;
	int alphaCount = 0;
	int index = 0;
	int t;

	rewind(fp);

    // 逐字符的获取文件内容并及时将 ASCII 字符数组中相应的位置数量递增一，此位置值为频率
	ch = (unsigned char)fgetc(fp);
	while(!feof(fp)) {
		alphaIndex[(unsigned char)ch]++;
        printf("%c", ch);
		ch = (unsigned char)fgetc(fp);
	}

    // 在 ASCII 字符数组中，每当找到数量不为空的字符，字符总个数递增一
    for (i = 0; i < 256; i++){
		if (alphaIndex[i]){
			alphaCount++;
		}
	}

    // 为 FREQ 结构体变量分配一个大小为字符总个数个自身结构体大小的连续空间
	*freq = (FREQ *)calloc(sizeof(FREQ), alphaCount);

    printf("----\n");	

    // 遍历 ASCII 字符数组每个数量不为空的字符，将该字符及其出现的频率依次绑定到连续的 FREQ 结构体变量中
	for (i = 0; i < 256; i++) {
		if (alphaIndex[i]) {
            // 绑定字母
			(*freq)[index].alpha = i;

			printf("%c", (*freq)[index].alpha);

            // 临时保存当前 FREQ 结构体变量在连续空间里的位置
			t = index;
            // 绑定字母在 ASCII 字符数组中刚才计算出后对应的频率，并使得当前 FREQ 结构体变量在连续空间里的位置后移
			(*freq)[index++].freq = alphaIndex[i];
            // 将临时保存的当前 FREQ 结构体变量在连续空间里的位置重新赋值给该值在 ASCII 字符数组的位置上的值，同时是 HUFFMAN_TABLE 结构体变量连续空间位置值
			alphaIndex[i] = t;
		}
	}

	printf("----\n");

    // 返回文件中所有不同种类的字符数量
	return alphaCount;
}

// 在一个连续空间的 HUFFMAN_TABLE 结构体变量中选择代表字母的频率最小的那个，返回其在连续空间的位置
int Handle_SelectMinFreq(HUFFMAN_TABLE *Huf, int account)
{

	int minIndex = -1;
	int i;

    // 线性阶遍历每个 HUFFMAN_TABLE 结构体变量，时刻将最小字母频率位置更新为当前找到的最小频率字母的那个
	for (i = 0; i < account; i++) {
	    // 如果当前 HUFFMAN_TABLE 结构体变量的总标志为零（没有访问过），并且最小位置从未更新或者当前 HUFFMAN_TABLE 结构体变量所代表的频率比最小位置的还小
		if (Huf[i].flag == 0 && (minIndex == -1 || Huf[i].freq < Huf[minIndex].freq))
		    // 更新最小位置
			minIndex = i;
    }

	// 将频率最小位置的 HUFFMAN_TABLE 结构体变量的总标志设置为 1 代表访问过
	Huf[minIndex].flag = 1;

	return minIndex;
}
