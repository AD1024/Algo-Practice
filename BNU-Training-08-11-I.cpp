#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
double a[210][210],b[210][210],w[210][210];
double t;
int N;
#define REP(i,x) for(int i=0;i<x;++i) 
int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
			if(i==j){
				b[i][j]=a[i][j];
			}else{
				t=(a[i][j]+a[j][i])/2;
				b[i][j]=b[j][i]=t;
				w[i][j]=a[i][j]-t;
				w[j][i]=(-w[i][j]);
			}
		}
	}
	REP(i,N){
		REP(j,N){
			if(!j){
				printf("%.8f",b[i][j]);
			}else{
				printf(" %.8f",b[i][j]);
			}
		}
		puts("");
	}
	REP(i,N){
		REP(j,N){
			if(!j){
				printf("%.8f",w[i][j]);
			}else{
				printf(" %.8f",w[i][j]);
			}
		}
		puts("");
	}
	return 0;
}