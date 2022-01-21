#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *ch;
    int len;
}HString;

// 串初始化函数
void HStrInit(HString *S);
// 串赋值函数
int HStrAssign(HString *S, const char *chars);
// 串插入函数
int HStrInsert(HString *S, int pos, const HString T);
// 串删除函数
int HStrDelete(HString *S, int pos, int len);
// 串连接函数
int HStrCat(HString *S, const HString T);
// 求子串函数
int SubHString(HString *T, HString S, int pos, int len);

int main(void)
{
	HString *S = (HString *)malloc(sizeof(HString));
	HString *T = (HString *)malloc(sizeof(HString));
	HStrInit(S);
	HStrInit(T);
    printf("HStrAssign(S, '233'): %d\n", HStrAssign(S, "233"));
    printf("S: ");
    for (int i = 1; i <= S->len; i++)
    	printf("%c", S->ch[i]);
    printf("\n");
    printf("HStrAssign(T, '666'): %d\n", HStrAssign(T, "666"));
    printf("T: ");
    for (int i = 1; i <= T->len; i++)
    	printf("%c", T->ch[i]);
    printf("\n");
    printf("HStrInsert(S, 2, *T): %d\n", HStrInsert(S, 3, *T));
    printf("S: ");
    for (int i = 1; i <= S->len; i++)
    	printf("%c", S->ch[i]);
    printf("\n");
    printf("HStrDelete(S, 4, 2): %d\n", HStrDelete(S, 4, 2));
    printf("S: ");
    for (int i = 1; i <= S->len; i++)
    	printf("%c", S->ch[i]);
    printf("\n");
    printf("HStrCat(S, *T): %d\n", HStrCat(S, *T));
    printf("S: ");
    for (int i = 1; i <= S->len; i++)
    	printf("%c", S->ch[i]);
    printf("\n");
    printf("SubHString(T, *S, 1, 3): %d\n", SubHString(T, *S, 1, 3));
    printf("T: ");
    for (int i = 1; i <= T->len; i++)
    	printf("%c", T->ch[i]);
    printf("\n");
	return 0;
}

void HStrInit(HString *S)
{
	S->ch = NULL;
	S->len = 0;
}

int HStrAssign(HString *S, const char *chars)
{
	int i = 0;
	if (NULL == chars || NULL == S)
		return 0;
	while (chars[i] != '\0')
		i++;
	S->len = i;
	if (0 != S->len) {
		if (S->ch != NULL)
			free(S->ch);
		S->ch = (char *)malloc((S->len+1)*sizeof(char));
		if (NULL == S->ch)
			return 0;
		for (i = 1; i <= S->len; i++)
			S->ch[i] = chars[i-1];
	} else {
		S->ch = NULL;
	}
	return 1;
}

int HStrInsert(HString *S, int pos, const HString T)
{
	int i;
	char *temp;
	if (NULL == S || NULL == S->ch || NULL == T.ch || pos > S->len || pos < 1)
		return 0;
	temp = (char *)malloc((S->len+T.len+1)*sizeof(char));
	if(NULL == temp)
		return 0;
	for (i = 1; i < pos; i++)
		temp[i] = S->ch[i];
	for (i = pos; i < pos+T.len; i++)
		temp[i] = T.ch[i-pos+1];
	for (i = pos+T.len; i <= S->len+T.len; i++)
		temp[i] = S->ch[i-T.len];
	free(S->ch);
	S->ch = temp;
	S->len = S->len+T.len;
	return 1;
}

int HStrDelete(HString *S, int pos, int len)
{
	int i;
	char *temp;
	if (NULL == S || NULL == S->ch || len < 0 || pos < 1 || pos > S->len-len+1)
		return 0;
	temp = (char *)malloc((S->len-len+1)*sizeof(char));
    if (NULL == temp)
    	return 0;
    for (i = 1; i < pos; i++)
    	temp[i] = S->ch[i];
    for (i = pos; i<= S->len-len; i++)
    	temp[i] = S->ch[i+len];
    free(S->ch);
    S->ch = temp;
    S->len = S->len-len;
    return 1;
}

int HStrCat(HString *S, const HString T)
{
	int i = 1;
	if (NULL == S || NULL == S->ch || NULL == T.ch)
		return 0;
	S->ch = (char *)realloc(S->ch, (S->len+T.len+1)*sizeof(char));
	if (NULL == S->ch)
		return 0;
	for (i = S->len + 1; i <= T.len+S->len; i++)
		S->ch[i] = T.ch[i-S->len];
	S->len = S->len+T.len;
	return 1;
}

int SubHString(HString *T, HString S, int pos, int len)
{
	int i = 1;
	if (NULL == T || NULL == T->ch || NULL == S.ch || len < 0 || len > S.len-pos+1
		|| pos < 1 || pos > S.len)
		return 0;
	T->len = len;
    if (NULL != T->ch)
    	free(T->ch);
    T->ch = (char *)malloc((T->len+1)*sizeof(char));
    if (NULL == T->ch)
    	return 0;
    for (i = 1; i <= T->len; i++)
    	T->ch[i] = S.ch[pos+i-1];
    return 1;
}