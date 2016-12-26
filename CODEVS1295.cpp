#include <iostream>
#include <cstdio>
#include <cstring>
#define mset(n,m) memset(n,m,sizeof(n))
#define FF false
#define TT true
using namespace std;

const int MAXN = 10001;

bool visx[MAXN],visy[MAXN],y[MAXN];
int cnt;
int n;
int tot;

inline void init(){
	mset(visx,FF);
	mset(visy,FF);
	mset(y,FF);
	cnt=0;
	scanf("%d",&n);
	tot=0;
}

void Find(int tt){
	if(tt>n){
		tot++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!(y[i] || visx[i+tt] || visy[tt-i+n])){
			y[i]=visx[i+tt]=visy[tt-i+n]=TT;
			Find(tt+1);
			y[i]=visx[i+tt]=visy[tt-i+n]=FF;
		}
	}
}

int main(){
	init();
	Find(1);
	cout<<tot;
	return 0;
}
