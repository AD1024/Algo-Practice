#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;


map<int,int> idx;

int N;

inline void parse(double x,int t){
	for(int i=1;i<=t;++i){
		idx[floor(i*x)]+=1;
	}
}

int main(){
	ios::sync_with_stdio(false);
	double x;
	int bi;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>x>>bi;
		parse(x,bi);
	}
	map<int,int>::iterator iter = idx.begin();
	while(iter != idx.end()){
		if(iter->second&1){
			cout<<iter->first;
			break;
		}
		++iter;
	}
	return 0;
}