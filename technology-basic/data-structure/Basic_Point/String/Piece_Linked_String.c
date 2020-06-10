#define BLOCK_SIZE 4

typedef struct BLOCK_SIZE{
	char ch[BLOCK_SIZE];
	struct block *next;
}Block;

typedef struct 
{
	Block *head;
	Block *tail;
	int len;
}LString;

