#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
using namespace std;

#define ll unsigned long long

ll g[510][510];

int px,py;
ll sum1,sum2,sum3,sum4;
int f;bool h=false;

inline void out(ll ans){
	if(!ans){
		puts("-1");
	}else{
		cout<<ans;
	}
}

int main(){
	int N;cin>>N;
	if(N == 1){puts("1");return 0;}
	for(int i=1;i<=N;++i){
		bool kk = h;
		for(int j=1;j<=N;++j){
			cin>>g[i][j];
			if(!g[i][j]){
				px = i;
				py = j;
				kk = true;
			}
		}
		if(!kk){
			h=true;
			for(int j=1;j<=N;++j){
				sum1 += g[i][j];
			}
		}
	}
	if(px == py && N-px == py){
		f = 3;
	}else{
		if(px == py) f=1;
		else if(N-px+1 == py) f=2;
		else f=0;
	}
	int s = py+1>N?py-1:py+1;
	for(int i=1;i<=N;++i){
		sum2 += g[i][s];
	}
	if(sum1 != sum2){
		puts("-1");return 0;
	}
	if(!f){
		// puts("OK1");
		ll d1 = 0;
		ll d2=d1;
		for(int i=1;i<=N;++i){
			d1 += g[i][i];
			d2 += g[i][N-i+1];
		}
		if(d1 != sum1 || d2 != d1){
			puts("-1");return 0;
		}
		ll k = 0,l = 0;
		for(int i=1;i<=N;++i){
			k += g[i][py];
			l += g[px][i];
		}
		if(k!=l){
			puts("-1");return 0;
		}
		ll diff = sum1 - k;
		out(diff);return 0;
	}else{
		// puts("OK2");
		ll k,l;
		k = l = 0;
		if(f == 3){
			for(int i=1;i<=N;++i){
				k += g[i][py];
				l += g[px][i];
			}
			if(k != l){
				// puts("OK3");
				puts("-1");return 0;
			}
			ll d1 = 0;
			ll d2=d1;
			for(int i=1;i<=N;++i){
				d1 += g[i][i];
				d2 += g[i][N-i+1];
			}
			if(k != d1 || d1!=d2){
				// puts("OK4");
				puts("-1");return 0;
			}
			out(sum1-k);return 0;
		}else if(f == 1){
			for(int i=1;i<=N;++i){
				k += g[i][py];
				l += g[px][i];
			}
			if(k != l){
				// puts("OK5");
				puts("-1");return 0;
			}
			ll d1 = 0;
			for(int i=1;i<=N;++i){
				d1 += g[i][i];
			}
			if(k != d1){
				// puts("OK6");
				puts("-1");return 0;
			}
			out(sum1-k);
		}else{
			for(int i=1;i<=N;++i){
				k += g[i][py];
				l += g[px][i];
			}
			if(k != l){
				// puts("OK7");
				puts("-1");return 0;
			}
			ll d1 = 0;
			for(int i=1;i<=N;++i){
				d1 += g[i][N-i+1];
			}
			if(d1 != k){
				// puts("OK8");
				puts("-1");return 0;
			}
			out(sum1-k);return 0;
		}
	}
	return 0;
}