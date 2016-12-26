#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define MAXN 8001000

typedef long long ll;
ll heap[MAXN];
int M,N,Q,V,T,U;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

struct Heap{
	int size;
	Heap(){
		size=0;
	}

	void pushUp(int i){
		while(fa(i)>=1){
			if(heap[fa(i)]<heap[i]){
				swap(heap[fa(i)],heap[i]);
				i=fa(i);
			}else break;
		}
	}

	void pushDown(int i){
		int l,r,k;
		while(lson(i)<=size){
			l=lson(i);r=rson(i);k=i;
			if(heap[l]>heap[k]){
				k=l;
			}
			if(r<=size && heap[r]>heap[k]){
				k=r;
			}
			if(k!=i){
				swap(heap[k],heap[i]);
				i=k;
			}else break;
		}
	}

	ll top(){
		return heap[1];
	}
	void pop(){
		heap[1]=heap[size--];
		pushDown(1);
	}

	void insert(int x){
		heap[++size]=x;
		pushUp(size);
	}
}H;
int main(){
	cin>>N>>M>>Q>>U>>V>>T;
	ll t;
	for(int i=1;i<=N;++i){
		scanf("%lld",&t);
		H.insert(t);
	}
	ll l,r;int cur=0;
	ll delta=0;
	while(M--){
		++cur;
		t=H.top();H.pop();
		t+=delta;
		if(cur%T==0){
			printf("%lld ",t);
		}
		l=U*t/V;
		r=t-l;
		delta+=Q;
		H.insert(l-delta);H.insert(r-delta);
	}
	putchar('\n');
	cur=0;
	while(H.size){
		++cur;
		if(cur%T==0) printf("%lld ",H.top()+delta);
		H.pop();
	}
	return 0;
}