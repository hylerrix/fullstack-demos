#include <stdio.h>
#include <malloc.h>

/*建立两个带头节点的学生链表，每个节点包含学号、姓名和成绩，
链表都按学号升序排列，将它们合并为一个链表仍按学号升序排列 */

/*
算法分析：
合并链表用merge()函数实现。函数中定义3个工作指针a、b、c，其中a、b分别指向La链表、Lb链表的当前结点，C指向合并后的链表尾结点。合并后链表的头结点共用La链表的头结点。
    ①合并前，先让a和b分别指向两个链表的第一个结点，c指向La链表的头结点。
    ②合并时应该分3种情况讨论，即La和Lb都没有处理完；La没处理完，但Lb处理完毕；Lb没处理完，但La处理完毕。
    ③合并过程中应始终将La和Lb链表中较小的一个链接在Lc中，方能保持有序。
*/

void merge(struct stud *La,struct stud *Lb)
{
    struct stud *a,*b,*c;
    c=La;
    a=La->next;/* 合并前 */
    b=Lb->next;
    while(a!=NULL && b!=NULL)/* La和Lb都没处理完 */
    {
        if(a->num <= b->num)
        {
            c->next=a;
            c=a;
            a=a->next;
        }
        else
        {
            c->next=b;
            c=b;
            b=b->next;
        }
    }
    if(a!=NULL)
        c->next=a;/* 若La没有处理完 */
    else
        c->next=b;/* 若Lb没有处理完 */
    free(Lb); /* 释放Lb的头结点 */
}

int main()
{
    printf("程序功能代码如 merge() 函数。\n");
    return 0;
}
