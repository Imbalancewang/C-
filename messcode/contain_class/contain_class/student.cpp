//
//  student.cpp
//  contain_class
//
//  Created by matthew on 2017/8/16.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <string>
#include "student.h"
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::string;
double student::average()const
{
    if(scores.size()>0)
        return scores.sum()/scores.size();
    else
        return 0;
}
const string &student::Name()const
{
    return name;
}
double &student::operator[](int i)
{
    return scores[i];
}
double student::operator[](int i)const
{
    return scores[i];
}
ostream &student::arr_out(std::ostream &os) const
{
    int i;
    int lim=scores.size();
    if(lim>0)
    {
        for(i=0;i<lim;i++)
        {
            os<<scores[i]<<" ";
            if(i%5==4)
                os<<endl;
        }
        if(i%5!=0)
            os<<endl;
    }
    else
        os<<"empty array";
    return os;
}
istream &operator>>(istream &is,student &stu)
{
    is>>stu.name;
    return is;
}
istream &getline(istream &is,student &stu)
{
    getline(is, stu.name);
    return is;
}
ostream &operator<<(ostream &os,const student &stu)
{
    os<<"scores for"<<stu.name<<endl;
    stu.arr_out(os);
    return os;
}
