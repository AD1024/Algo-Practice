#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
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
    if(a<0){
        putchar('-');
        a = -a;
    }
    if(a>=10){
        write(a / 10);
    }
    putchar(a % 10 + '0');
}

int N;
int a[10001];
int main(){
	N=read();
	int lap=1;
	for(int i=1;i<=N;++i)
		a[i]=i;
	for(int i=1;i<=10000;++i){
		int k=(k+i)%N;
		if(!k) k=N;
		a[k]=-1;
	}
	bool flag=true;
	for(int i=1;i<=N;++i){
		if(a[i]!=-1){
			flag=false;
			write(a[i]);
			putchar(' ');
		}
	}
	if(flag){
		puts("It is Nice!");
	}
	return 0;
}