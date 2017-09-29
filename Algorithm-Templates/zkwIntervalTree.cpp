#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node{
	int Max,Min;
	int Sum;
}Tree[10010<<2];

int M,N;
#define lson(x) x<<1
#define rson(x) x<<1|1

inline void Maintain(int i){
	Tree[i].Max = max(Tree[lson(i)].Max,Tree[rson(i)].Max);
	Tree[i].Sum = Tree[lson(i)].Sum+Tree[rson(i)].Sum;
	Tree[i].Min = min(Tree[lson(i)].Min , Tree[rson(i)].Min);
}

inline void Build(){
	for(M=1;M<=N+1;M<<=1);
	for(int i=M+1;i<=M+N;++i){
		int val;cin>>val;
		Tree[i].Max=Tree[i].Min=Tree[i].Sum=val;
	}
	for(int i=M-1;i;--i){
		Maintain(i);
	}
}

inline void update(int pos,int val){
	pos+=M;
	Tree[pos].Sum+=val;Tree[pos].Max+=val;Tree[pos].Min+=val;
	for(pos>>=1;pos;pos>>=1){
		Maintain(pos);
	}
}


int main(){

}