#include <iostream>
#include <cstdio>
#include <cstring>
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
queue<int> q;
int N;

int main(){
	N=read();
	for(int i=1;i<=N;++i) q.push(i);
	while(q.size()!=1){
		q.push(q.front());
		q.pop();
		q.push(q.front());
		q.pop();
		q.pop();
	}
	write(q.front());
	return 0;
}