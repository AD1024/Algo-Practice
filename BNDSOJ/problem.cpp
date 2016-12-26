#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

int C[2010][2010];
int K,M,N;

ll cnt=0;int T;
int dp[2010][2010];

int main(){
	cin>>T>>K;
	C[0][0]=1%K;C[1][0]=1%K;
	C[1][1]=1%K;C[2][0]=1%K;
	C[2][1]=2%K;C[2][2]=1%K;
	for(int i=2;i<=2001;++i){
		C[i][0]=1;C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%K;
		}
	}
	for(int i=0;i<=2001;++i){
		int cnt=0;
		for(int j=i;j<=2001;++j){
			if(C[j][i]==0){
				dp[j][i]=++cnt;
			}else dp[j][i]=cnt;
		}
	}
	
	for(int i=0;i<=2001;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]+=dp[i][j-1];
		}
	}
// for(int i=0;i<=10;++i){
// 		for(int j=0;j<=i;++j){
// 			cout<<dp[i][j]<<' ';
// 		}
// 		putchar('\n');
// 	}
	while(T--){
		cin>>N>>M;
		printf("%d\n",dp[N][min(N,M)]);
	}
	return 0;
}