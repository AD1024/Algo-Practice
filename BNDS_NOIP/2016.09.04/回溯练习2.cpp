#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

inline bool prime(int x){
	if(x==2) return true;
	if(x==1) return false;
	if(!(x&1)) return false;
	for(int i=2;i<=sqrt(x);++i){
		if(!(x%i)) return false;
	}
	return true;
}
int ans=0;
bool used[10001];
int N;
int a[10001];
void f(int idx){
	if(idx>N){
		ans++;
	}else{
		for(int i=1;i<=N;++i){
			if(!used[i]){
				if(prime(i+a[idx-1]) || idx==1){
					used[i]=true;
					a[idx]=i;
					f(idx+1);
					used[i]=false;
				}
			}
		}
	}
}

int main(){
	cin>>N;
	f(1);
	cout<<ans;
	return 0;
}