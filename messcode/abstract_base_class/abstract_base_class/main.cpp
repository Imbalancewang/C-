//
//  main.cpp
//  abstract_base_class
//
//  Created by matthew on 2017/8/12.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "ACCTABC.h"
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::endl;
const int clients=1;

int main(int argc, const char * argv[]) {
    AcctABC *p_clients[clients];
    std::string temp;
    long tempnum;
    double tempbal;
    char kind;
    for(int i=0;i<clients;i++)
    {
        cout<<"Enter clients' name:"<<endl;
        getline(cin,temp);
        cout<<temp<<endl;
        cout<<"Enter clients' number:"<<endl;
        cin>>tempnum;
        cout<<"balance:"<<endl;
        cin>>tempbal;
        cout<<"Enter 1 for Brass or 2 for Brassplus"<<endl;
        while(cin>>kind&&(kind!='1'&&kind!='2'))
            cout<<"Enter 1 or 2"<<endl;
        if(kind=='1')
            p_clients[i]=new Brass(temp,tempbal,tempbal);
        else
        {
            double tmax,trate;
            cout<<"Enter the overdraft: "<<endl;
            cin>>tmax;
            cout<<"rate:"<<endl;
            cin>>trate;
            p_clients[i]=new BrassPlus(temp,tempnum,tempbal,tmax,trate);
        }
        while(cin.get()!='\n')
            continue;
    }
    cout<<endl;
    for(int i=0;i<clients;i++)
    {
        p_clients[i]->ViewAcct();
        cout<<endl;
    }
    for(int i=0;i<clients;i++)
    {
        delete p_clients[i];
    }
    return 0;
}
