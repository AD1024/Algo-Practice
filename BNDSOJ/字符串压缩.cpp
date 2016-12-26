#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define MP(x,y) make_pair(x,y)
#define fi first
#define se second
vector< pair<char,int> > v;

char str[257];

int main(){
	cin>>str;
	int cnt=0;
	for(int i=0;i<strlen(str);){
		char c=str[i];
		cnt=0;
		while(str[i]==c){
			++i;
			++cnt;
		}
		v.push_back(MP(c,cnt));
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i].fi;
		if(v[i].se!=1) cout<<v[i].se;
	}
	return 0;
}