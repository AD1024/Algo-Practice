/*
ID: ccodera1
LANG: C++
TASK: lamps
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int a[110];

vector<string> v;

int C,N;
bool found;
int on[110];int oncur;
int off[110],offcur;
map<string,bool> vis;

inline bool ok(){
	for(int i=0;i<oncur;++i){
		if(a[on[i]] == 0) return false;
	}
	for(int i=0;i<offcur;++i){
		if(a[off[i]] == 1) return false;
	}
	return true;
}

inline void alter(int s,int x){
	for(int i=s;i<=N;i+=x){
		a[i] ^= 1;
	}
}

void dfs(int idx){
	if(idx == C){
		if(ok()){
			found = true;
			string ret = "";
			for(int i=1;i<=N;++i){
				ret += char(a[i]+'0');
			}
			if(!vis[ret]){
				v.push_back(ret);
				vis[ret] = true;
			}
		}
	}else{
		for(int i=1;i<=4;++i){
			if(i == 1){
				alter(1,1);
				dfs(idx+1);
				alter(1,1);
			}else if(i == 2){
				alter(1,2);
				dfs(idx+1);
				alter(1,2);
			}else if(i == 3){
				alter(2,2);
				dfs(idx+1);
				alter(2,2);
			}else if(i == 4){
				alter(1,3);
				dfs(idx+1);
				alter(1,3);
			}
		}
	}
}

int main(){
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	cin>>N>>C;
	int t;
	while(cin>>t){
		if(t == -1) break;
		else on[oncur++] = t;
	}
	while(cin>>t){
		if(t == -1) break;
		else off[offcur++] = t;
	}
	if(C > 4){
		C %= 2;
		if(C == 1){
			C = 3;
		}else C = 4;
	}
	for(int i=1;i<=N;++i) a[i] = 1;
	dfs(0);
	if(!found){
		puts("IMPOSSIBLE");
		return 0;
	}
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		cout<<v[i]<<endl;
	}
	return 0;
}