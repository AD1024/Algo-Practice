#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int a[1010];

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	int ans = 0;
	sort(a+1,a+1+N);
	for(int i=1;i<N;++i){
		for(int j = i+1;j<=N;++j){
			if(gcd(i,j) == 1){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}