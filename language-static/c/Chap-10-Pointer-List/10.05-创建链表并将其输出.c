#include <stdio.h>
#include <stdlib.h>

//创建链表并将其输出

struct Student
{
    char cName[20];/* 姓名 */
    int iNumber;/* 学号 */
    struct Student *next;/* next的类型是指向本结构体类型的指针类型 */
};

int iCount;/* 全局变量表示链表长度 */

struct Student *Create()
{
    struct Student *pHead=NULL;/* 初始化链表，头指针为空 */
    struct Student *pEnd,*pNew;
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
            pEnd->next=pNew;/* 跟踪新加入的节点 */
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
    return pHead;
}

void print(struct Student *pHead)
{
    struct Student *pTemp;/* 循环所用的临时指针 */
    int iIndex=1;/* 表示链表中节点的序号 */
    printf("**********本名单中有%d个学生**********\n",iCount);
    pTemp=pHead;/* 指针得到首节点的地址 */
    while(pTemp!=NULL)
    {
        printf("第%d个学生是：\n",iIndex);
        printf("姓名：%s\n",pTemp->cName);/* 输出姓名 */
        printf("学号：%d\n\n",pTemp->iNumber);/* 输出学号 */
        pTemp=pTemp->next;/* 移动临时指针到下一个节点 */
        iIndex++;/* 进行自加运算 */
    }
}

int main()
{
    struct Student *pHead;/* 定义头结点 */
    pHead=Create();/* 创建节点 */
    print(pHead);/* 输出链表 */
    return 0;
}
