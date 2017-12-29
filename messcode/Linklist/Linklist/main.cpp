//
//  main.cpp
//  Linklist
//
//  Created by matthew on 2017/12/27.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
using namespace std;
typedef struct Poly
{
    int coef;
    int exp;
    struct Poly *next;
}Poly,*Polynomial;
int Init(Polynomial &p);
int Destroy(Polynomial &p);
int read(Polynomial &p);
int display(Polynomial &p);
int Polyder(Polynomial &p);
int addPoly(Polynomial &pa,Polynomial &pb,Polynomial &res);
int multiplyPoly(Polynomial &pa,Polynomial &pb,Polynomial &res);
int main(int argc, const char * argv[]) {
    // insert code here...
    Poly* p;Polynomial q,res;
    Init(p);Init(q);Init(res);
    read(p);read(q);
    multiplyPoly(p, q, res);
    //addPoly(p, q, res);
    //Polyder(p);
    //display(p);
    display(res);
    
    return 0;
}
int Init(Polynomial &p)
{
    p=new Poly;
    p->next=NULL;
    p->coef=p->exp=-1;
    return 0;
}
int read(Polynomial &p)
{
    Polynomial tmp=p;
    int tmpcoef,tmpexp;
    while(cin>>tmpcoef>>tmpexp)
    {
        if (tmpexp==-1&&tmpcoef==-1) {
            break;
        }
        Polynomial t;
        t=new Poly;
        t->coef=tmpcoef;
        t->exp=tmpexp;
        t->next=NULL;
        tmp->next=t;
        tmp=t;
    }
    return 0;
}
int display(Polynomial&p)
{
    Poly *tmp=p;
    int flag=0;
    while(tmp->next)
    {
        tmp=tmp->next;
        if(tmp->coef)
        {
            cout<<tmp->coef<<" "<<tmp->exp<<" ";
            flag=1;
        }
    }
    if(!flag)
        cout<<"0";
    cout<<endl;
    return 0;
}
int Polyder(Polynomial &p)
{
    Polynomial tmp=p;
    while(tmp->next)
    {
        Polynomial temp=tmp;
        tmp=tmp->next;
        tmp->coef=tmp->coef*tmp->exp;
        tmp->exp--;
        if(!tmp->coef || tmp->exp<0)
        {
            temp->next=tmp->next;
            
        }
        else{
            temp=temp->next;
        }
    }
    return 0;
}
int addPoly(Polynomial &pa,Polynomial &pb,Polynomial &res)
{
    Polynomial qa=pa->next,qb=pb->next;
    Polynomial head=res;
    while(qa&&qb)
    {
        if(qa->exp<qb->exp)
        {
            Polynomial temp;
            temp=new Poly;
            temp->coef=qb->coef;
            temp->exp=qb->exp;
            temp->next=NULL;
            head->next=temp;
            head=temp;
            qb=qb->next;
        }
        else if(qa->exp==qb->exp)
        {
            Polynomial temp;
            temp=new Poly;
            temp->coef=qa->coef+qb->coef;
            temp->exp=qa->exp;
            temp->next=NULL;
            head->next=temp;
            head=temp;
            qa=qa->next;
            qb=qb->next;
        }
        else if(qa->exp>qb->exp)
        {
            Polynomial temp;
            temp=new Poly;
            temp->coef=qa->coef;
            temp->exp=qa->exp;
            temp->next=NULL;
            head->next=temp;
            head=temp;
            qa=qa->next;
        }
    }
    head->next=qa==NULL?qb:qa;
    return 0;
}
int Destroy(Polynomial &p)
{
    while(p)
    {
        Polynomial l=p;
        p=p->next;
        delete l;
    }
    return 0;
}
int multiplyPoly(Polynomial &pa,Polynomial &pb,Polynomial &res)
{
    Polynomial qa=pa->next;
    while(qa)
    {
        Polynomial temp;
        Init(temp);
        Polynomial qb=pb->next;
        Polynomial head=temp;
        while(qb)
        {
            Polynomial t;
            t=new Poly;
            t->coef=qb->coef*qa->coef;
            t->exp=qb->exp+qa->exp;
            t->next=NULL;
            head->next=t;
            head=t;
            qb=qb->next;
        }
        //display(temp);
        addPoly(res, temp, res);
       // Destroy(temp); memory leak?
        // add the destroy answer error;
      //  display(res);
        qa=qa->next;
    }
    return 0;
}
