#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;
	struct node *next;
}LNode,*LinkList;

// 头插法建立单链表
LinkList Creat_LinkList_Head();
// 尾差法建立单链表
LinkList Creat_LinkList_Tail();
// 求单链表的表长
int Length_LinkList(LinkList H);
// 单链表中按序号查找
LinkList Get_LinkList(LinkList H, int k);
// 单链表中按值查找
LNode *Locate_LinkList(LinkList H, ElemType x);
// 单链表的插入
int Insert_LinkList(LinkList H, int i, ElemType x);
// 单链表的删除
int Del_LinkList(LinkList H, int i);
// 单链表的倒置
void Reverse(LinkList H);
// 单链表中删除重复结点
void Pur_LinkList(LinkList H);

int main(void)
{
	int asw;
	LinkList pList;
	LNode *pNode;
	LinkList H1 = Creat_LinkList_Head();
	LinkList H2 = Creat_LinkList_Tail();
	Length_LinkList(H1);
	Get_LinkList(H1, 1);
	Locate_LinkList(H1, 1);

	return 0;
}

LinkList Creat_LinkList_Head()
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s;
	int x;
	scanf("%d", &x);
	while (x != -1) {
	    s = (LinkList)malloc(sizeof(LNode));
	    s->data = x;
	    s->next = H->next;
	    H->next = s;
	    scanf("%d", &x);
	}
	return H;
}

LinkList Creat_LinkList_Tail()
{
	LinkList H = (LinkList)malloc(sizeof(LNode));
	H->next = NULL;
	LNode *s, *r = H;
	int x;
	scanf("%d", &x);
	while (x != -1)
	{
		s = (LinkList)malloc(sizeof(LNode));
		s->data = x;
		s->next = NULL;
		r->next = s;
		r = s;
        scanf("%d", &x);
	}
	return H;
}

int Length_LinkList(LinkList H)
{
	LNode *p = H;
	int j = 0;
	while (p->next != NULL) {
		p = p->next;
        j++;
	}
	return j;
}

LinkList Get_LinkList(LinkList H, int k)
{
	LNode *p;
	int j = 0;
	if(k > Length_LinkList(H))
		return NULL;
	while (p->next != NULL && j < k) {
		p = p->next;
		j++;
	}
	if (j == k)
		return p;
    return NULL;
}

LNode *Locate_LinkList(LinkList H, ElemType x)
{
	LNode *p = H;
	while (p->next != NULL && p->data != x)
		p=p->next;
	return p;
}

void Pur_LinkList(LinkList H)
{
	LNode *p,*q,*r;
	p = H->next;
	if (p != NULL) {
		while (p->next) {
			q = p;
			while (q->next) {
				if (q->next->data == p->data) {
					r = q->next;
					q->next = r->next;
					free(r);
				}
				else {
					q = q->next;
				}
				p = p->next;
			}
		}
	}

}