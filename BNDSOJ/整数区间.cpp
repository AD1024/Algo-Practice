#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

struct P{
	int beg,end;
	void init(){
		scanf("%d%d", &beg, &end);
	}
};

P e[101000];
int N;

bool cmp(P a, P b){
	if(a.end != b.end) return a.end < b.end;
	return a.beg < b.beg;
}

int main(){
	int ans;
	scanf("%d", &N);
	ans = 0;
	for(int i=1;i<=N;++i) e[i].init();
	sort(e+1, e+1+N, cmp);
	int pos = -0x3f3f3f;
	for(int i=1;i<=N;++i) {
		if(pos < e[i].beg) {
			pos = e[i].end;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}