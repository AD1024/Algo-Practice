#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

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
void write(int a){    
    if(a < 0){  
        putchar('-');  
        a = -a;  
    }  
    if(a >= 10){  
        write(a / 10);  
    }         
    putchar(a % 10 + '0');    
}
int main(){
	int N;N=read();
	write(((1+N)*N)>>1);
	return 0;
}