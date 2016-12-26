#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXN = (1<<20)+10;

double p[MAXN];
int N;

void RC(){
	double ans=0;
	for(int i=1;i<(1<<N);++i){
		int k=0;
		double sum=0;
		for(int j=0;j<N;++j){
			if(i & (1<<j)){
				sum+=p[j];
				++k;
			}
		}
		if(k&1){
				ans+=1.0/sum;
			}else{
				ans-=1.0/sum;
			}
	}
	printf("%.5lf\n",ans);
}

int main(){
	while(cin>>N){
		for(int i=0;i<N;++i){
			cin>>p[i];
		}
		RC();
	}
	return 0;
}