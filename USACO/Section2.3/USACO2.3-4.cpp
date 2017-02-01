/*
ID: ccodera1
LANG: C++
TASK: money
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define OJ

long long dp[10001];

int N,a[10010];
int v;
int main(){
	#ifdef OJ
		freopen("money.in","r",stdin);
		freopen("money.out","w",stdout);
	#endif
	cin>>v>>N;
	for(int i=1;i<=v;++i){
		cin>>a[i];
	}
	for(int i=0;i<=N;++i){
		if(i % a[1] == 0){
			dp[i] = 1;
		}
	}
	for(int i=2;i<=v;++i){
		for(int j=1;j<=N;++j){
			if(j >= a[i]){
				dp[j] += dp[j-a[i]];
			}
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}