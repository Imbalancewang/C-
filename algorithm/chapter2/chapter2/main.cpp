//
//  main.cpp
//  chapter2
//
//  Created by matthew on 2017/7/18.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(int argc, const char * argv[]) {
    using namespace std;
    //2-1 daffofil
   /* int ge,shi,bai,sum;
    for(int number = 100;number <= 999;number++){
        ge=number%10;
        shi=number%100/10;
        bai=number/100;
        sum=ge*ge*ge+bai*bai*bai+shi*shi*shi;
        if(ge*ge*ge+bai*bai*bai+shi*shi*shi ==number){
            cout << number <<endl;
        }
    }*/
    //2-2 hanxin
   /* int a,b,c;
    while(cin>>a>>b>>c){
    for(int sum=10;sum<=100;sum++){
        if(sum%3==a&&sum%5==b&&sum%7==c){
            cout<<sum<<endl;
            break;
        }
        if(sum==100)
            cout<<"No answer"<<endl;
    }
    }*/
    //2-3 triangle
    /*int n,m;
    cin>>n;
    m=n;
    for(int i=1;i<=n;i++){
        for(int k=1;k<i;k++){
            cout<<" ";
        }
        for(int j=2*m-1;j>=1;j--){
            cout<<"*";
        }
        m--;
        cout<<endl;
    }*/
    //2-4 subsequence
    /*int n,m;
    for(int i=1;;i++){
        cin>>n>>m;
        if(n==0&&m==0){
            break;
        }
        float sum=0.0,val;
        for(int j=n;j<=m;j++){
            val=j;
            sum+=1/(val*val)*1.0;
        }
        printf("Case %d: %.5f\n",i,sum);
    }*/
    //2-5 decimal
    /*int a,b,c,i,decimal[101]={0};
    cin>>a>>b>>c;
    int integer=a/b,remain=a%b;
    for(i=1;i<=c;i++){
        decimal[i]=remain*10/b;
        remain=remain*10%b;
    }
    remain=remain*10/b;
   // cout<<i<<remain<<endl;
    if(remain>=5){
        cout<<integer<<".";
        for(int j=1;j<=i-2;j++){
            cout<<decimal[j];
        }
        cout<<decimal[i-1]+1;
    }
    else{
        cout<<integer<<".";
        for(int j=1;j<=i-1;j++){
            cout<<decimal[j];
        }
    }*/
    //2-6 permutation
   /* int abc,def,ghi,sum;
    int a[10]={0};
    for(abc=100;abc<=333;abc++){
        memset(a, 0, sizeof(a));
        sum=0;
        def=abc*2;
        ghi=abc*3;
        a[abc/100]=a[abc/10%10]=a[abc%10]=1;
        a[def/100]=a[def/10%10]=a[def%10]=1;
        a[ghi/100]=a[ghi/10%10]=a[ghi%10]=1;
        for(int i=1;i<10;i++){
            sum+=a[i];
        }
        if(sum==9){
            cout<<abc<<" "<<def<<" "<<ghi<<endl;
        }
    }*/
    return 0;
}
