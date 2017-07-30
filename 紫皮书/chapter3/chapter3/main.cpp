//
//  main.cpp
//  chapter3
//
//  Created by matthew on 2017/7/19.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctype.h>
#include <cstring>

int judge(char[],int);
using namespace std;
int main(int argc, const char * argv[]) {
    //3-1 score
   /* string str1;
    int sum,ct;
    while(cin>>str1){
        sum=0;
        for(int i=0,ct=1;i<str1.size();i++){
            if(str1[i]=='o'){
                sum+=ct;
                ct++;
            }
            else{
                ct=1;
            }
        }
        cout<<sum<<endl;
    }*/
    //3-2 Molar Mass
    char s[105];
    scanf("%s",s);
    int i;
    int sum=0;
    double m=0,n=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='A'&&s[i]<'Z')   //if(isupper(s[i]))
        {
            char c;
            c=s[i];
            switch (c)
            {
                case 'C':
                    n=12.01;break;
                case 'H':
                    n=1.008;break;
                case 'O':
                    n=16.00;break;
                case 'N':
                    n=14.01;break;
            }
            sum=0;
        }
        while(isdigit(s[i]))
        {
            sum=sum*10+s[i]-'0';
            if(!isdigit(s[i+1]))
            {
                break;
            }
            else 
                i++;
        }
        if(sum!=0)
            m+=sum*n;
        else if(s[i+1]>='A'&&s[i+1]<='Z'||i==strlen(s)-1)          //else if(isupper(s[i+2])||i==strlen(s)-1)
            m+=n;
    }
    printf("%.3f\n",m);
    //3-3 digit counting
  /*  int n,flag;
    int number[12];
    cin>>n;
    memset(number, 0, sizeof(number));
    for(int i=1;i<=n;i++){
        flag=i;
        while(flag){
            number[flag%10]++;
            flag=flag/10;
        }
    }
    for(int i=0;i<10;i++){
        cout<<number[i]<<" ";
    }*/
    //3-4 periodic strings
   /* char str1[100];
    int sublen;
    cin>>str1;
        for(int i=1;i<=strlen(str1);i++){
            if(strlen(str1)%i==0){
                sublen=judge(str1,i);
                if(sublen){
                    cout<<sublen<<endl;
                    break;
                }
            }
        }*/
    //3-5 puzzle
 /*   char maps[5][7];
    char cmd[1001];
    int cases = 0;
    while (gets(maps[0])) {
        if (maps[0][0] == 'Z') break;
        for (int i = 1 ; i < 5 ; ++ i)
            gets(maps[i]);
        int b_x = 0,b_y = 0;
        for (int i = 0 ; i < 5 ; ++ i)
            for (int j = 0 ; j < 5 ; ++ j)
                if (maps[i][j] == ' ') {
                    b_x = i;b_y = j;
                    break;
                }
        int count = 0;
        while (~scanf("%c",&cmd[count]))
            if (cmd[count] != '0') count ++;
            else break;
        cmd[count] = 0;getchar();
        int flag = 0,x = b_x,y = b_y;
        for (int i = 0 ; cmd[i] ; ++ i) {
            switch(cmd[i]) {
                case 'A':	x = b_x-1;y = b_y; break;
                case 'B':	x = b_x+1;y = b_y; break;
                case 'L':	x = b_x;y = b_y-1; break;
                case 'R':	x = b_x;y = b_y+1; break;
            }
                
                if (x < 0 || x > 4 || y < 0 || y > 4) {
                    flag = 1;break;
                }else {
                    maps[b_x][b_y] = maps[x][y];
                    maps[x][y] = ' ';
                    b_x = x; b_y = y;
                }
            }
            
            if (cases ++) printf("\n");
            printf("Puzzle #%d:\n",cases);
            
            if (flag)
                printf("This puzzle has no final configuration.\n");
            else {
                for (int i = 0 ; i < 5 ; ++ i) {
                    printf("%c",maps[i][0]);
                    for (int j = 1 ; j < 5 ; ++ j)
                        printf(" %c",maps[i][j]);
                    printf("\n");
                }
            }
        }*/
    
        return 0;
}
int judge(char str[100],int sublen){
    char str1[50],str2[50];
    if(sublen==strlen(str)){
        return sublen;
    }
    else{
        for(int i=0;i<sublen;i++){
            str1[i]=str[i];
            str2[i]=str[sublen+i];
        }
        
        if(!strcmp(str1, str2)){
            return sublen;
        }
        else
            return 0;
    }
}
