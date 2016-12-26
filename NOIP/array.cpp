#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

set<int> s;

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
int x;
int main(){
	N=read();
	while(N--){
		x=read();
		s.insert(x);
	}
	printf("%d\n",(int)s.size());
	return 0;
}