#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cstring>
using namespace std;

// string pre = "1011010110110101101011011010110110";

#define ll long long

/*
string Next(string x){
	string ret = "";
	for(int i=0;i<x.length();++i){
		if(x[i] == '0'){
			ret+='1';
		}else ret += "10";
	}
	return ret;
}*/
ll pl,pr;

ll l[210];
ll f[210];
/*
ll work(ll pos,int cur){
	if(!pos) return 0;
	if(pos == l[cur]) return f[cur];
	if(pos > l[cur]) return work(pos-l[cur],cur-1) + f[cur];
	else return work(pos,cur-1);
}*/

inline ll work(ll pos){
	ll a = 0;
	if(pos == 0) return 0;
	if(pos == 1 or pos == 2) return 1;
	for(int i=92;i;--i){
		if(pos>=f[i]){
			a += l[i];
		}
		if(pos>=f[i]) pos -= f[i];
	}
	return a;
}

int main(){
	/*
	string start = "1";
	for(int i=0;i<20;++i){
		start = Next(start);
	}
	cout<<start;*/
	f[1] = f[2] = 1;
	l[1] = 0;l[2] = 1;
	for(int i=3;i<=100;++i){
		f[i] = f[i-1] + f[i-2];l[i] = l[i-1] + l[i-2];
	}
	//---------
	ios::sync_with_stdio(false);
	int Q;cin>>Q;
	while(Q--){
		cin>>pl>>pr;
		cout<<work(pr) - work(pl-1)<<endl;
	}
	
	return 0;
}