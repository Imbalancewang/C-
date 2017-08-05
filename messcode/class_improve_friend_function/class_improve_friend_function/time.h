//
//  time.h
//  class_improve_friend_function
//
//  Created by matthew on 2017/8/5.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef time_h
#define time_h
#include <iostream>
class Time
{
private:
    int minutes;
    int hours;
public:
    Time();
    Time(int h,int m=0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h=0,int m=0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    void show() const;
};

#endif /* time_h */
