#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define ll long long

int Next[1000100];
int t[1000100];
int s[1000100];

ll N,M;

inline ll read(){
	char ch = getchar();
	ll a = 0;bool flag = false;
	while(ch>'9' || ch<'0' || ch == '-'){
		if(ch == '-') flag = true;
		ch = getchar();
	}
	while(ch>='0' && ch<='9'){
		a = a * 10 + ch - '0';
		ch = getchar();
	}
	return flag?-a:a;
}

inline void getNext(){
	Next[1] = 0;
	int j = 0;
	for(int i=2;i<=M;++i){
		while(j != 0 && s[j+1] != s[i]){
			j = Next[j];
		}
		if(s[j+1] == s[i]) ++j;
		Next[i] = j;
	}
}

inline void KMP(){
	int ans1,ans2;
	int j = 0;
	bool f = false;
	for(ll i=1;i<=N;++i){
		while(j != 0 && t[i] != s[j+1]){
			j = Next[j];
		}
		if(t[i] == s[j+1]){
			++j;
		}
		if(j == M){
			printf("%lld ",i-M+1);
			j = Next[j];
			if(!f){
				ans1 = i-M+1;
				f = true;
			}
			ans2 = i;
		}
	}
	if(!f){
		puts("Orz yulemao");
	}else{
		puts("");
		printf("%d %d",ans1,ans2);
	}
}

int main(){
	N = read(); M = read();
	for(int i=1;i<=N;++i){
		t[i] = read();
	}
	for(int i=1;i<=M;++i){
		s[i] = read();
	}
	getNext();
	KMP();
	return 0;
}