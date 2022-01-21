#include <stdio.h>
#include <stdlib.h>

//链表的插入操作

struct Student{
    char cName[20];/* 姓名 */
    int iNumber;/* 学号 */
    struct Student *next;/* next的类型是指向本结构体类型的指针类型 */
};

int iCount;/* 全局变量表示链表长度 */

struct Student *Create()
{
    struct Student *pHead=NULL;/* 初始化链表，头指针为空 */
    struct Student *pNew,*pEnd;
    iCount=0;/* 初始化链表长度 */
    pEnd=pNew=(struct Student *)malloc(sizeof(struct Student));
    printf("请输入学生的姓名和学号：\n");
    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);
    while(pNew->iNumber!=0)
    {
        iCount++;
        if(iCount==1)
        {
            pNew->next=pHead;/* 使得指针指向为空 */
            pEnd=pNew;/* 跟踪新加入的节点 */
            pHead=pNew;/* 头指针指向首节点 */
        }
        else
        {
            pNew->next=NULL;/* 新节点的指针为空 */
            pEnd->next=pNew;/* 原来的节点指向新节点 */
            pEnd=pNew;/* pEnd指向新节点 */
        }
        pNew=(struct Student *)malloc(sizeof(struct Student));/* 再次分配节点的内存空间 */
        scanf("%s",pNew->cName);
        scanf("%d",&pNew->iNumber);
    }
    free(pNew);/* 释放节点空间 */
    return(pHead);
}

void Print(struct Student *pHead)
{
    struct Student *pTemp;/* 循环所用的临时指针 */
    int iIndex=1;/* 表示链表中节点的序号 */
    printf("\n****本名单中有%d名学生****\n",iCount);
    pTemp=pHead;/* 指针得到首节点的地址 */
    while(pTemp!=NULL)
    {
        printf("第%d名学生是:\n",iIndex);
        printf("姓名：%s\n",pTemp->cName);/* 输出姓名 */
        printf("学号：%d\n\n",pTemp->iNumber);/* 输出学号 */
        pTemp=pTemp->next;/* 移动临时指针到下一个节点 */
        iIndex++;/* 进行自加运算 */
    }
}

struct Student *Insert(struct Student *pHead)
{
    struct Student *pNew;/* 定义pNew指向新分配的空间 */
    printf("请输入学生的姓名和学号：\n");
    pNew=(struct Student *)malloc(sizeof(struct Student));/* 分配内存空间，返回该内存空间地址 */
    scanf("%s",pNew->cName);
    scanf("%d",&pNew->iNumber);
    pNew->next=pHead;/* 新节点指针指向原来的首节点 */
    pHead=pNew;/* 头指针指向新节点 */
    iCount++;/* 增加链表节点数量 */
    return pHead;/* 返回头指针 */
}

int main()
{
    struct Student *pHead;/* 定义头结点 */
    pHead=Create();/* 创建节点 */
    pHead=Insert(pHead);/* 插入节点 */
    Print(pHead);/* 输出链表 */
    return 0;
}
