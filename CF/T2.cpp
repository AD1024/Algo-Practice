#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> t;
vector<string> v;
int N,M;
string pass;
bool cmp(string a,string b){
	return a.length()<b.length();
}

int main(){
	cin>>N>>M;
	string k;
	for(int i=0;i<N;++i){
		cin>>k;
		t.push_back(k);
	}
	cin>>pass;
	for(int i=0;i<t.size();++i){
		if(pass!=t[i] && t[i].length()<=pass.length()){
			v.push_back(t[i]);
		}
	}
	v.push_back(pass);
	sort(v.begin(),v.end(),cmp);
	int cur=0;
	while(pass.length()>v[cur].length()) ++cur;
	int trie=cur/M;
	int best=trie*5+cur+1;
	int fail=(v.size()%M?v.size()/M:v.size()/M-1);
	int worst=fail*5+v.size();
	cout<<best<<" "<<worst;
	return 0;
}