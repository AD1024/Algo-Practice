#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main(){
	char str[200010];
	scanf("%s",str);
	int len=strlen(str);
	for(int i=1;str[i];i++){
		if(str[i]==str[i-1]){
			for(char s='a';s<='z';++s){
				if(s!=str[i-1] && s!=str[i+1]){
					str[i]=s;
					break;
				}
			}
		}
	}
	puts(str);
	return 0;
}
