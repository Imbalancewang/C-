//
//  main.c
//  tree
//
//  Created by matthew on 2017/12/2.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<>
#include <iostream>
using namespace std;
typedef struct node
{
    char data;
    struct node*lchild,*rchild;
} pjq;
char ch;
void creat(pjq **p,int a)//先序建树
{
    *p=NULL;
    if(a)
        ch=getchar();
    else
        a=1;
    if(ch=='\n')
        return;
    else
    {
        if(ch=='#')
            *p=NULL;
        else
        {
            *p=(pjq *)malloc(sizeof(pjq));
            (*p)->data=ch;
            creat(&((*p)->lchild),a);
            creat(&((*p)->rchild),a);
        }
    }
}
void print1(pjq *p)//中序输出树
{
    if(p!=NULL)
    {
        print1(p->lchild);
        printf("%c",p->data);
        print1(p->rchild);
    }
}
void print2(pjq *p）//后序输出树
{
    if(p!=NULL)
    {
        print2(p->lchild);
        print2(p->rchild);
        printf("%c",p->data);
    }
}
            void print3(pjq *b)//层次遍历输出树
{
    if(b==NULL)
        return ;
    pjq *p;
    pjq *q[2050];
    int front,last;
    front=last=-1;
    last++;
    q[last]=b;
    while(front!=last)
    {
        front=(front+1);
        p=q[front];
        printf("%c",p->data);
        if(p->lchild!=NULL)
        {
            last++;
            q[last]=p->lchild;
        }
        if(p->rchild!=NULL)
        {
            last++;
            q[last]=p->rchild;
        }
    }
}
            int main()
{
    pjq *p=NULL;
    while((ch=getchar())!=EOF)
    {
        if(ch=='#')
            printf("\n");
        else
        {
            int a=0;
            creat(&p,a);
            print1(p);
            printf(" ");
            print2(p);
            printf(" ");
            print3(p);
            printf("\n");
        }
        getchar();
    }
    return 0;
}
