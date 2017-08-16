//
//  student.h
//  contain_class
//
//  Created by matthew on 2017/8/16.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef student_h
#define student_h
#include <iostream>
#include <string>
#include <valarray>
class student
{
private:
    typedef std::valarray<double> arraydb;
    std::string name;
    arraydb scores;
    std::ostream & arr_out(std::ostream &os)const;
public:
    student() : name("null student"),scores(){}
    explicit student(const std::string &s) : name(s),scores(){}
    explicit student(int n) : name("nully"),scores(n){}
    student(const std::string &s,const arraydb &a) : name(s),scores(a){}
    student(const char *str,const double *pd,int n) : name(str),scores(pd,n){}
    ~student(){}
    double average()const;
    const std::string &Name()const;
    double &operator[](int i);
    double operator[](int i)const;
    friend std::istream &operator>>(std::istream&is,student &stu);
    friend std::istream &getline(std::istream &is,student stu);
    friend std::ostream &operator<<(std::ostream &os,const student &stu);
};
#endif /* student_h */
