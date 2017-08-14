//
//  main.cpp
//  public_inheritance
//
//  Created by matthew on 2017/8/14.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "worker.h"
const int LIM=4;
int main(int argc, const char * argv[]) {
    Waiter bob("Bob",314,5);
    Singer mat("matthew",321,3);
    Waiter w_temp;
    Singer s_temp;
    Worker *pw[LIM]={&bob,&mat,&w_temp,&s_temp};
    int i;
    for(i=2;i<LIM;i++)
        pw[i]->Set();
    for(i=0;i<2;i++)
        pw[i]->Show();
    return 0;
}
