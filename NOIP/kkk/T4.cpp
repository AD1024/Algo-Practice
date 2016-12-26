#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int phi[500010];
int N;

inline void get_phi(){
	memset(phi,0,sizeof(phi));
	for(int i=2;i<500001;++i){
		if(!phi[i]){
			for(int j=i;j<500001;j+=i){
				if(!phi[j]) phi[j]=j;
				phi[j]-=phi[j]/i;
			}
		}
	}
}
int sum[500010];

int main(){
	get_phi();
	for(int i=2;i<=500000;++i){
		sum[i]=sum[i-1]+phi[i];
	}
	while(~scanf("%d",&N)){
		printf("%d\n",sum[N]*2+1);
	}
	return 0;
}