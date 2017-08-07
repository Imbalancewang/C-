//
//  Header.h
//  class_axis
//
//  Created by matthew on 2017/8/7.
//  Copyright © 2017年 matthew. All rights reserved.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
namespace VECTOR
{
    class Vector
    {
    public:
        enum Mode {RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1,double n2,Mode form=RECT);
        ~Vector();
        double xval()const{return x;}
        double yval()const{return y;}
        double magval()const{return mag;}
        double angval()const{return ang;}
        void polar_mode();
        void rect_mode();
        void reset(double n1,double n2,Mode form);
        Vector operator+(const Vector &b)const;
        Vector operator-(const Vector &b)const;
        Vector operator*(double n)const;
        Vector operator-()const;
        friend Vector operator*(double n,Vector &a);
        friend std::ostream &operator<<(std::ostream &os,const Vector &v);
    };
}

#endif /* Header_h */
