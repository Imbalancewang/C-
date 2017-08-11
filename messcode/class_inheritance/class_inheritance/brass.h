//
//  brass.h
//  class_inheritance
//
//  Created by matthew on 2017/8/11.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef brass_h
#define brass_h
#include <string>

class Brass
{
private:
    std::string fullname;
    long acctNum;
    double balance;
public:
    Brass(const std::string &s="Nullbody",long an=-1,double bal=0.0);
    void Deposit(double amt);
    virtual void Withdraw(double amt);
    double Balance()const;
    virtual void ViewAcct()const;
    virtual ~Brass(){};
};

class BrassPlus : public Brass
{
private:
    double maxloan;
    double rate;
    double owesBank;
public:
    BrassPlus(const std::string &s="Nullbody",long an=-1,double bal=0.0,double ml=500,double r=0.11125);
    BrassPlus(const Brass &ba,double ml=500,double r=0.11125);
    virtual void ViewAcct()const;
    virtual void Withdraw(double amt);
    void ResetMax(double m){maxloan=m;}
    void ResetRate(double r){rate=r;}
    void ResetOwes() {owesBank=0;}
};
#endif /* brass_h */
