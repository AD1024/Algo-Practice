#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
using namespace std;
const int N=10000;
int L,num;
char CH[105],le[105];
int x[105],y[105],en[105],sj[105];
bool vis[30];
int read(){
    char ch=getchar();
    while (ch<'0' || ch>'9'){
        if (ch=='n') return N;
        ch=getchar();
    }
    int res=0;
    while (ch>='0' && ch<='9'){
        res=res*10+ch-'0';
        ch=getchar();
    }
    return res;
}
int dfs(int L,int R){
    if (sj[L]==-1) return 0;
    if (R==L+1)
        return sj[L];
    int M=0;
    for (int i=L+1;i<=R-1;i=en[i]+1)
        M=max(M,dfs(i,en[i]));
    return M+sj[L];
}
bool check(){
    int top=0,S[105];
    for (int i=1;i<=L;i++)
        if (CH[i]=='F'){
            if (vis[le[i]-'a']) return 0;
            S[++top]=i;
            vis[le[i]-'a']=1;
        }
        else{
            if (!top) return 0;
            en[S[top]]=i;
            vis[le[S[top]]-'a']=0;
            top--;
        }
    return (!top);
}
int main(){
    // freopen("testdata1.in","r",stdin);
    // freopen("testdata1.txt","w",stdout);
    int T; T=read();
    while (T--){
        L=read(),num=read();
        if (num==N) num=read(); else num=0;
        for (int i=1;i<=L;i++){
            CH[i]=getchar();
            while (CH[i]!='E' && CH[i]!='F') CH[i]=getchar();
            if (CH[i]=='E') continue;
            le[i]=getchar();
            while (le[i]<'a' || le[i]>'z') le[i]=getchar();
            x[i]=read(),y[i]=read();
            if (x[i]>y[i]) sj[i]=-1;
            else if (x[i]<N && y[i]==N) sj[i]=1;
            else sj[i]=0;
        }
        memset(vis,0,sizeof(vis));
        if (!check()){
            puts("ERR");
            continue;
        }
        en[0]=L+1,sj[0]=0;
        if (dfs(0,L+1)==num) puts("Yes"); else puts("No");
    }
    return 0;
} 