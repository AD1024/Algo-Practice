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
inline void Build(){
	M=1;
	while(M<N){
		M<<=1;
	}
	for(int i=M+1;i<=M+N;++i){
		int val;cin>>val;
		Tree[i].Max=Tree[i].Min=Tree[i].Sum=val;
	}
	for(int i=M-1;i;--i){
		Tree[i].Max = max(Tree[lson(i)].Max,Tree[rson(i)].Max);
		Tree[i].Sum = Tree[lson(i)].Sum+Tree[rson(i)].Sum;
		Tree[i].Min = min(Tree[lson(i)].Min , Tree[rson(i)].Min);
	}
}

inline void SinglePointUpdate(int pos,int val){
	pos+=M;
	Tree[pos].Sum+=val;Tree[pos].Max+=val;Tree[pos].Min+=val;
	while(pos){
		pos>>=1;
		Tree[pos].Max=max(Tree[lson(pos)].Max,Tree[rson(pos)].Max);
		Tree[pos].Min=min(Tree[lson(pos)].Min,Tree[rson(pos)].Min);
		Tree[pos].Sum=Tree[lson(pos)].Sum+Tree[rson(pos)].Sum;
	}
}


int main(){

}