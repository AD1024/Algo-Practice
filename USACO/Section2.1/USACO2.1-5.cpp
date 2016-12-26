/*
ID: ccodera1
LANG: C++
TASK: hamming
*/
#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

#define ull unsigned long long

vector< bitset<8> > ans;

bool vis[1024];

int N,B,D;

void dfs(int idx){
	if(idx > N){
		for(int i=0;i<ans.size()-1;++i){
			cout<<ans[i].to_ulong();
			if((i+1)%10 == 0){
				puts("");
			}else putchar(' ');
		}
		cout<<ans[ans.size()-1].to_ulong();puts("");
		exit(0);
	}else{
		for(int i=0;i<=1<<(B+1);++i){
			if(!vis[i]){
				vis[i] = true;
				bitset<8> add((ull)i);
				for(int j=0;j<ans.size();++j){
					bitset<8> k = add ^ ans[j];
					if(k.count()<D){
						vis[i] = false;
						break;
					}
				}
				if(!vis[i]) continue;
				else {
					ans.push_back(add);
					dfs(idx+1);
				}
				ans.pop_back();
				vis[i] = false;
			}
		}
	}
}

int main(){
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
	cin>>N>>B>>D;
	dfs(1);
	return 0;
}