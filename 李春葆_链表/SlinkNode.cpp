#include<malloc.h>
#include<stdio.h>
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next; //指向下一个节点的指针（当然就是struct类型）
}SLinkNode;
void InitList(SLinkNode *&L)
{
    L=(SLinkNode *)malloc(sizeof(SLinkNode));
    L->next=NULL;
}
void DestoryList(SLinkNode *&L)
{
    SLinkNode *pre=L,*p=pre->next;
    while(p!=NULL)
    {
        free(pre);
        pre=p;p=pre->next;
    }
    free(pre);
}
int GetLength(SLinkNode *L)
{
    int i = 0;
    SLinkNode *p=L->next;
    while (p!=NULL)
    {
        p=p->next;
        i++;
    }
    return i;
}
int GetElem(SLinkNode *L,int i,ElemType &e)
{
    int j = 0;
    SLinkNode *p = L;
    if (j<1) return 0;
    while (j<i||p!=NULL)
    {
       j++;
       p = p->next;
    }
    if (p==NULL)
        return 0;
    else
    {
        e = p->data;
        return 1;
    }

}

int Locate(SLinkNode *L,ElemType e)	
{	
    SLinkNode *p=L->next;
    int j=1;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
        j++;
    }

    if (p==NULL)
    {
        return 0;
    }
    else return(j);   
}

int InsElem(SLinkNode *&L,ElemType x,int i)	//插入结点值为x的结点
{	int j=0;
	SLinkNode *p=L,*s;
	if (i<=0) return 0;			//参数i错误返回0
	while (p!=NULL && j<i-1)	//查找第i-1个结点*p
	{	j++;
		p=p->next;
	}
    if(p=NULL) return 0;
    else
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=x;
        s->next = p->next;
        p->next =s;
        return 1;  
    }
}

int DelElem(SLinkNode *&L,int i)
{
    int j = 0;
    SLinkNode *p = L,*q;
    if(i<=0) return 0;
    while(j<i-1&&p != NULL)
    {
        p=p->next;
        j++;
    }

    if (p==NULL) return 0;
    else
    {
        q=p->next;
        if(q==NULL) return 1;
        else
        {
            p->next = q->next;
            return 1;
            free(q);
        }
    }
}

//整体单链表算法
void CreateListF(SLinkNode *&L,ElemType a[],int n)
{
    SLinkNode *s;int i;
    L=(SLinkNode *)malloc(sizeof(SLinkNode));
    L->next=NULL;
    for (int i = 0; i < n; i++)
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
    
}

void CreateListR(SLinkNode *&L,ElemType a[],int n)
{
    SLinkNode *s,*tc; int i;
    L=(SLinkNode *)malloc(sizeof(SLinkNode));
    tc=L;
    for (int i = 0; i < n; i++)
    {
        s=(SLinkNode *)malloc(sizeof(SLinkNode));
        s->data=a[i];
        tc->next = s;
        tc = s;
    }
    tc->next=NULL;
}
