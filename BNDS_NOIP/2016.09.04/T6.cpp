#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool used[1001];
int a[1001];
int ans=0;
int N,K;
void f(int idx){
	if(idx>K){
		ans++;
	}else{
		for(int i=1;i<=N;++i){
			if(!used[i]){
				used[i]=true;
				a[idx]=i;
				f(idx+1);
				used[i]=false;
			}
		}
	}
}

int main(){
	cin>>N>>K;
	f(1);
	cout<<ans;
	return 0;
}