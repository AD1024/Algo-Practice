#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define Y "YES"
#define N "NO"
#define nl '\n'

char str[10001];
int K;
bool vis[110];
int main(){
	cin>>K;
	cin>>str;
	int len=strlen(str);
	int cnt=0;
	for(int i=0;i<len;++i){
		if(!vis[str[i]-'a']){
			vis[str[i]-'a']=true;
			cnt++;
		}
	}
	memset(vis,false,sizeof(vis));
	if(cnt>=K){
		cout<<Y;
		int cur=0;
		int z=0;
		for(int i=0;i<len;++i){
			if(!vis[str[i]-'a'] && z<K){
				cout<<nl;
				vis[str[i]-'a']=true;
				z++;
			}
			cout<<str[i];
		}
	}else
		puts(N);
	return 0;
}