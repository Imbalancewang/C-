//
//  main.cpp
//  oj1119
//
//  Created by matthew on 2017/12/2.
//  Copyright © 2017年 matthew. All rights reserved.
//
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct BiTreeNode
{
    char value;
    BiTreeNode *lchild;
    BiTreeNode *rchild;
};
BiTreeNode *CreateBiTree()
{
    BiTreeNode *T;
    char ch;
   // cout<<"ds"<<endl;
    cin>>ch;
    if(ch=='#'){
        T=NULL;
        return T;
    }
    else
    {
        T=new BiTreeNode;
        T->value=ch;
        T->lchild=CreateBiTree();
        T->rchild=CreateBiTree();
    }
    return T;
}
void PreOrderTraverse(BiTreeNode *T)
{
    if(T)
    {
        cout<<T->value;//
        PreOrderTraverse(T->lchild);//
        PreOrderTraverse(T->rchild);
    }
}
void InOrderTraverse(BiTreeNode *T)
{
    if(T)
    {
        InOrderTraverse(T->lchild);//
        cout<<T->value;//
        InOrderTraverse(T->rchild);//
    }
}
void PostOrderTraverse(BiTreeNode *T)
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->value;
    }
}
void LevelOrderTraverse(BiTreeNode *T)
{
    if(T)
    {
        vector<BiTreeNode*> vec;
        int cur=0,last=1;
        vec.push_back(T);
        while(cur<vec.size())
        {
            last=vec.size();
            while(cur<last)
            {
                cout<<vec[cur]->value;
                if(vec[cur]->lchild!=NULL)
                    vec.push_back(vec[cur]->lchild);
                if(vec[cur]->rchild!=NULL)
                    vec.push_back(vec[cur]->rchild);
                cur++;
            }
        }
    }
}
void DestroyBiTree(BiTreeNode *&T)
{
    if(T!=NULL)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        delete T;
    }
}

int main()
{
    BiTreeNode *pTree;
    pTree=CreateBiTree();
    while(pTree){
    InOrderTraverse(pTree);
    cout<<" ";
    PostOrderTraverse(pTree);
    cout<<" ";
    LevelOrderTraverse(pTree);
    cout<<endl;
    DestroyBiTree(pTree);
        pTree=CreateBiTree();

    }
    return 0;
}


