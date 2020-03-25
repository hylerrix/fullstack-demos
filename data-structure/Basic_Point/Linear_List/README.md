---

## 线性表

---

### 1. 线性表的运算

|线性表运算|参考函数声明|
|----|----|
|线性表初始化|InitList(L)|
|求线性表长度|ListLength(L)|
|返回线性表中指定位置元素的值|GetElem(L, i, x)|
|按值查找|LocationElem(L, x)|
|插入操作|ListInsert(L, i , x)|
|删除操作|ListDelete(L, i)|
|判断是否为空|ListEmpty(L)|
|将线性表置为空表|ClearList(L)|
|销毁线性表|DestroyList(L)|

### 2. 线性表的顺序存储

#### 顺序表

##### 顺序表的存储结构

```
#define MAXSIZE <线性表可能达到的最大长度>
typedef struct
{
    ElemType elem[MAXSIZE];
    int length;    // 线性表长度
}SeqList；
```

##### 顺序表的初始化

```
Init_SeqList(SeqList *L)
{
    L->length = 0;
}
```

##### 顺序表的插入

```
int Insert_SeqList(SeqList *L, int i, ElemType x)
{
    int j;
    if (L->length == MAXSIZE) {
        return OVERFLOW;    // 表空间已满，不能插入
    }
    if (i < 1 || i > L->length + 1) {
        return ERROR;    // 检查插入位置是否正确
    }
    for (j = L->length; j >= i; --j) {
        L->elem[j+1] = L->elem[j];
    }
    L->elem[i] = x;
    L->length++;
    return TRUE;    // 插入成功，返回
}
```

##### 顺序表的删除

```
int Delete_SeqList(SeqList *L, int i)
{
	int j;
	if (i < 1 || i > L->length)
		return ERROR;
    for (j = i; j < L->length; ++j) {
    	L->elem[j] = L->elem[j+1];
    }
    L->length--;
    return TRUE;
}
```

##### 顺序表中按值查找

```
int Location_SeqList(SeqList *L, ElemType x)
{
	int i = 1;
	while (i <= L->length && L->elem[i]!=x)
		i++;
	if (i > L->length)
		return FALSE;
	else
		return i;
}
```

##### 顺序表其他操作

> 还可以有合并、分拆、复制、排序等

### 3. 线性表的链式存储

#### 单链表

##### 单链表其他操作

> 还可以有求差集等

#### 循环链表

#### 双向链表

#### 静态链表

### 4. 线性表的应用实例

* 约瑟夫环问题
* 一元多项式运算器的分析与实现


顺序存储优点如下：
* 用数组存储数据元素，操作方法简单，容易实现
* 无需为表示结点间的逻辑关系而增加额外的存储开销
* 存储密度高
* 顺序表可按元素位序随机存取结点
缺点：
* 做插入、删除操作时，须大量的移动数据元素，效率比较低
* 要占用连续的存储空间，存储分配只能预先进行

链表的优缺点恰好和顺序表相反。

怎样选取存储结构：
* 基于存储的考虑
* 基于运算的考虑
* 基于环境的考虑