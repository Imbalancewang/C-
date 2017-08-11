//
//  main.cpp
//  class_inheritance
//
//  Created by matthew on 2017/8/11.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "brass.h"
using std::cin;
using std::endl;
using std::string;
using std::cout;

int main(int argc, const char * argv[]) {
    Brass piggy("porcelot piggy",343242348,4000.00);
    BrassPlus hoggy("fsdfsdfsd hoggy",53456572,90000.00);
    piggy.ViewAcct();
    cout<<endl;
    hoggy.ViewAcct();
    cout<<"hoggy->1000->piggy"<<endl;
    piggy.Deposit(1000.00);
    hoggy.Withdraw(1000.00);
    cout<<endl;
    piggy.ViewAcct();
    hoggy.ViewAcct();
    return 0;
}
