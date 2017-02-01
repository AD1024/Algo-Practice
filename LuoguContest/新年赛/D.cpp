#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N,M;

struct Line{
	int l,r;
};
Line l[5010];

int pos[10000010];

bool cmp(Line a,Line b){
	return a.l<b.l;
}

inline int read(){
	int a = 0;
	ch = getchar();
	while(!isdigit(ch)){
		ch = getchar();
	}
	while(isdigit(ch)){
		a = a*10+ch-'0';ch = getchar();
	}
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	N=read();M=read();
	for(int i=1;i<=N;++i){
		l[i].l = read();
		l[i].r = read();
	}
	int p,t;
	for(int i=1;i<=M;++i){
		p = read();t=read();
		pos[p] = min(pos[p],t);
	}
	sort(l+1,l+N+1,cmp);
	
	return 0;
}