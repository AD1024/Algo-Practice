/*
ID: ccodera1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

inline void file(){
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
}

int a[3],b[3];
bool vis[101][101][101];
int N;
int ans;

#define ABS(x) x>0?x:-x

inline bool ok(int l,int r){
	return abs(l-r)<=2 || abs(l-r)>=N-2;
}

int main(){
	file();
	cin>>N;
	cin>>a[0]>>a[1]>>a[2];
	cin>>b[0]>>b[1]>>b[2];
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			for(int k=1;k<=N;++k){
				if((ok(a[0],i) && ok(a[1],j) && ok(a[2],k)) || (ok(b[0],i) && ok(b[1],j) && ok(b[2],k))){
					if(!vis[i][j][k]){
						ans++;
						vis[i][j][k]=true;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}