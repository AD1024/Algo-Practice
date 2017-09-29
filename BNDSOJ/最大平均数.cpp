#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
struct Node{
	int lson,rson;
	double sum;
	double avg;
};

#define lson(x) x<<1
#define rson(x) x<<1|1
#define Mid(x,y) (x+y)>>1
#define fa(x) x>>1
#define l(x) Tree[x].lson
#define r(x) Tree[x].rson
#define Sum(x) Tree[x].sum
#define Avg(x) Tree[x].avg

Node Tree[101000<<1];

double A[101000];

inline void Maintain(int x){
	Sum(x) = Sum(lson(x)) + Sum(rson(x));
	Avg(x) = Sum(x) / (double)(r(x)-l(x)+1);
	Avg(x) = max(Avg(lson(x)),Avg(rson(x)));
}

inline void Build(int x,int lt,int rt){
	l(x) = lt;
	r(x) = rt;
	if(lt == rt){
		Sum(x) = A[lt];
		Avg(x) = A[lt];
		return;
	}
	int mid = Mid(lt,rt);
	Build(lson(x),lt,mid);
	Build(rson(x),mid+1,rt);
	Maintain(x);
}*/

double pre[101000];
double a[101000];
int l,r;
int main(){
	int N;
	cin>>N;
	cin>>l>>r;
	pre[0] = 0.0;
	for(int i=1;i<=N;++i){
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}
	double ans = -10e9;
	for(int i=l;i<=r;++i){
		for(int s=1,e=i;e<=N;++e,++s){
			// cout<<s<<" "<<e<<endl;
			ans = max(ans, (pre[e]-pre[s]+a[s])/(double)(e-s+1));
			// cout<<pre[e]-pre[s]+a[s]<<endl;
		}
	}
	printf("%.2f\n",ans);
	return 0;
}