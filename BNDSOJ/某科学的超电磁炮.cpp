#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char g[1100][1100];

int M,N,C;

inline int read(){
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
int ans=0;
inline void work(int x,int y){
    for(int i=x;i>=0;--i){
        if(g[i][y]=='#'){
            ans--;
            g[i][y]='.';
        }
    }
    for(int i=x;i<N;++i){
        if(g[i][y]=='#'){
            ans--;
            g[i][y]='.';
        }
    }
    for(int i=y;i>=0;--i){
        if(g[x][i]=='#'){
            ans--;
            g[x][i]='.';
        }
    }
    for(int i=y;i<M;++i){
        if(g[x][i]=='#'){
            ans--;
            g[x][i]='.';
        }
    }
}

int main(){
    N=read();M=read();
    C=read();
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>g[i][j];
            if(g[i][j]=='#'){
                ++ans;
            }
        }
    }
    int x,y;
    while(C--){
        x=read();y=read();
        work(x,y);
    }
    printf("%d\n",ans);
    return 0;
}