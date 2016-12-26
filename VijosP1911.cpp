#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int cnt=0,N;
int a[110];
map<int,bool> m;
int main(){
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i!=j){
				m[a[i]+a[j]]=true;
			}
		}
	}
	for(int i=1;i<=N;++i){
		if(m[a[i]]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}