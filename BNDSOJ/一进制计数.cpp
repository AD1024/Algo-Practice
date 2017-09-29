#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

typedef long long ll;

ll dp[1000100];

ll N;

int main(){
	memset(dp,0x3f3f3f,sizeof(dp));
    dp[1] = 1;
	for(int i=1;i<1e6+9;++i){
        dp[i+1] = min(dp[i+1], dp[i]+1);
		for(int j=1;j<=i && i*j<1e6+9;++j){
			dp[i*j] = min(dp[i*j], dp[i]+dp[j]);
		}
	}
	while(scanf("%d", &N) != EOF){
		printf("%lld\n", dp[N]);
	}
	return 0;
}


