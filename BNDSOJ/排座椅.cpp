#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int x,y,l,r;
int M,N,K,L,D;
int co,ro;

struct line{
	int tot;
	int id;
	void init(int x){
		tot=0;
		id=x;
	}
};

line col[1001];
line row[1001];

bool cmp(line a,line b){
	if(a.tot!=b.tot) return a.tot>b.tot;
	else return a.id<b.id;
}

bool cmp1(line a,line b){
	return a.id<b.id;
}

int main(){
	cin>>M>>N>>K>>L>>D;
	for(int i=1;i<=M;++i){
		row[i].init(i);
	}
	for(int i=1;i<=N;++i) col[i].init(i);
	for(int i=0;i<D;++i){
		cin>>x>>y>>l>>r;
		if(x==l){
			col[min(y,r)].tot++;
		}else{
			row[min(x,l)].tot++;
		}
	}
	sort(row+1,row+N+1,cmp);
	sort(col+1,col+N+1,cmp);
	//sort(row+1,row+K+1,cmp1);
	//sort(col+1,col+L+1,cmp1);
	for(int i=1;i<K;++i){
		cout<<row[i].id<<" ";
	}
	cout<<row[K].id<<"\n";
	for(int i=1;i<L;++i){
		cout<<col[i].id<<" ";
	}
	cout<<col[L].id;
	return 0;
}