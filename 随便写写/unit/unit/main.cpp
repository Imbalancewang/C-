//
//  main.cpp
//  unit
//
//  Created by matthew on 2017/7/18.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <climits>

int main(int argc, const char * argv[]) {
    using namespace std;
    //symbols defined in climits file.
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_long_long = LLONG_MAX;
    
    //sizeof operator yields size of type or if variable.
    cout << "int is "<< sizeof(int) << "bytes" << endl;
    cout << "short is " << sizeof(short) << "bytes" << endl;
    cout << "long is" << sizeof(long) << "bytes" << endl;
    cout << "long long is" <<sizeof(n_long_long) << "bytes" << endl;
    
    cout << "Maximum values:" << endl;
    cout << "int:" << n_int <<endl;
    cout << "short:" << n_short <<endl;
    cout << "long:" << n_long << endl;
    cout << "long long :" << n_long_long << endl <<endl;
    
    cout << "Minimum int value=" << INT_MIN <<endl;
    cout << " Bits per byte=" << CHAR_BIT <<endl;
    return 0;
}
