#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10100];
int ans[10100];

int N;

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		if(a[i]>3){
			puts("No answer");return 0;
		}
	}
	if(a[1]>2 || a[N]>2){
		puts("No answer");
	}else if(a[1]==2 && a[2]<2){
		puts("No answer");
	}else if(a[N] == 2 && a[N-1]<2){
		puts("No answer");
	}else{
		if(a[1]==1){
			ans[1] = 1;
		}else{
			ans[1] = ans[2] = 1;
		}
		if(a[N] == 1){
			ans[N] = 1;
		}else{
			ans[N] = ans[N-1] = 1;
		}
		for(int i=1;i<=N;++i){
			if(a[i] == 3){
				for(int j=i-1;j<=i+1;++j){
					if(j && j<=N){
						if(ans[j]){
							puts("No answer");
							return 0;
						}
						ans[j] = 1;
					}
				}
			}
		}
		int cnt;
		int stat[4];
		int cur;
		for(int i=2;i<N;++i){
			cnt = cur = 0;
			memset(stat,0,sizeof(stat));
			for(int j=i-1;j<=i+1;++j){
				if(ans[j]){
					++cnt;
					stat[++cur] = 1;
				}
			}
			if(cnt == a[i]) continue;
			else if(cnt > a[i]){
				puts("No answer");
			}else{
				int diff = a[i] - cnt;
				for(int j=1;j<=3;++j){
					if(!stat[i]){
						ans[i-1+j] = 1;
					}
				}
			}
		}
		for(int i=1;i<=N;++i){
			cout<<ans[i]<<" ";
		}
	}
	return 0;
}