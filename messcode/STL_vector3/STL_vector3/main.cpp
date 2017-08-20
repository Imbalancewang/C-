//
//  main.cpp
//  STL_vector3
//
//  Created by matthew on 2017/8/20.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
struct review
{
    std::string title;
    int rating;
};
bool operator<(const review &r1,const review&r2);
bool worsethan(const review &r1,const review&r2);
bool fillreview(review &rr);
void showreview(const review&rr);
int main(int argc, const char * argv[]) {
    using namespace std;
    vector<review> books;
    review temp;
    while(fillreview(temp))
        books.push_back(temp);
    if(books.size()>0)
    {
        cout<<"Thank you. You enter the following "<<books.size()<<endl;
        for_each(books.begin(), books.end(), showreview);
        sort(books.begin(),books.end());
        cout<<"sorted by title"<<endl;
        for_each(books.begin(), books.end(), showreview);
        sort(books.begin(), books.end(), worsethan);
        cout<<"sorted by rating"<<endl;
        for_each(books.begin(), books.end(), showreview);
        random_shuffle(books.begin(), books.end());
        cout<<"after shuffle"<<endl;
        for_each(books.begin(), books.end(), showreview);
    }
    else
        cout<<"no"<<endl;
    return 0;
}
bool operator<(const review &r1,const review &r2)
{
    if(r1.title<r2.title)
        return true;
    else if(r1.title==r2.title && r1.rating<r2.rating)
        return true;
    else
        return false;
}
bool worsethan(const review &r1,const review &r2)
{
    if(r1.rating<r2.rating)
        return true;
    else
        return false;
}
bool fillreview(review &rr)
{
    std::cout<<"enter book title: ";
    std::getline(std::cin,rr.title);
    if(rr.title=="quit")
        return false;
    std::cout<<"enter book rating"<<std::endl;
    std::cin>>rr.rating;
    if(!std::cin)
        return false;
    while(std::cin.get()!='\n')
        continue;
    return true;
}
void showreview(const review &rr)
{
    std::cout<<rr.rating<<"\t"<<rr.title<<std::endl;
}
