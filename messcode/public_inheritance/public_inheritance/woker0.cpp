//
//  woker0.cpp
//  public_inheritance
//
//  Created by matthew on 2017/8/14.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include "worker.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
Worker::~Worker(){}
void Worker::Set()
{
    cout<<"enter name"<<endl;
    getline(cin,fullname);
    cout<<"enter id"<<endl;
    cin>>id;
    while(cin.get()!='\n')
        continue;
}
void Worker::Show()const
{
    cout<<"Name: "<<fullname<<endl;
    cout<<"ID: "<<id<<endl;
}
void Waiter::Set()
{
    Worker::Set();
    cout<<"enter panache: "<<endl;
    cin>>panache;
    while(cin.get()!='\n')
        continue;
}
void Waiter::Show()const
{
    Worker::Show();
    cout<<"panache: "<<panache<<endl;
}
string Singer::pv[]={"other","alto","contralto","soprano","bass","baritone","tenor"};
void Singer::Set()
{
    Worker::Set();
    cout<<"enter number:"<<endl;
    int i;
    for(int i=0;i<Vtype;i++)
    {
        cout<<i<<": "<<pv[i]<<" ";
        if(i%4==3)
            cout<<endl;
    }
    if(i%4!=0)
        cout<<endl;
    while(cin>>voice&&(voice<0||voice>=Vtype))
        cout<<"please enter correctly"<<endl;
    while(cin.get()!='\n')
        continue;
}
void Singer::Show()const
{
    cout<<"singer"<<endl;
    Worker::Show();
    cout<<"voice:"<<pv[voice]<<endl;
}
