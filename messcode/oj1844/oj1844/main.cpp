//
//  main.cpp
//  oj1844
//
//  Created by matthew on 2017/11/22.
//  Copyright © 2017 matthew. All rights reserved.
//
#include <iostream>
#define MAXSIZE 1050

typedef struct
{
    int i,j;
    int element;
    
}Triple;
typedef struct
{
    Triple data[MAXSIZE+1];
    int nu,mu,tu;
}TSmatrix;
void read(TSmatrix *M,int n,int m,int k);
void display(TSmatrix M);
void Transpose(TSmatrix M,TSmatrix *N);
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m,k;
    std::cin>>n>>m>>k;
    TSmatrix M,N;
    read(&M, n, m, k);
    Transpose(M, &N);
    display(N);
    return 0;
}
void read(TSmatrix *M,int n,int m,int k)
{
    (*M).mu=m;(*M).nu=n;(*M).tu=k;
    for(int i=0;i<k;i++)
        std::cin>>(*M).data[i].i>>(*M).data[i].j>>(*M).data[i].element;
}
void display(TSmatrix M)
{
    std::cout<<M.nu<<" "<<M.mu<<" "<<M.tu<<std::endl;
    for(int i=0;i<M.tu;i++){
        std::cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].element<<std::endl;
    }
}
void Transpose(TSmatrix M,TSmatrix *N)
{
    (*N).mu=M.nu;(*N).nu=M.mu;(*N).tu=M.tu;
    int q=0;
    for(int col=0;col<M.mu;++col)
        for(int p=0;p<M.tu;++p)
        {
            if(M.data[p].j==col)
            {
                (*N).data[q].i=M.data[p].j;
                (*N).data[q].j=M.data[p].i;
                (*N).data[q].element=M.data[p].element;
                q++;
            }
        }
}
