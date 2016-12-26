#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;
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

int main(){
	ll x;
	while(~scanf("%lld",&x)){
		ll N=x;
		if(x==1) {
			puts("0");
			continue;
		}else if(x==2){
			puts("1");
			continue;
		}
		while(!(x&(x-1))){
			x--;
		}
		ll tms = log(x)/log(2);
		ll k=N-x;
		if(k>x){
			tms+=2;
		}else tms+=1;
		write(tms);
		puts("");
	}
	puts("0");
	return 0;
}