#include<iostream>
#include<cstring> //#include<queue.h> //s.push()  s.pop()  s.top()
using namespace std;
typedef struct Node
{
    char data;
    struct Node *lchild,*rchild;
}Treelist;
typedef struct
{
    Treelist *c[2010];
    int front ,rear;
}Queue;
Treelist *Input(Treelist *T,char a)//t,0 0  m-1
{
    if(a=='\n')return T;
    else
    {
        if(a=='#')
            T=NULL;
        else
        {
            T=new Treelist;
            T->data=a;
            T->lchild=T->rchild=NULL;
            a=getchar();
            T->lchild=Input(T->lchild,a);
            a=getchar();
            T->rchild=Input(T->rchild,a);
        }
        return T;
    }
    
}
int InTraverse(Treelist *T)
{
    if(T==NULL)
        return 0;
    InTraverse(T->lchild);
    cout<<T->data;
    InTraverse(T->rchild);
    return 1;
}
void ReTraversal(Treelist *T)//后序
{
    if(T!=NULL)
    {
        ReTraversal(T->lchild);//左孩子输出
        ReTraversal(T->rchild);//右孩子输出
        cout<<T->data;//根输出
        return;
    }
}
int LevelTraverse(Treelist *T)
{
    if(T==NULL)return 0;
    Queue *Q=new Queue;//出错点：分配空间的
    Q->front=Q->rear=0;
    Q->c[++Q->rear]=T;
    while(Q->front!=Q->rear)
    {
        T=Q->c[++Q->front];
        cout<<T->data;
        if (T->lchild!=NULL)
            Q->c[++Q->rear]=T->lchild;
        if (T->rchild!=NULL)
            Q->c[++Q->rear]=T->rchild;
    }
    return 1;
}
void destroy(Treelist *T)//用递归销毁即可
{
    if(T!=NULL)
    {
        destroy(T->lchild);
        destroy(T->rchild);
        delete T;
    }
}
int main()
{
    Treelist *T=NULL;
    char x;
    int m,n,count=0;
    while((x=getchar())!=EOF)
    {
        T=Input(T,x);
        InTraverse(T);
        cout<<' ';
        ReTraversal(T);
        cout<<' ';
        LevelTraverse(T);
        cout<<endl;
        destroy(T);
        T=NULL;
        getchar();//吸掉每次输入结束的'\n'
    }
    return 0;
    
}
