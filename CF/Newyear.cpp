#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int read(){    
    char ch;  
    bool flag=false;  
    int a=0;    
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch=='-')));    
    if(ch != '-'){  
        a*=10;  
        a+=ch-'0';    
    }  
    else{  
        flag = true;  
    }  
    while(((ch=getchar())>='0')&&(ch<='9')){  
        a*=10;  
        a+=ch - '0';  
    }     
    if(flag){  
        a=-a;  
    }  
    return a;    
}    
void write(int a){    
    if(a<0){  
        putchar('-');  
        a=-a;  
    }  
    if(a>=10){  
        write(a/10);  
    }         
    putchar(a%10+'0');    
}

int main(){
	int a[3];
	a[0]=read();a[1]=read();a[2]=read();
	sort(a,a+2);
	int ans=0x3f3f3f3f;
	for(int i=a[0];i<=a[2];++i){
		if(i-a[0]+a[2]-i+abs(a[1]-i)<ans){
			ans=i-a[0]+a[2]-i+abs(a[1]-i);
		}
	}
	write(ans);
	return 0;
}