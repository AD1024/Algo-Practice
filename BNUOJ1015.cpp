#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string msg;
char ch;
//const char list[28]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
inline void NEXT(){
	if(ch>'Z') ch='A';
}

int main(){
    int x,y;
    cin>>x>>y;
    int cur=0;
    int last;
    getchar();
    while(getline(cin,msg)){
        char g[1001][1001];
        cur=0;
        ch='A';
        //parse(msg);
        string::iterator s = msg.begin();
        string::iterator e = msg.end();
        while(s!=e){
        	if(isalpha(*s)){
           		g[cur/y][cur%y]=toupper(*s);
            	++cur;
        	}
            ++s;
        }
        while(cur<x*y){
        	NEXT();
            g[cur/y][cur%y]=ch++;
            cur++;
        }
        for(int i=0;i!=y;i++){
            for(int j=0;j!=x;j++){
                putchar(g[j][i]);
            }
        }
        puts("");
    }
    return 0;
}