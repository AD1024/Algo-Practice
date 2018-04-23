#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

#define pb(x) push_back(x)
#define INF 0x3f3f3f

vector<int> ans;
int cnt = INF;

int main(){
	ios::sync_with_stdio(false);
	string s,t;
	int sl,tl;
	cin>>sl>>tl;
	cin>>s>>t;
	vector<int> p;
	int c;
	for(int i=0;i+sl<=tl;++i){
		c = 0;
		p.clear();
		for(int j=0;j<sl;++j){
			if(s[j] != t[i+j]){
				c += 1;
				p.pb(j);
			}
		}
		if(c < cnt){
			ans = p;
			cnt = c;
		}
	}
	cout<<cnt<<'\n';
	for(auto i: ans)
		cout<<i+1<<' ';
	return 0;
}
