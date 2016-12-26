#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int cur=0;
int p1,p2,p3;
char str[110];
char a[10001];

inline void parse(int idx){
	char dist,k;
	bool star=(p1==3);
	if(str[idx-1]>='a' && str[idx-1]<='z'){
		dist=(p1==1?str[idx+1]-1:str[idx+1]-33);
		k=(p1==1?str[idx-1]+1:str[idx-1]-31);
		if(p3==1){
			while(k<=dist){
				for(int i=0;i<p2;++i){
					a[cur++]=star?'*':k;
				}
				++k;
			}
		}else{
			while(dist>=k){
				for(int i=0;i<p2;++i){
					a[cur++]=star?'*':dist;
				}
				dist--;
			}
		}
	}else{
		dist=str[idx+1]-1;
		k=str[idx-1]+1;
		if(p3==1){
			while(k<=dist){
				for(int i=0;i<p2;++i){
					a[cur++]=star?'*':k;
				}
				++k;
			}
		}else{
			while(dist>=k){
				for(int i=0;i<p2;++i){
					a[cur++]=star?'*':dist;
				}
				dist--;
			}
		}
	}
}

int main(){
	cin>>p1>>p2>>p3;
	cin>>str;
	int len=strlen(str);
	for(int i=0;i<len;++i){
		if((str[i]>='a' && str[i]<='z') || (str[i]>='0' && str[i]<='9')){
			a[cur++]=str[i];
		}else if(str[i+1]>str[i-1] && ((isalpha(str[i+1]) && isalpha(str[i-1])) || (isdigit(str[i-1]) && isdigit(str[i+1])))){
			parse(i);
		}else{
			a[cur++]=str[i];
		}
	}
	puts(a);
	return 0;
}