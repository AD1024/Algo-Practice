#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
bool vis[40010];
int prime[40010];
int n;
bool idx[40010];
void init(){
    memset(vis,true,sizeof(vis));  
    memset(prime,0,sizeof(prime));
    int num=0;  
    for (int i=2;i<=32767;++i){  
        if (vis[i]==true){  
            num++;  
            prime[num] = i;  
            idx[i]=true;
        }  
        for (int j=1;((j<=num) && (i*prime[j]<=32767));++j){  
            vis[i*prime[j]]=false;  
            if (i%prime[j]==0) break;  
        }  
    }  
}
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
const int Pow[5]={1,10,100,1000,10000};
int stack[10];
int top=0;

inline int Reverse(int x){
	while(x){
		stack[++top]=x%10;
		x/=10;
	}
	int ret=0;
	int cur=0;
	while(top>0){
		ret+=stack[top--]*Pow[cur++];
	}
	return ret;
}

int main(){
	n=read();
	init();
	if(idx[n] && idx[Reverse(n)]){
		puts("Yes");
	}else{
		puts("no");
	}
	return 0;
}