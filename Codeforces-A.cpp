#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char g[1001][5];
int N;
int main(){
	cin>>N;
	bool found=false;
	for(int i=0;i<N;++i){
		cin>>g[i];
		if(!found){
			if(g[i][0]==g[i][1] && g[i][0]=='O' && !found){
				g[i][0]=g[i][1]='+';
				found=true;
			}

			if(g[i][3]==g[i][4] && g[i][4]=='O' && !found){
				g[i][3]=g[i][4]='+';
				found=true;
			}
		}
	}
	if(!found) puts("NO");
	else{
		puts("YES");
		for(int i=0;i<N;++i){
			for(int j=0;j<4;++j){
				printf("%c",g[i][j]);
			}
			printf("%c\n",g[i][4]);
		}
	}
	return 0;
}