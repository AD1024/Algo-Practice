#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
//#define OJ
#define TINT(x) x-'A'
int Index[40],flag;
char a[40],b[40],c[40];
int N;
int num[40];
bool vis[40];
int cnt=0;
inline void Rev(char str[]){
    for(int i=1;i<=N/2;++i){
        str[i]^=str[N-i+1]^=str[i]^=str[N-i+1];
    }
}
inline bool ok(int idx){
    int k=0;
    int x,y,z;
    for(int i=1;i<=idx;++i){
        x=TINT(a[i]);
        y=TINT(b[i]);
        z=TINT(c[i]);
        if(Index[x]==-1 || Index[y]==-1 || Index[z]==-1) return true;
        z=Index[z];
        int t=Index[x]+Index[y]+k;
        k=t/N;
        t%=N;
        if(t!=z) return false;
    }
    return true;
}
void f(int dep){
    if(flag) exit(0);
    //IMPORTANT 剪枝
    for(int i=1;i<=dep;i++){
        int aa=a[i]-'A',bb=b[i]-'A',cc=c[i]-'A';
        aa=Index[aa];bb=Index[bb],cc=Index[cc];
        if(bb!=-1&&cc!=-1&&aa!=-1)
            if((aa+bb)%N!=cc&&(aa+bb+1)%N!=cc) return;
    }
    if(!ok(dep)) return;
    if(dep==N){
        //if(ok(N)){
            flag=true;
            for(int i=0;i<N;++i){
                cout<<Index[i]<<" ";
            }
            return;
        //}
    }else{
        int k=num[dep+1];
        for(int i=N-1;i>=0;--i){
            if(!vis[i]){
                vis[i]=true;
                Index[k]=i;
                f(dep+1);
                vis[i]=false;
                Index[k]=-1;
            }
        }
    }
}
int main(){
    #ifdef OJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>N;
    memset(Index,-1,sizeof(Index));
    int x,y,z;
    scanf("%s%s%s",a+1,b+1,c+1);
    Rev(a);Rev(b);Rev(c);
    for(int i=1;i<=N;++i){
        x=TINT(a[i]);y=TINT(b[i]);z=TINT(c[i]);
        if(!vis[x]){
            vis[x]=true;
            num[++cnt]=x;
        }
        if(!vis[y]){
            vis[y]=true;
            num[++cnt]=y;
        }
        if(!vis[z]){
            vis[z]=true;
            num[++cnt]=z;
        }
    }
    memset(vis,false,sizeof(vis));
    f(0);
    #ifdef OJ
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}