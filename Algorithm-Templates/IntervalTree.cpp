#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 100100
#define lson(x) x<<1
#define rson(x) x<<1|1
#define Mid(x,y) (x+y)>>1
int A[1001];
inline int read(){ // ReadInt
    char ch;
    bool flag = false;
    int a=0;
    while(!((((ch=getchar())>='0') && (ch<='9')) || (ch=='-')));
    if(ch!='-'){
        a *= 10;
        a += ch - '0';
    }
    else{
        flag = true;
    }
    while(((ch=getchar())>='0')&& (ch<='9')){
        a *= 10;
        a += ch - '0';
    }
    if(flag){
        a = -a;
    }
    return a;
}

struct Node{
    int sum;
    int Max,Min;
    int lson,rson;
    Node(){
        sum=0;
        Max=-INF;
        Min=INF;
        lson=rson=0;
    }
}Tree[1000<<1]; // Double space

inline void Maintain(int k){ // Pass the value of sons to the father node.
    Tree[k].sum=Tree[lson(k)].sum+Tree[rson(k)].sum; // Maintain the sum.
    Tree[k].Max=max(Tree[lson(k)].Max,Tree[rson(k)].Max); // Maintain Max value;
    Tree[k].Min=min(Tree[lson(k)].Min,Tree[rson(k)].Min); // Maintain Min value;
}

void Build(int rt,int l,int r){ // Build up an IntervalTree by using a sequence of number
    Tree[rt].lson=l;Tree[rt].rson=r;
    if(l==r){ // Reach a leaf node
        Tree[rt].sum=A[l];
        Tree[rt].Min=Tree[rt].Max=Tree[rt].sum;
        return;
    }
    int mid=Mid(l,r);
    Build(lson(rt),l,mid); // Build left son(l to mid)
    Build(rson(rt),mid+1,r); // Buld right son(mid+1 to r)
    Maintain(rt); // Maintain the value of father node.
}

void Update(int rt,int p,int value,bool change){
    if(Tree[rt].lson==p && Tree[rt].lson==Tree[rt].rson){
        if(change){
            Tree[rt].sum=value;
            Tree[rt].Max=value;
            Tree[rt].Min=value;
        }else{
            Tree[rt].sum+=value;
            Tree[rt].Max+=value;
            Tree[rt].Min+=value;
        }
        return;
    }
    int mid=Mid(Tree[rt].lson,Tree[rt].rson);
    if(p<=mid){
        Update(lson(rt),p,value,change);
    }else{
        Update(rson(rt),p,value,change);
    }
    Maintain(rt);
}

int QuerySum(int rt,int l,int r){ // Query the sum of inverval [l,r]
    if(Tree[rt].lson==l && Tree[rt].rson==r){
        return Tree[rt].sum;
    }else{
        int mid=Mid(Tree[rt].lson,Tree[rt].rson); // Find the mid point
        if(r<=mid){								  // Cond 1: The interval that we are seeking is contained in the interval of left node
            return QuerySum(lson(rt),l,r);
        }else if(l>mid){						  // Cond 2: The interval that we are seeking is contained in the interval in the right node.
            return QuerySum(rson(rt),l,r);
        }else{	
        	// IMPORTAINT: the half of the interval that we are seeking is contained 
        	// in the interval of left node 
        	// and the other half is contained in that of right node.								  
            return QuerySum(lson(rt),l,mid)+QuerySum(rson(rt),mid+1,r);
        }
    }
}
/*
* The idea is assemble that of QuertSum
*/
int QueryMax(int rt,int l,int r){
    if(Tree[rt].lson==l && Tree[rt].rson==r){
        return Tree[rt].Max;
    }else{
        int mid=Mid(Tree[rt].lson,Tree[rt].rson);
        if(r<=mid){
            return QueryMax(lson(rt),l,r);
        }else if(l>mid){
            return QueryMax(rson(rt),l,r);
        }else return max(QueryMax(lson(rt),l,mid),QueryMax(rson(rt),mid+1,r));
    }
}

int QueryMin(int rt,int l,int r){
    if(Tree[rt].lson==l && Tree[rt].rson==r){
        return Tree[rt].Min;
    }else{
        int mid=Mid(Tree[rt].lson,Tree[rt].rson);
        if(r<=mid){
            return QueryMin(lson(rt),l,r);
        }else if(l>mid){
            return QueryMin(rson(rt),l,r);
        }else return min(QueryMin(lson(rt),l,mid),QueryMin(rson(rt),mid+1,r));
    }
}

#define NL putchar('\n')
int main(){
    int N;N=read();
    for(int i=1;i<=N;++i) A[i]=read();
    Build(1,1,N);
    int op;
    while(~scanf("%d",&op)){
        switch(op){
            case 1:{
                int l,r;l=read();r=read();
                cout<<QuerySum(1,l,r);
                NL;
                break;
            }
            case 2:{
                int l,r;l=read();r=read();
                cout<<QueryMax(1,l,r);
                NL;
                break;
            }
            case 3:{
                int l,r;l=read();r=read();
                cout<<QueryMin(1,l,r);
                NL;
                break;
            }
            case 4:{
                int pos,val;pos=read();val=read();
                bool mod=read();
                Update(1,pos,val,mod);
                break;
            }
        }
    }
    return 0;
}