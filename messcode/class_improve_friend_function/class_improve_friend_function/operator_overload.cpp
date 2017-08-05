//
//  operator_overload.cpp
//  class_improve_friend_function
//
//  Created by matthew on 2017/8/5.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "time.h"

Time::Time()
{
    minutes=0;
    hours=0;
}
Time::Time(int h,int m)
{
    hours=h;
    minutes=m;
}
void Time::AddMin(int m)
{
    minutes+=m;
    hours+=minutes/60;
    minutes%=60;
}
void Time::AddHr(int h)
{
    hours+=h;
}
void Time::Reset(int h,int m)
{
    hours=h;
    minutes=m;
}
Time Time::operator+(const Time &t)const
{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hours=hours+t.hours+sum.minutes/60;
    sum.minutes%=60;
    return sum;
}
Time Time::operator-(const Time &t)const
{
    Time diff;
    int tot1,tot2;
    tot1=t.minutes+60*t.hours;
    tot2=minutes+60*hours;
    diff.minutes=(tot2-tot1)%60;
    diff.hours=(tot2-tot1)/60;
    return diff;
}
Time Time::operator*(double n)const
{
    Time res;
    int totmin=hours*n*60+minutes*n;
    res.hours=totmin/60;
    res.minutes=totmin%60;
    return res;
}
void Time::show()const
{
    std::cout<<hours<<"hours,"<<minutes<<"minutes"<<std::endl;
}
