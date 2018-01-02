//
//  main.cpp
//  TripleTable
//
//  Created by matthew on 2018/1/1.
//  Copyright © 2018年 matthew. All rights reserved.
//

#include <iostream>
#define MAXSIZE 12500
using namespace std;
typedef int ElemType;
typedef struct Triple
{
    int i,j;
    ElemType e;
}Triple;
typedef struct TSMatrix
{
    Triple data[MAXSIZE];
    int mu,nu,tu;
}TSMatrix;
int CreateSMatrix(TSMatrix &M);
int DestroySMatrix(TSMatrix &M);
int PrintSMatrix(TSMatrix &M);
int FastTranspose(TSMatrix &M,TSMatrix &T);
int main(int argc, const char * argv[]) {
    // insert code here...
    TSMatrix M,T;
    CreateSMatrix(M);
    PrintSMatrix(M);
    FastTranspose(M,T);
    PrintSMatrix(T);
    //std::cout << "Hello, World!\n";
    return 0;
}
int CreateSMatrix(TSMatrix &M)
{
    int mu,nu;
    cout<<"please input the size of matrix"<<endl;
    cin>>mu>>nu;
    cout<<"please input the matrix by order"<<endl;
    M.mu=mu;M.nu=nu;
    int flag;
    for(flag=0;;flag++)
    {
        cin>>M.data[flag].i>>M.data[flag].j>>M.data[flag].e;
        if(M.data[flag].i==0&&M.data[flag].j==0&&M.data[flag].e==0)
            break;
    }
    M.tu=flag;
    return 0;
}
//int DestroySMatrix(TSMatrix &M);
int PrintSMatrix(TSMatrix &M)
{
    cout<<"The Matrix"<<endl;
    cout<<M.mu<<" "<<M.nu<<" "<<M.tu<<endl;
    for (int i=0; i<M.tu; i++) {
        cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].e<<endl;
    }
    return 0;
}
int FastTranspose(TSMatrix &M,TSMatrix &T)
{
    T.mu=M.nu;T.nu=M.mu;T.tu=M.tu;
    int num[M.tu],cpot[M.tu];
    if(T.tu)
    {
        for(int col=0;col<M.tu;col++)
            num[col]=0;
        for(int col=0;col<M.tu;col++)
            ++num[M.data[col].j];
        cpot[0]=1;
        for(int col=1;col<M.tu;col++)
            cpot[col]=cpot[col-1]+num[col-1];
        int col,q;
        for(int p=0;p<=M.tu;p++)
        {
            col=M.data[p].j;
            q=cpot[col];
            T.data[q].i=M.data[p].j;
            T.data[q].j=M.data[p].i;
            T.data[q].e=M.data[p].e;
            ++cpot[col];
        }
    }
    return 0;
}
