#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int N,M;
double k[10010];
double slp = 0.00;

int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>k[i];
	}
	int ans = 0;
	for(int i=M+1;i<=N;++i){
		if(k[i] - k[M] / ((i-M)*40.0) >= slp){
			slp = k[i] - k[M] / ((i-M)*40.0);++ans;
		}
	}
	slp = 0.0;
	for(int i=M-1;i;--i){
		if(k[i] - k[M] / ((M-i)*40.0) >= slp){
			slp = k[i] - k[M] / ((M-i)*40.0);++ans;
		}
	}
	cout<<ans;
	return 0;
}