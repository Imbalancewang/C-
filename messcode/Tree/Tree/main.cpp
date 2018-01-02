//
//  main.cpp
//  Tree
//
//  Created by matthew on 2017/12/29.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
int InitBiTree(BiTree &T);
int CreateBiTree(BiTree &T);
int DestroyBiTree(BiTree &T);
int PreOrderTraverse(BiTree &T);
int InOrderTraverse(BiTree &T);
int PostOrderTraverse(BiTree &T);
int LevelOrderTraverse(BiTree &T);
int GetDepth(BiTree &T);
int GetNodeNumber(BiTree &T);
int main(int argc, const char * argv[]) {
    // insert code here...
    BiTNode *T;
    InitBiTree(T);
    CreateBiTree(T);
    PreOrderTraverse(T);
    cout<<endl;
    InOrderTraverse(T);
    PostOrderTraverse(T);
    cout<<endl;
    DestroyBiTree(T);
   // std::cout << "Hello, World!\n";
    return 0;
}
int InitBiTree(BiTree &T)
{
    T=NULL;
    return 0;
}
int CreateBiTree(BiTree &T)
{
    TElemType ch;
    cin>>ch;
    if(ch=='#')
    {
        T=NULL;
    }
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return 0;
}
int DestroyBiTree(BiTree &T)
{
    if(T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        delete  T;
    }
    return 0;
}
int PreOrderTraverse(BiTree &T)
{
    if(T)
    {
        cout<<T->data;
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return 0;
}
int InOrderTraverse(BiTree &T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data;
        InOrderTraverse(T->rchild);
    }
    return 0;
}
int PostOrderTraverse(BiTree &T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data;
    }
    return 0;
}
int LevelOrderTraverse(BiTree &T)
{
    
    return 0;
}
int GetDepth(BiTree &T)
{
    if(T==NULL)
        return 0;
    return max(GetDepth(T->lchild),GetDepth(T->rchild))+1;
}
int GetNodeNumber(BiTree &T)
{
    if(T==NULL)
        return 0;
    return GetNodeNumber(T->lchild)+GetNodeNumber(T->rchild)+1;
}
