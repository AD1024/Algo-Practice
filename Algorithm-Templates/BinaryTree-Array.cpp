#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1

struct Node{
	int v;
	int l,r;
	int idx;
	Node(){
		idx=-1;
	}
}T[1001];
bool ok;
int __tot=0;
void Insert(int idx,int pos,int v){
	if(idx==-1){
		T[pos].v=v;
		T[pos].idx=pos;
		ok=true;
	}else if(T[lson(pos)].idx==-1) Insert(T[lson(pos)].idx,lson(pos),v);
	else if(T[rson(pos)].idx==-1) Insert(T[rson(pos)].idx,rson(pos),v);
	else{
		Insert(T[lson(pos)].idx,lson(pos),v);
		if(ok) return;
		Insert(T[rson(pos)].idx,rson(pos),v);
	}
}

void InOrder_Traverse(int idx,int pos){
	if(idx==-1) return;
	else{
		InOrder_Traverse(T[lson(pos)].idx,lson(pos));
		printf("%d ",T[pos].v);
		InOrder_Traverse(T[rson(pos)].idx,rson(pos));
	}
}

void PreOrder_Traverse(int idx,int pos){
	if(idx==-1) return;
	else{
		printf("%d ",T[pos].v);
		PreOrder_Traverse(T[lson(pos)].idx,lson(pos));
		PreOrder_Traverse(T[rson(pos)].idx,rson(pos));
	}
}

void PostOrder_Traverse(int idx,int pos){
	if(idx==-1) return;
	else{
		PostOrder_Traverse(T[lson(pos)].idx,lson(pos));
		PostOrder_Traverse(T[rson(pos)].idx,rson(pos));
		printf("%d ",T[pos].v);
	}
}

int main(){
	int N;
	cin>>N;
	while(N--){
		int op;cin>>op;
		switch(op){
			case 1:{
				int v;cin>>v;
				ok=false;
				Insert(T[1].idx,1,v);
				break;
			}
			case 2:{
				InOrder_Traverse(T[1].idx,1);
				putchar('\n');
				break;
			}
			case 3:{
				PreOrder_Traverse(T[1].idx,1);
				putchar('\n');
				break;
			}
			case 4:{
				PostOrder_Traverse(T[1].idx,1);
				putchar('\n');
				break;
			}
		}
	}
	return 0;
}