//
//  ACCTABC.h
//  abstract_base_class
//
//  Created by matthew on 2017/8/12.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef ACCTABC_h
#define ACCTABC_h
#include <iostream>
#include <string>

class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;
protected:
    struct Formatting
    {
        std::ios_base::fmflags flag;
        std::streamsize pr;
    };
    const std::string & FullName()const {return fullName;}
    long AcctNum()const {return acctNum;}
    Formatting SetFormat()const;
    void Restore(Formatting &f)const;
public:
    AcctABC(const std::string &s="Nullbody",long an=-1,double bal=0.0);
    void Deposit(double amt);
    virtual void withdraw(double amt)=0;
    double Balance()const {return balance;}
    virtual void ViewAcct()const=0;
    virtual ~AcctABC(){}
};
class Brass : public AcctABC
{
public:
    Brass(const std::sting &s="Nullbody",long an=-1,double bal=0.0) : AcctABC(s,an,bal){}
    virtual void withdraw(double amt);
    virtual void ViewAcct()const;
    virtual ~Brass(){}
};
class BrassPlus : public AcctABC
{
private:
    double maxloan;
    double rate;
    double owesbank;
public:
    BrassPlus(const std::string &s="Nullbody",long an=-1,double bal=0.0,double ml=500,double r=0.10)
    BrassPlus(const Brass &ba,double ml=500,double r=0.10);
    virtual void withdraw(double amt);
    virtual void AcctABC()const;
    void ResetMax(double m){maxloan=m;}
    void ResstRate(double r){rate=r;}
    void ResetOwes(owesbank=0.0;)
};

#endif /* ACCTABC_h */
