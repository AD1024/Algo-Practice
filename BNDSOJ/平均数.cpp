#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define eps 10e-8

double avg;
double score[1010];
double sum;
int main(){
	for(int i=1;i<=20;++i){
		scanf("%lf",&score[i]);
		sum+=score[i];
	}
	avg=sum/20.0;
	int ans=0;
	for(int i=1;i<=20;++i){
		if(avg-score[i]>eps){
			ans++;
		}
	}
	printf("%.2lf\n%d",avg,ans);
	return 0;
}