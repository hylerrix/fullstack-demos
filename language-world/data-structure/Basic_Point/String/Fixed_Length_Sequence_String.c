#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

typedef struct 
{
	char ch[MAXSIZE+1];
	int len;
}SString;

// 串插入函数
int SStrInsert(SString *S, int pos, const SString T);
// 串删除函数
int SStrDelete(SString *S, int pos, int len);
// 串连接函数
int SStrCat(SString *S, const SString T);
// 求子串函数
int SubSString(SString *T, SString S, int pos, int len);

int main(void)
{
	SString *S;
	SString *T;
    S = (SString *)malloc(sizeof(SString));
    T = (SString *)malloc(sizeof(SString));
    S->ch[1] = 'a';
    S->ch[2] = 's';
    S->ch[3] = 'd';
    S->len = 3;
    T->ch[1] = 'q';
    T->ch[2] = 'w';
    T->ch[3] = 'e';
    T->ch[4] = 'r';
    T->len = 4;
    printf("T: ");
    for (int i = 1; i <= T->len; ++i)
    {
    	printf("%c", T->ch[i]);
    }
    printf("\n");
    printf("S: ");
    for (int i = 1; i <= S->len; ++i)
    {
    	printf("%c", S->ch[i]);
    }
    printf("\n");
    printf("SStrInsert(S, 1, T): %d\n", SStrInsert(S, 2, *T));
    printf("S: ");
    for (int i = 1; i <= S->len; ++i)
    {
    	printf("%c", S->ch[i]);
    }
    printf("\n");
    printf("SStrDelete(S, 2, 1): %d\n", SStrDelete(S, 2, 1));
    printf("S: ");
    for (int i = 1; i <= S->len; ++i)
    {
    	printf("%c", S->ch[i]);
    }
    printf("\n");
    printf("SStrCat(S, T): %d\n", SStrCat(S, *T));
    printf("S: ");
    for (int i = 1; i <= S->len; ++i)
    {
    	printf("%c", S->ch[i]);
    }
    printf("\n");
    printf("SubSString(T, S, 2, 3): %d\n", SubSString(T, *S, 2, 3));
    printf("S: ");
    for (int i = 1; i <= S->len; ++i)
    {
    	printf("%c", S->ch[i]);
    }
    printf("\n");
    printf("T: ");
    for (int i = 1; i <= T->len; ++i)
    {
    	printf("%c", T->ch[i]);
    }
    printf("\n");
	return 0;
}

int SStrInsert(SString *S, int pos, const SString T)
{
	int i;
	if (NULL == S || NULL == S->ch || NULL == T.ch || pos < 1 || pos > S->len + 1)
	    return 0;
	if (S->len+T.len <= MAXSIZE) {
        for (i = S->len+T.len; i >= pos+T.len; i--)
        	S->ch[i] = S->ch[i-T.len];
        for (i = pos; i < pos+T.len; i++)
        	S->ch[i] = T.ch[i-pos+1];
        S->len = S->len+T.len;
	} else if (pos+T.len <= MAXSIZE) {
        for (i = MAXSIZE; i > pos+T.len; i--)
        	S->ch[i] = S->ch[i-T.len];
        for (i = pos; i < pos+T.len; i++)
        	S->ch[i] = T.ch[i-pos+1];
        S->len = MAXSIZE;
	} else {
		for (i = pos; i <= MAXSIZE; i++)
			S->ch[i] = T.ch[i-pos+1];
		S->len = MAXSIZE;
	}
	return 1;
}

int SStrDelete(SString *S, int pos, int len)
{
	int i = 1;
	if (NULL == S || NULL == S->ch || len < 0 || pos < 1 || pos > S->len-len+1)
	    return 0;
    for (i = pos; i <= S->len-len; i++)
    	S->ch[i] = S->ch[i+len];
    S->len = S->len-len;
    return 1;
}

int SStrCat(SString *S, const SString T)
{
	int i = 1;
	if (NULL == S || NULL == S->ch || NULL == T.ch)
	    return 0;
	if (S->len + T.len <= MAXSIZE) {
		for (i = S->len+1; i <= S->len+T.len; i++)
			S->ch[i] = T.ch[i-S->len];
		S->len = S->len+T.len;
		return 1;
	} else if (S->len <= MAXSIZE) {
		for (i = S->len+1; i <= MAXSIZE; i++)
			S->ch[i] = T.ch[i-S->len];
		S->len = MAXSIZE;
		return 0;
	} else {
		return 0;
	}
}

int SubSString(SString *T, SString S, int pos, int len)
{
	int i;
	if (NULL == T || NULL == T->ch || NULL == S.ch || len < 0 || 
		len > S.len -pos+1 || pos < 1 || pos > S.len) 
		return 0;
	for (i = 1; i <= len; i++)
		T->ch[i] = S.ch[pos+i-1];
	T->len = len;
	return 1;
}