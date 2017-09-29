#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

int heap[150010<<2];

int cnt;

inline void pushUp(int i){
	while(fa(i)>=1) {
		if(heap[i]<heap[fa(i)]){
			swap(heap[i], heap[fa(i)]);
			i=fa(i);
		}else break;
	}
}

inline void pushDown(int i){
	int k,l,r;
	while(lson(i) <= cnt) {
		k=i;r=rson(i);l=lson(i);
		if(heap[l]<heap[k]) k = l;
		if(r<=cnt && heap[r] < heap[k]) k = r;
		if(k != i) {
			swap(heap[k], heap[i]);
			i=k;
		}else break;
	}
}

inline void insert(int x) {
	heap[++cnt] = x;
	pushUp(cnt);
}

inline int top(){
	return heap[1];
}

inline void pop(){
	heap[1] = heap[cnt--];
	pushDown(1);
}

inline bool empty(){
	return cnt == 0;
}

int main(){
	int N;scanf("%d", &N);int a;
	while(N--){
		scanf("%d", &a);
		insert(a);
	}
	while(!empty()){
		printf("%d ",top());
		pop();
	}
	return 0;
}