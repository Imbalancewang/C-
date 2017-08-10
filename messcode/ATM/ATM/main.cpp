//
//  main.cpp
//  ATM
//
//  Created by matthew on 2017/8/10.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "queue.h"
#include <ctime>
#include <cstdlib>
const int MIN_PER_HR=60;
bool newcustomer(double x);
int main(int argc, const char * argv[]) {
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;
    std::srand(std::time(0));
    cout<<"enter maximun length of queue"<<endl;
    int qs;
    cin>>qs;
    Queue line(qs);
    cout<<"enter the simulation hours"<<endl;
    int hours;
    cin>>hours;
    long cyclelimit=MIN_PER_HR*hours;
    cout<<"enter the average hour of customer per hour"<<endl;
    double perhour;
    cin>>perhour;
    double min_per_cust;
    min_per_cust=MIN_PER_HR / perhour;
    Item temp;
    long turnaways=0;
    long customers=0;
    long served=0;
    long sum_line=0;
    int wait_time=0;
    long line_wait=0;
    for(int cycle=0;cycle<cyclelimit;cycle++)
    {
        if(newcustomer(min_per_cust))
        {
            if(line.isfull())
                turnaways++;
            else
            {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
            }
        }
        if(wait_time<=0&&!line.isempty())
        {
            line.dequeue(temp);
            wait_time=temp.ptime();
            line_wait+=cycle-temp.when();
            served++;
        }
        if(wait_time>0)
            wait_time--;
        sum_line+=line.queuecount();
    }
    if(customers>0)
    {
        cout<<"customers accepted: "<<customers<<endl;
        cout<<"customers served:"<<served<<endl;
        cout<<"turnaways:"<<turnaways<<endl;
        cout<<"average queue size:";
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout<<(double)sum_line/cyclelimit<<endl;
        cout<<"average wait_time:"<<(double)line_wait/served<<"minutes"<<endl;
    }
        else
            cout<<"No customes"<<endl;
        cout<<"Done"<<endl;
    return 0;
    return 0;
}
bool newcustomer(double x)
{
    return (std::rand()*x/RAND_MAX<1);
}
