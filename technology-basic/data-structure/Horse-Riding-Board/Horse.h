#ifndef HORSE
#define HORSE

#define STACK_SIZE 100    /* 存储空间初始分配量 */
#define STACKINCREMENT 10    /* 存储空间分配增量 */
#define N 8    /* 棋盘大小 */

int weight[N][N];    /* 各点的权值 */
int Board[N][N][8];    /* 按点的权值递升存放待走方向，每点8个 */

typedef struct {    // 位置
    int x;
    int y;
}PosType;

typedef struct {    // 栈的元素
	int ord;
	PosType seat;    // 点
	int di;    // 马的方向
}ElemType;

typedef struct {    // 定义栈
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

SqStack S;

extern int InitStack();    // 初始化一个空栈
extern ElemType GetTop();    // 取得栈顶的值
extern void Push(ElemType elem);    // 将元素压入栈
extern int Pop(ElemType *elem);    // 将栈顶值出栈
extern int StackEmpty();    // 判断栈是否为空
extern void OutputPath();    // 输出马走过的路径
extern int Pass(PosType curpos);    // 判断当前位置是否合法
extern PosType NextPos(PosType curpos, int direction);    // 8 个候选方向
extern void SetWeight();
extern void SetMap();    // 各点的8个方向按照权值递增排列
extern int HorsePath(PosType start);    // 马走过的路径

#endif