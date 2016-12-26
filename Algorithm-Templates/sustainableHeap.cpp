#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int heap[1001000];

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

struct Heap{
	int size;
	Heap(){
		size=0;
	}

	void pushDown(int i){
		int l,r,k;
		while(lson(i)<=size){
			l=lson(i),r=rson(i),k=i;
			if(heap[k]>heap[l]){
				k=l;
			}
			if(r<=size && heap[k]>heap[r]){
				k=r;
			}
			if(k!=i){
				swap(heap[k],heap[i]);
				i=k;
			}else break;
		}
	}

	void pushUp(int i){
		while(fa(i)>=1){
			if(heap[fa(i)]>heap[i]){
				swap(heap[i],heap[fa(i)]);
				i=fa(i);
			}else break;
		}
	}

	void pop(){
		heap[1]=heap[size--];
		pushDown(1);
	}
	int top(){
		return heap[1];
	}
	void insert(int x){
		heap[++size]=x;
		pushUp(size);
	}
};

inline int read(){
	int a=0;
	char ch = getchar();bool flag = false;
	while(ch>'9' || ch<'0' || ch=='-'){
		if(ch=='-') flag=true;
		ch = getchar();
	}
	while(ch>='0' && ch <= '9'){
		a = a*10+ch-'0';
		ch=getchar();
	}
	if(flag) a=-a; 
	return a;
}

int main(){
	Heap h;
	int N;N=read();int k;
	for(int i=1;i<=N;++i){
		k=read();
		h.insert(k);
	}
	while(h.size!=0){
		printf("%d ",h.top());h.pop();
	}
	return 0;
}