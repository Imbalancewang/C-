//
//  main.cpp
//  oj11041458
//
//  Created by matthew on 2017/11/1.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
void stack_output(string str);
int main(int argc, const char * argv[]) {
    // insert code here...
    string str;
    while(cin>>str)
        stack_output(str);
    return 0;
}
void stack_output(string str)
{
    stack<int>s;
    for(int i=0,flag=0;i<str.size();i++)
    {
        if (str[i]=='P') {
            flag++;
            s.push(flag);
            
        }
        if (str[i]=='Q') {
            if (s.empty()) {
                cout<<"error ";
                break;
            }
            else{
                cout<<s.top()<<" ";
                s.pop();
            }
        }
    }
    cout<<endl;
}
