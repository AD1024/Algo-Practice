#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define MID(x,y) (x+y)>>1
#define bk break
typedef long long ll;
typedef void V;

struct Node{
    ll lson,rson,Max,Min;
    ll sum;
    ll maxLen;
    Node(){
        sum=0;
        Max=-0x3f3f3f3f;
        Min=0x3f3f3f3f;
        maxLen=0;
    }
}Tree[100100<<1];

ll A[100100<<1];

inline bool valid(int x){
    int num=x%10;
    x/=10;
    while(x){
        if(x%10!=num) return false;
        x/=10;
    }
    return true;
}

inline int getLen(int x){
    int l=0;
    while(x){
        l++;
        x/=10;
    }
    return l;
}

inline V maintain(int idx){
    Tree[idx].sum=Tree[lson(idx)].sum+Tree[rson(idx)].sum;
    Tree[idx].Max = max(Tree[lson(idx)].Max,Tree[rson(idx)].Max);
    Tree[idx].Min = min(Tree[lson(idx)].Min,Tree[rson(idx)].Min);
    Tree[idx].maxLen = max(Tree[lson(idx)].maxLen,Tree[lson(idx)].maxLen);
}

V BuildTree(int rt,int l,int r){
    Tree[rt].lson = l;
    Tree[rt].rson = r;
    if(l==r){
        Tree[rt].sum=A[l];
        Tree[rt].Max=A[l];
        Tree[rt].Min=A[l];
        if(valid(A[l])){
            Tree[rt].maxLen=getLen(A[l]);
        }
        return;
    }
    int mid=MID(l,r);
    BuildTree(lson(rt),l,mid);
    BuildTree(rson(rt),mid+1,r);
    maintain(rt);
}

V update(int rt,int pos,int val,bool mod){
    if(Tree[rt].lson==Tree[rt].rson && Tree[rt].lson==pos){
        if(mod){
            Tree[rt].sum+=val;
            Tree[rt].Max+=val;
            Tree[rt].Min+=val;
            
        }else{
            Tree[rt].sum+=Tree[rt].Max-val;
            Tree[rt].Max=val;
            Tree[rt].Min=val;
        }
        if(valid(Tree[rt].Max)){
            if(getLen(Tree[rt].Max)>Tree[rt].maxLen){
                Tree[rt].maxLen=getLen(Tree[rt].Max);
            }
        }
        return;
    }
    int mid=MID(Tree[rt].lson,Tree[rt].rson);
    if(pos<=mid){
        update(lson(rt),pos,val,mod);
    }else
        update(rson(rt),pos,val,mod);
    maintain(rt);
}

ll QuerySum(int rt,int l,int r){
    if(l==Tree[rt].lson and Tree[rt].rson==r){
        return Tree[rt].sum;
    }else{
        int mid = MID(Tree[rt].rson,Tree[rt].lson);
        ll ans=0;
        if(r<=mid){
            ans+=QuerySum(lson(rt),l,r);
        }else if(l>=mid+1){
            ans+=QuerySum(rson(rt),l,r);
        }else{
            ans+=QuerySum(lson(rt),l,mid);
            ans+=QuerySum(rson(rt),mid+1,r);
        }
        return ans;
    }
}

ll RMinQ(int rt,int l,int r){
    if(l==Tree[rt].lson and r==Tree[rt].rson){
        return Tree[rt].Min;
    }else{
        int mid = MID(Tree[rt].lson,Tree[rt].rson);
        ll ret=0x3f3f3f3f;
        if(r<=mid){
            ret=min(ret,RMinQ(lson(rt),l,r));
        }else if(l>=mid+1){
            ret=min(ret,RMinQ(rson(rt),l,r));
        }else{
            ret=min(ret,RMinQ(lson(rt),l,mid));
            ret=min(ret,RMinQ(rson(rt),mid+1,r));
        }
        return ret;
    }
}

ll RMaxQ(int rt,int l,int r,bool ch){
    if(l==Tree[rt].lson and r==Tree[rt].rson){
        if(ch)
            return Tree[rt].Max;
        else return Tree[rt].maxLen;
    }else{
        int mid = MID(Tree[rt].lson,Tree[rt].rson);
        ll ans=-0x33f3f;
        if(r<=mid){
            ans=max(ans,RMaxQ(lson(rt),l,r,ch));
        }else if(l>=mid+1){
            ans=max(ans,RMaxQ(rson(rt),l,r,ch));
        }else{
            ans=max(ans,RMaxQ(lson(rt),l,mid,ch));
            ans=max(ans,RMaxQ(rson(rt),mid+1,r,ch));
        }
        return ans;
    }
}

inline long long read(){
    char ch;
    bool flag = false;
    long long a=0;
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
void write(long long a){
    if(a < 0){
        putchar('-');
        a = -a;
    }
    if(a >= 10){
        write(a / 10);
    }
    putchar(a % 10 + '0');
}
ll N,M;
int main(){
    N=read();M=read();
    for(int i=1;i<=N;++i){
        A[i]=read();
    }
    BuildTree(1,1,N);
    int l,r,op,val;
    while(M--){
        op=read();
        switch(op){
            case 1:{
                l=read();r=read();val=read();
                for(register int i=l;i<=r;++i){
                    update(1,i,val,1);
                }
                bk;
            }
            case 2:{
                l=read();r=read();val=read();
                val=-val;
                for(register int i=l;i<=r;++i){
                    update(1,i,val,1);
                }
                bk;
            }
            case 3:{
                l=read();r=read();val=read();
                val=-val;
                for(register int i=l;i<=r;++i){
                    update(1,i,val,0);
                }
                bk;
            }
            case 4:{
                l=read();r=read();
                write(QuerySum(1,l,r));
                putchar('\n');
                bk;
            }
            case 5:{
                l=read();r=read();
                write(RMinQ(1,l,r));
                putchar('\n');
                bk;
            }
            case 6:{
                l=read();r=read();
                write(RMaxQ(1,l,r,1));
                putchar('\n');
                bk;
            }
            case 7:{
                l=read();r=read();
                write(RMaxQ(1,l,r,0));
				putchar('\n');
                bk;
            }
        }
    }
    return 0;
}