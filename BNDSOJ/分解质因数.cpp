#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

inline bool ok(int x){
	if(x==1) return false;
	if(x==2) return true;
	if(!(x&1)) return false;
	for(int i=2;i<=sqrt(x);++i){
		if(!(x%i)) return false;
	}
	return true;
}

int main(){
	vector<int> v;
	int N;cin>>N;
	cout<<N<<"=";
	if(ok(N)){
		cout<<N;
	}else{
		while(N!=1){
			for(int i=2;i<=N;++i){
				if(ok(i) && !(N%i)){
					v.push_back(i);
					N/=i;break;
				}
			}
		}
		for(int i=0;i<v.size()-1;++i){
			cout<<v[i]<<"*";
		}
		cout<<v[v.size()-1];
	}
	return 0;
}