//
//  main.cpp
//  chapter3+
//
//  Created by matthew on 2017/7/23.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef struct _node
{
    int  id;
    char str[12];
}node;

node data[101];
char maps[12][12];
int  size[12][12];

int cmp(node a, node b)
{
    return a.id < b.id;
}

int main()
{
    //3-6 crossword answer
    /*int row,column,times = 1;
    while (cin >> row && row) {
        cin >> column;
        for (int i = 0; i < row; ++ i)
            cin >> maps[i];
        int id = 1;
        for (int i = 0; i < row; ++ i)
            for (int j = 0; j < column; ++ j)
                if (maps[i][j] != '*' && (!i || !j || maps[i-1][j] == '*' || maps[i][j-1] == '*'))
                    size[i][j] = id ++;
                else size[i][j] = 0;
        
        if  (times > 1) printf("\n");
        printf("puzzle #%d:\n",times ++);
        printf("Across\n");
        for (int i = 0; i < row; ++ i) {
            int move = 0;
            while (move < column) {
                if (size[i][move]) {
                    printf("%3d.",size[i][move]);
                    int save = 0;
                    while (move < column && maps[i][move] != '*')
                        printf("%c",maps[i][move ++]);
                    printf("\n");
                }else move ++;
            }
        }
        
        printf("Down\n");
        int count = 0;
        for (int i = 0; i < column; ++ i) {
            int move = 0;
            while (move < row) {
                if (size[move][i]) {
                    data[count].id = size[move][i];
                    int save = 0;
                    while (move < row && maps[move][i] != '*')
                        data[count].str[save ++] = maps[move ++][i];
                    data[count ++].str[save ++] = 0;
                }else move ++;
            }
        }
        sort(data, data+count, cmp);
        for (int i = 0; i < count; ++ i)
            printf("%3d.%s\n",data[i].id, data[i].str);
    }*/
    //3-7 DNA consensus string
  /*  int m,n;
    cin>>m>>n;
    string dna[60];
    int value[4][1005]={0};
    for(int i=0;i<m;i++)
        cin>>dna[i];
    for(int j=0;j<n;j++){
        for(int i=0;i<m;i++){
            switch (dna[i][j]) {
                case 'A':value[0][j]++;break;
                case 'C':value[1][j]++;break;
                case 'G':value[2][j]++;break;
                case 'T':value[3][j]++;break;
                default:
                    break;
            }
        }
    }
    for(int j=0;j<n;j++){
        if(value[0][j]>=value[1][j]&&value[0][j]>=value[2][j]&&value[0][j]>=value[3][j])
            cout<<'A';
        else if(value[1][j]>value[0][j]&&value[1][j]>=value[2][j]&&value[2][j]>=value[3][j])
            cout<<'C';
        else if(value[2][j]>value[0][j]&&value[2][j]>value[1][j]&&value[2][j]>value[3][j])
            cout<<'G';
        else if(value[3][j]>value[0][j]&&value[3][j]>value[1][j]&&value[3][j]>value[2][j])
            cout<<'T';
    }*/
    //3-8 repeating decimals
    int a,b,middle;
    int remain[3000];
    cin>>a>>b;
    
    return 0;
}
