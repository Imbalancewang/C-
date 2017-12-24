//
//  main.cpp
//  oj1296
//
//  Created by matthew on 2017/12/19.
//  Copyright © 2017年 matthew. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
struct Node
{
    Node * lchild;
    Node * rchild;
    char c;
};
Node *rebuild(string s1, string s2)
{
    Node * t=NULL;
    if(s1.size()>0){
        t=new Node;
        t->c=s1[0];
        t->lchild=NULL;
        t->rchild=NULL;
    }
    if(s1.size()>1){
        int root;
        for(int i=0; i<s2.size(); i++){
            if(s2[i]==t->c){
                root=i;
                break;
            }
        }
        string qianxu_left=s1.substr(1, root);
        string zhongxu_left=s2.substr(0, root);
        t->lchild=rebuild(qianxu_left, zhongxu_left);
        string qianxu_right=s1.substr(root+1, s1.size()-root-1);
        string zhongxu_right=s2.substr(root+1, s2.size()-root-1);
        t->rchild=rebuild(qianxu_right, zhongxu_right);
    }
    
    return t;
}
void houxu(Node * t)
{
    if(t->lchild!=NULL)
        houxu(t->lchild);
    if(t->rchild!=NULL)
        houxu(t->rchild);
    cout<<t->c;
}

int main()
{
    string s1, s2;
    int n;
    cin>>n;
    while(n--){
        cin>>s1>>s2;
        Node * t=rebuild(s1, s2);
        houxu(t);
        cout<<endl;
    }
    
    return 0;
}
