#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int a[10100];
int N;int type;

#define rep(i,x) for(int i=1;i<=x;++i)

inline void P7(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1] || a[i] == a[i+1]-2) ++ans;
		if(i<=N-2){
			if(a[i+1] == a[i] && a[i+1] == a[i+2]) ++ans;
			if(a[i] == a[i+1] && a[i]-1 == a[i+2]) ++ans;
		}
	}
	cout<<ans;
	exit(0);
}

inline void P6(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1] || a[i] == a[i+1]+2) ++ans;
		if(i<=N-2){
			if(a[i+1] == a[i] && a[i+1] == a[i+2]) ++ans;
			if(a[i+1] == a[i+2] && a[i]+1 == a[i+1]) ++ans;
		}
	}
	cout<<ans;
	exit(0);
}

inline void P5(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1]-1 || a[i] == a[i+1]+1) ++ans;
		if(i<=N-2){
			if(a[i+1] == a[i] && a[i+1] == a[i+2]) ++ans;
			if(a[i] == a[i+2] && a[i+1] == a[i+2]-1) ++ans;
		}
	}
	cout<<ans;
	exit(0);
}

inline void P4(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1]-1) ++ans;
		if(i<=N-2){
			if(a[i+1] == a[i]-1 and a[i+1] == a[i+2]){
				ans++;
			}
		}
	}
	cout<<ans;
	exit(0);
}

inline void P3(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1]+1) ++ans;
		if(i<=N-2){
			if(a[i] == a[i+1] and a[i+2] == a[i+1]+1){
				++ans;
			}
		}
	}
	cout<<ans;
	exit(0);
}

inline void P2(){
	int ans = 0;
	rep(i,N-1){
		if(a[i] == a[i+1]) ans++;
	}
	cout<<ans;
	exit(0);
}

inline void P1(){
	int ans = N;
	for(int i=1;i<=N-3;++i){
		if(a[i] == a[i+1] && a[i+1]==a[i+2] && a[i+2] == a[i+3]){
			ans++;
		}
	}
	cout<<ans;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin>>N>>type;
	for(int i=1;i<=N;++i) cin>>a[i];
	switch(type){
		case 1:{
			P1();
			break;
		}
		case 2:{
			P2();
			break;
		}
		case 3:{
			P3();break;
		}
		case 4:{
			P4();break;
		}
		case 5:{
			P5();break;
		}
		case 6:{
			P6();break;
		}
		case 7:{
			P7();break;
		}
	}
	return 0;
}