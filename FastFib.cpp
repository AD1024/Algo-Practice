#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const long long MOD = 1000000007;
typedef long long ll;
ll a[2][2]={{1,0},
			{0,1}};

ll s[2][2]={{1,1},
			{1,0}};

ll tmp[2][2]={0};

inline void copya(){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			a[i][j]=tmp[i][j];
		}
	}
}

inline void copys(){
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			s[i][j]=tmp[i][j];
		}
	}
}

inline void FastPow(int p){
	while(p){
		if(p&1){
			memset(tmp,0,sizeof(tmp));
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					for(int k=0;k<2;++k){
						tmp[i][j]+=((a[i][k]%MOD) * (s[k][j]%MOD))%MOD;
					}
				}
			}
			copya();
		}
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				for(int k=0;k<2;++k){
					tmp[i][j]+=((s[i][k]%MOD)*(s[k][j]%MOD))%MOD;
				}
			}
		}
		copys();
		p>>=1;
	}
}

int main(){
	int fib[2][2]={{1,1},
				   {0,0}};
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int P;cin>>P;
	FastPow(P-1);
	memset(tmp,0,sizeof(tmp));
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				tmp[i][j]+=((fib[i][k]%MOD)*(a[k][j]%MOD))%MOD;
			}
		}
	}
	cout<<tmp[0][1];
	return 0;
}