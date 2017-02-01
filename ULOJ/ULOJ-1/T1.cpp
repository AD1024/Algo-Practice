#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string x;

int ans = 0;

bool idx[200];

int main(){
	idx['O'] = idx['U'] = idx['Y'] = idx['E'] = idx['A'] = idx['I'] = 1;
	cin>>x;
	x = x + 'A';
	int cnt = 1;
	for(int i=0;i<x.length();++i){
		if(idx[x[i]]){
			ans = max(ans,cnt);
			cnt = 0;
		}
		++cnt;
	}
	cout<<ans;
	return 0;
}
