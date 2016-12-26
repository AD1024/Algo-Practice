#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

inline int read()    
{    
    char ch;  
    bool flag = false;  
    int a = 0;    
    while(!((((ch = getchar()) >= '0') && (ch <= '9')) || (ch == '-')));    
    if(ch != '-')  
    {  
        a *= 10;  
        a += ch - '0';    
    }  
    else  
    {  
        flag = true;  
    }  
    while(((ch = getchar()) >= '0') && (ch <= '9'))  
    {  
        a *= 10;  
        a += ch - '0';  
    }     
    if(flag)  
    {  
        a = -a;  
    }  
    return a;    
}    
void write(int a)    
{    
    if(a < 0)  
    {  
        putchar('-');  
        a = -a;  
    }  
    if(a >= 10)  
    {  
        write(a / 10);  
    }         
    putchar(a % 10 + '0');    
}

//-----Tmp
typedef long long ll;
ll f[25][25][25];
inline void init(){
	f[1][1][1]=1;
	for(ll i=2;i<=24;++i){
		for(ll j=1;j<=i;++j){
			for(ll k=1;k<=i;++k){
				if(j+k>=3 && j+k<=i+1){
					f[i][j][k]=f[i-1][j-1][k]+f[i-1][j][k-1]+f[i-1][j][k]*(i-2);
				}
			}
		}
	}
}
int main(){
	int T;T=read();
	init();
	while(T--){
		ll n,l,r;
		scanf("%lld%lld%lld",&n,&l,&r);
		printf("%lld\n",f[n][l][r]);
	}
}