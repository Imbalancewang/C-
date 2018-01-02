//
//  main.cpp
//  sparsematrix
//
//  Created by matthew on 2017/12/30.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#define MAX 12500
using namespace std;
typedef int  ElemType;
typedef struct
{
    int i,j;
    ElemType e;
}Triple;
typedef struct
{
    Triple data[MAX];
    int mu,nu,tu;
}TSMatrix;
int CreateSMatrix(TSMatrix &M);
int DestroySMaxtrix(TSMatrix &M);

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
