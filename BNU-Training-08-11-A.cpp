#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

char str[110][110];

int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>str[i];
	}
	bool flag=false;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			if(str[i][j]=='#'){
				if(str[i+1][j]=='#' && str[i+2][j]=='#' && str[i+1][j-1]=='#' && str[i+1][j+1]=='#'){
					str[i][j]='x';
					str[i+1][j]='x';
					str[i+2][j]='x';
					str[i+1][j-1]='x';
					str[i+1][j+1]='x';
				}else{
					flag=true;
					break;
				}
			}
		}
	}
	if(flag){
		puts("NO");
	}else{
		puts("YES");
	}
	return 0;
}