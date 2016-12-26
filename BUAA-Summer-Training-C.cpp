#include <iostream>
#include <cstdio>
using namespace std;

int N,ans=0;
typedef long long Lovelive;
int main(){
	cin>>N;
	for(int i=1;i<N;++i){
		if(!(N%i)){
			ans+=1;
		}
	}
	Lovelive k,sum;
	for(int i=2;i<=N;++i){
		k=sum=1;
		for(;;){
			if(i*k+sum>N) break;
			k*=i;
			sum+=k;
			if(!(N%sum)){
				++ans;
				//break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
