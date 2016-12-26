#include <iostream>
using namespace std;

int g[10][10];
bool used[10];
char a[10];
bool found;
void f(int idx){
	if(idx>5){
		found=true;
		for(int i=1;i<5;++i){
			cout<<a[i]<<" ";
		}
		putchar(a[5]);
	}else{
		for(int i=1;i<=5;++i){
			if(!used[i]){
				if(g[idx][i]){
					used[i]=true;
					a[idx]='A'+i-1;
					f(idx+1);
					used[i]=false;
				}
			}
		}
	}
}

int main(){
	for(int i=1;i<=5;++i){
		for(int j=1;j<=5;++j){
			cin>>g[i][j];
		}
	}
	f(1);
	if(!found){
		puts("no");
	}
	return 0;
}