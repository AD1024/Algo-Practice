#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;

int a[110];

int N;

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	if(N == 1){
		puts("0");return 0;
	}
	sort(a+1,a+1+N);
	int maxn = a[N];
	int ans = 0;
	for(int i=1;i<N;++i){
		ans += maxn - a[i];
	}
	cout<<ans;
	return 0;
}