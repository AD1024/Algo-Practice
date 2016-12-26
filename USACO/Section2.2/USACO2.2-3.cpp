/*
ID: ccodera1
LANG: C++
TASK: runround
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

bool in[100];
int N;
inline void reset(){
	memset(in,false,sizeof(in));
}

int num[100];

inline bool ok(int x){
	reset();
	int t = x;
	int cur=0;
	int cnt = 0;
	if(x<10) return true;
	if(((x%10) & 1) && (((x/10)%10) & 1) && x>=10 && x<=99) return true;
	while(x){
		x/=10;++cur;
	}
	for(int i=cur;i>=1;--i){
		num[i] = t%10;
		t/=10;
		if(in[num[i]] || !num[i]) return false;
		else in[num[i]] =  true;
	}
	int i=1;
	reset();
	while(cnt<cur){
		if(!in[i]){
			in[i] = true;
		}else return false;
		++cnt;i=(i+num[i])%cur;
		if(i == 0){
			i = cur;
		}
	}
	return i==1;
}

int main(){
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	cin>>N;
	++N;
	while(!ok(N)) N++;
	cout<<N<<endl;
	return 0;
}