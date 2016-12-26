#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

bool vis[30010];
vector<int> v;

int main(){
	int x;
	int N;
	int K;
	cin>>N>>K;
	for(int i=0;i<N;++i){
		cin>>x;
		if(!vis[x]){
			vis[x]=true;
			v.push_back(x);
		}
	}
	if(v.size()<K){
		puts("NO RESULT");
		return 0;
	}
	sort(v.begin(),v.end());
	cout<<v[K-1];
	return 0;
}