//
//  main.cpp
//  oj1092
//
//  Created by matthew on 2017/11/22.
//  Copyright © 2017 matthew. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
int countnextval(std::string str,int *nextval);
int main(int argc, const char * argv[]) {
    // insert code here...
    std::string str;
    int nextval[205];
    while (1) {
        std::cin>>str;
        countnextval(str, nextval);
        for(int i=0;i<str.size();i++)
            std::cout<<nextval[i]<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
int countnextval(std::string str,int *nextval)
{
    nextval[0]=-1;
    int i=0,j=-1;
    while(i!=str.size()-1)
    {
        if(j==-1||str[i]==str[j])
        {
            ++i;
            ++j;
            if(str[i]!=str[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
    return 0;
}
