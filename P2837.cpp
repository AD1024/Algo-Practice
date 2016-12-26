#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int L,D,X;
int N;
int M;

inline bool judge(int x){
	int sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return sum==X;
}

int main(){
	cin>>L>>D>>X;
	int j=D;
	int i=L;
	while(i<=D && j>=L){
		if(judge(i)){
			M=i;
		}
		if(judge(j)){
			N=j;
		}
		++i,--j;
	}
	printf("%d\n%d",N,M);
	return 0;
}