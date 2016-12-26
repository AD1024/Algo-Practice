#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int N;

vector<int> v;

int main(){
	cin>>N;
	int cur=1;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			int a;cin>>a;
			if(j==cur){
				++cur;
				v.push_back(a);
			}
		}
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<" ";
	}
	return 0;
}