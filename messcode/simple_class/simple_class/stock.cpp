//
//  stock.cpp
//  masterplate_function
//
//  Created by matthew on 2017/8/4.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "Header.h"

Stock::Stock()
{
    std::cout<<"Default constructor called"<<std::endl;
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
Stock::Stock(const std::string &co,long n,double pr)
{
    std::cout<<"construct using"<<co<<"call"<<std::endl;
    company=co;
    if(n<0)
    {
        std::cout<<"number of shares can't be negative"
        <<company<<"shares set to 0.\n";
        shares=0;
    }
    else
        shares=n;
    share_val=pr;
    set_tot();
}
Stock::~Stock()
{
    std::cout<<"bye"<<std::endl;
}
void Stock::buy(long num,double price)
{
    if(num<0){
        std::cout<<"something must be wrong"<<std::endl;
    }
    else{
        shares+=num;
        share_val=price;
        set_tot();
    }
}
void Stock::sell(long num, double price)
{
    using std::cout;
    if(num<0)
    {
        cout<<"something must be wrong"<<std::endl;
    }
    else if(num>shares){
        cout<<"you can't sell more"<<std::endl;
    }
    else{
        shares-=num;
        share_val=price;
        set_tot();
    }
}
void Stock::update(double price)
{
    share_val=price;
    set_tot();
}
void Stock::show()const
{
    std::cout<<"company"<<company<<std::endl
    <<"shares:"<<shares<<std::endl
    <<"price:"<<share_val<<std::endl
    <<"total worth:"<<total_val<<std::endl;
}

