#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map<string,bool> idx;
string str;
int ans=0;

int main(){
	int N;
	cin>>N;
	while(N--){
		cin>>str;
		sort(str.begin(),str.end());
		if(!idx[str]){
			ans++;
			idx[str]=true;
		}
	}
	cout<<ans;
	return 0;
}