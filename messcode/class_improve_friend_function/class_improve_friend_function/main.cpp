//
//  main.cpp
//  class_improve_friend_function
//
//  Created by matthew on 2017/8/5.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include "time.h"
int main(int argc, const char * argv[]) {
    using std::cout;
    using std::endl;
    Time weeding(4,35);
    Time waxing(2,44);
    Time total;
    Time diff;
    Time adj;
    cout<<"weeding="<<endl;
    weeding.show();
    cout<<"waxing="<<endl;
    waxing.show();
    total=weeding+waxing;
    cout<<"total="<<endl;
    total.show();
    return 0;
}
