#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define fa(x) x >> 1
#define lson(x) x << 1
#define rson(x) x << 1 | 1

int heap[101000];
int size;

struct Heap{
	void push_up(int i){
		while(fa(i) >= 1) {
			if(heap[i] < heap[fa(i)]){
				swap(heap[i], heap[fa(i)]);
				i = fa(i);
			}else break;
		}
	}
	void push_down(int i){
		int l,r,k;
		while(lson(i) <= size){
			k = i;l = lson(i);r = rson(i);
			if(heap[l] < heap[k]) k = l;
			if(r <= size && heap[r] < heap[k]) k = r;
			if(k != i){
				swap(heap[i], heap[k]);
				i = k;
			}else break;
		}
	}
	int len(){
		return size;
	}
	int top(){
		return heap[1];
	}
	bool empty(){
		return size <= 0;
	}
	void insert(int x){
		heap[++size] = x;
		push_up(size);
	}
	void pop(){
		heap[1] = heap[size--];
		push_down(1);
	}
};

int main(){
	Heap h = Heap();
	
}
