### 栈 stack 先进先出 LIFO

栈只允许在表的一端进行插入或删除操作->编译软件、程序设计语言

Pop(S)出栈
GetTop(S)取栈顶元素
SetEmpty(S)置栈空操作

#define MAXSIZE <栈最大元素数>
typedef struct
{
    datatype data[MAXSIZE];
    int top;
}SeqStack;

// 置空栈
SeqStack *Init_SeqStack();
// 判空栈
int Empty_SeqStack(SeqStack *S);
// 入栈
int Push_SeqStack(SeqStack *S, datatype x);
// 出栈
int Pop_SeqStack(SeqStack *S, datatype *x);
// 取栈顶元素
datatype Top_SeqStack(SeqStatck *S);

多栈的共享邻接空间

应用实例
括号匹配问题
表达式求值
数值转换
行编辑程序
栈与递归
迷宫求解
马踏棋盘

### 队列 queue
队列只允许在表的一端进行插入操作、而在另一端进行删除操作->操作系统和事物管理器

应用实例
舞伴问题

