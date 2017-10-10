//
//  main.cpp
//  oj106910701071
//
//  Created by matthew on 2017/10/3.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
struct poly{
    int coef=0;
    int exp=0;
};
const int MAX=5000;
typedef int Status;
Status read(poly *a);
Status diff(poly *a,poly *b);
Status add(poly *c,poly *b,poly *res);
Status multiply(poly *a,poly *b,poly *res);
Status display(poly *a);
int main(int argc, const char * argv[]) {
    poly a[MAX],b[MAX],res[MAX];
    read(a);
    //read(b);
    //multiply(a, b, res);
    //add(a, b, res);
    //display(res);
    diff(a, b);
    display(b);
    //display(a);
    return 0;
}
Status read(poly *a)
{
    for(int i=0;;i++)
    {
        std::cin>>a[i].coef>>(*(a+i)).exp;
        if(a[i].coef==-1 && a[i].exp==-1)
            break;
    }
    return 0;
}

Status diff(poly *a,poly *b)
{
    for(int i=0;;i++)
    {
        b[i].exp=a[i].exp-1;
        b[i].coef=a[i].exp*a[i].coef;
        if(a[i].coef==-1 && a[i].exp==-1)
        {
            b[i].exp=-1;
            break;
        }
    }
    return 0;
}
Status add(poly *c,poly *b,poly *res)
{
    int k=0;
    poly a[MAX];
    for(int w=0;w<MAX;)
    {
        a[w].coef=c[w].coef;
        a[w].exp=c[w].exp;
        w++;
    }
  //  display(a);
    for(int i=0,j=0;;)
    {
       // std::cout<<"loop";
        if(a[i].exp==-1 &&b[j].exp==-1)
            break;
        else if(a[i].exp>b[j].exp)
        {
            res[k].coef=a[i].coef;
            res[k].exp=a[i].exp;
            i++;k++;
        }
        else if(a[i].exp<b[j].exp)
        {
            //std::cout<<"2";
            res[k].exp=b[j].exp;
            res[k].coef=b[j].coef;
            j++;k++;
        }
        else if(a[i].exp==b[j].exp)
        {
            //std::cout<<"3";
            res[k].exp=a[i].exp;
            res[k].coef=a[i].coef+b[j].coef;
            k++;i++;j++;
        }
    }
    res[k].exp=-1;
    return 0;
}
Status multiply(poly *a,poly *b,poly *res)
{
    poly temp[MAX];int j;
    res[0].coef=-1;
    res[0].exp=-1;
    for(int i=0;;)
    {
        if(a[i].exp==-1 && a[i].coef==-1)
            break;
        else
        {
            memset(temp, 0, sizeof(temp));
            for(j=0;;)
            {
                if(b[j].exp==-1)
                    break;
                temp[j].coef=a[i].coef*b[j].coef;
                temp[j].exp=a[i].exp+b[j].exp;
                j++;
            }
            temp[j].exp=-1;
            temp[j].coef=-1;
        }
        add(res,temp,res);
        //std::cout<<"second";
        //display(res);
        i++;
    }
    return 0;
}
Status display(poly *a)
{
    int flag=0;
    for(int i=0;a[i].exp>=0;i++)
    {
        if (a[i].coef!=0) {
            std::cout<<a[i].coef<<" "<<a[i].exp<<" ";
            flag=1;
        }
    }
    if(!flag)
        std::cout<<"0";
    std::cout<<std::endl;
    return 0;
}
