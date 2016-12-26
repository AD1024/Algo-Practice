#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char sec[200];
char org[200];
char str[200];
bool idx[200];
char dict[200],rdict[200];

int len;
inline bool parse(){
	for(int i=0;i<len;++i){
		if(!idx[org[i]]){
			idx[org[i]]=true;
			dict[sec[i]]=org[i];
			rdict[org[i]]=sec[i];
		}else{
			if(rdict[org[i]]!=sec[i]){
				return false;
			}
		}
	}
	for(int i='A';i<='Z';++i){
		if(!idx[i]){
			return false;
		}
	}
	return true;
}

inline void scan(){
	memset(dict,-1,sizeof(dict));
	scanf("%s",sec);
	scanf("%s",org);
	scanf("%s",str);
	len=strlen(sec);
}

inline void work(){
	if(parse()){
		for(int i=0;i<strlen(str);++i){
			if(dict[str[i]]!=-1){
				putchar(dict[str[i]]);
			}else{
				puts("Failed");
				return;
			}
		}
	}else{
		puts("Failed");return;
	}
}

int main(){
	scan();
	work();
	return 0;
}