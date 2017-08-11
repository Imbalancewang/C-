//
//  brass.cpp
//  class_inheritance
//
//  Created by matthew on 2017/8/11.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include "brass.h"
#include <iostream>
using std::cin;
using std::endl;
using std::cout;
using std::string;
typedef std:: ios_base::fmtflags format;
typedef std:: streamsize precis;
format setFormat();
void restore(format f,precis p);

Brass::Brass(const string &s,long an,double bal)
{
    fullname=s;
    acctNum=an;
    balance=bal;
}
void Brass::Deposit(double amt)
{
    if(amt<0)
        cout<<"Negative deposit not allowed"<<endl;
    else
        balance+=amt;
}
void Brass::Withdraw(double amt)
{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    if(amt<0)
        cout<<"withdrawal amout not allowed"<<endl;
    else if(amt<=balance)
        balance-=amt;
    else
        cout<<"money is not enough, withdrawal cancelled"<<endl;
    restore(initialState, prec);
}
double Brass::Balance()const
{
    return balance;
}
void Brass::ViewAcct()const
{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    cout<<"Client: "<<fullname<<endl;
    cout<<"Account: "<<acctNum<<endl;
    cout<<"Balance $: "<<balance<<endl;
    restore(initialState, prec);
}
BrassPlus::BrassPlus(const string &s,long an,double bal,double ml,double r) : Brass(s,an,bal)
{
    maxloan=ml;
    rate=r;
    owesBank=0.0;
}
BrassPlus::BrassPlus(const Brass &ba,double ml,double r) : Brass(ba)
{
    maxloan=ml;
    owesBank=0.0;
    rate=r;
}
void BrassPlus::ViewAcct()const
{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    Brass::ViewAcct();
    cout<<"Maximun loan: "<<maxloan<<endl;
    cout<<"owed to bank: "<<owesBank<<endl;
    cout.precision(3);
    cout<<"loan rate: "<<rate<<endl;
    restore(initialState, prec);
}
void BrassPlus::Withdraw(double amt)
{
    format initialState=setFormat();
    precis prec=cout.precision(2);
    double bal=Balance();
    if(amt<=bal)
        Brass::Withdraw(amt);
    else if (amt<=bal+maxloan-owesBank)
    {
        double advance=amt-bal;
        owesBank+=advance*(1.0+rate);
        cout<<"bank advance: "<<advance<<endl;
        cout<<"Finance charge: "<<advance*rate<<endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout<<"Transaction cancelled"<<endl;
    restore(initialState, prec);
}
format setFormat()
{
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}
void restore(format f,precis p)
{
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}

