#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

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

typedef long long ll;
#define MAXN 1001
#define mid(x,y) (x+y)>>1
ll T[MAXN];
ll pre[MAXN];
ll post[MAXN];
ll N,M;
ll L,R;

int main(){
    N=read();M=read();
    for(int i=1;i<=N;++i){
        T[i]=read();
    }
    sort(T+1,T+1+N);
    for(int i=1;i<=N;++i){
        pre[i]=pre[i-1]+T[i]; // prefix sum
    }
    for(int i=0;i<=N;++i){
        post[i]=pre[N]-pre[i]; // sufix sum
    }
    int upper,lower;
    while(M--){
        L=read();R=read();
        int u,v;
        u=0;
        v=N;
        while(1){ //find upper bound
            if(u==v){
                upper=u;
                break;
            }else if(v-u==1){
                if(pre[v]<=R){
                    upper=v;
                }else{
                    upper=u;
                }
                break;
            }
            if(pre[mid(u,v)]<=R){
                u=mid(u,v);
            }else v=mid(u,v);
        }
        u=0;
        v=N;
        while(1){ // find lower bound
            if(u==v){
                lower=N-u;
                break;
            }
            else if(v-u==1){
                if(post[u]>=L){
                    lower=N-u;
                }else{
                    lower=N-v;
                }
                break;
            }
            if(post[mid(u,v)]>=L){
                v=mid(u,v);
            }else u=mid(u,v);
        }
        bool ok=false;
        if((pre[lower]<=R && lower==N) || (pre[upper]>=L && upper==1)){
            ok=true;
            puts("-1");
        }else if(upper<lower){
            ok=true;
            puts("-1");
        }else{
            for(int i=lower;i<=upper;++i){
                if(pre[i]<L || post[N-i]>R){
                    write(i);
                    putchar('\n');
                    ok=true;
                    break;
                }
            }
        }
        if(!ok){
            puts("-1");
        }
    }
    return 0;
}