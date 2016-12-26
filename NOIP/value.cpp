#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
int N;
int a[100100];
int main(){
	N=read();
	for(int i=1;i<=N;++i){
		a[i]=read();
	}
	long long sum=0;
	for(int i=2;i<=N;++i){
		sum+=abs(a[i]-a[i-1]);
	}
	printf("%lld\n",sum);
	return 0;
}