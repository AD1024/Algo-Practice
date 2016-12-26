#include <iostream>
#include <cstdio>
#include <cstdlib>
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
char* substring(char* ch,int pos,int length){  
    char* pch=ch;  
    char* subch=(char*)calloc(sizeof(char),length+1);    
    int i; 
    pch=pch+pos;
    for(i=0;i<length;i++){  
        subch[i]=*(pch++);  
    }  
    subch[length]='\0';
    return subch;
} 
int main(){
	char a[1001000];
	gets(a);
	int q;q=read();
	while(q--){
		int x,y,l;
		x=read();y=read();l=read();
		if(strcmp(substring(a,x-1,l),substring(a,y-1,l))==0){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}