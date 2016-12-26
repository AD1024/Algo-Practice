#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a,string b){
	return a+b>b+a;
}

vector<string> v;

int main(){
	int N;cin>>N;
	while(N--){
		string a;cin>>a;v.push_back(a);
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();++i){
		cout<<v[i];
	}
	return 0;
}