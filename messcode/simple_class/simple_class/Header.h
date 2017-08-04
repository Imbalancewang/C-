//
//  Header.h
//  masterplate_function
//
//  Created by matthew on 2017/8/4.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef HEADER_H
#define HEADER_H
#include <string>
class Stock{
private:
    std::string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){total_val=shares*share_val;}
public:
    Stock();
    ~Stock();
    Stock(const std::string &co,long n=0,double pr=0.0);
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show()const;
    const Stock &topval(const Stock &s)const;
};


#endif /* Header_h */
