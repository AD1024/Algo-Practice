#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

typedef unsigned long long LL;

LL MOD;
LL getPhi(int x){
	int ret=x;
	int a=x;
	for(int i=2;i*i<=a;++i){
		if(a%i==0){
			ret=ret/i*(i-1);
			while(!(a%i)){
				a/=i;
				ret*=i;
			}
		}
	}
	if(a>1){
		ret*=(a-1);
	}
	return ret;
}

LL power(LL a, LL b){
	 LL ret=1;
	 while(b){
	 	if(b&1){
	 		ret=(ret*a)%MOD;
	 	}
	 	a=(a*a)%MOD;
	 	b>>=1;
	 }
	 return ret;
}

LL M;
int b,P;
LL ans;
LL list[100001];
int main(){
	int CASE;
	cin>>CASE;
	int T=0;
	while(CASE--){
		++T;
		ans=0;
		cin>>b>>P>>M;
		MOD=P;
		if(P==1){
			if(M==18446744073709551615){
				cout<<"Case #"<<T<<": "<<"18446744073709551616"<<"\n";
			}else{
				cout<<"Case #"<<T<<": "<<M+1<<"\n";
			}
			continue;
		}
		LL i,phi,fact;
		phi=getPhi(P);
		fact=1;
		for(i=0;i<=M && fact<=phi;++i){
			if(power(i,fact)==b){
				ans+=1;
			}
			fact*=(i+1);
			fact%=phi;
		}
		fact%=phi;
		while(i<=M&&fact){
			if(power(i,fact+phi)==b){
				ans+=1;
			}
			fact*=(i+1);
			fact%=phi;
			++i;
		}
		if(i<=M){
			LL k=0;
			for(int j=0;j<P;++j){
				list[j]=power(i+j,phi);
				if(list[j]==b){
					++k;
				}
			}
			LL tms = (M-i+1)/P;
			ans+=k*tms;
			LL loop=(M-i+1)%P;
			for(int j=0;j<loop;++j){
				if(list[j]==b){
					ans++;
				}
			}
		}
		cout<<"Case #"<<T<<": "<<ans<<"\n";
	}
	return 0;
}
