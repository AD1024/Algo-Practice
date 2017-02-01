/*
ID: ccodera1
LANG: C++
TASK: prefix
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

string a[10100];
bool dp[201000];
string S;

int cur;

int main(){
	freopen("prefix.in","r",stdin);
	freopen("prefix.out","w",stdout);
	string s;
	while(cin>>s){
		if(s == ".") break;
		a[++cur] = s;
	}
	while(cin>>s){
		S += s;
	}
	dp[0] = true;
	S = ' '+S;
	for(int i=1;i<S.size();++i){
		for(int j=1;j<=cur;++j){
			if(i>=a[j].length() && dp[i-a[j].length()]){
				if(S.substr(i-a[j].length()+1,a[j].length()) == a[j]){
					dp[i] = true;
				}
			}
		}
	}
	for(int i=S.length();i>=0;--i){
		if(dp[i]){
			printf("%d\n",i);
			return 0;
		}
	}
}