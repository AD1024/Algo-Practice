#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1
#define mid(x,y) x + y >>1

struct Node{
	int lson,rson,Min,Max,Sum;
	int add;
};

Node Tree[10100<<2];

int A[101000<<2];

inline void Maintain(int rt){
	int l = lson(rt);
	int r = rson(rt);
	Tree[rt].Max = max(Tree[l].Max, Tree[r].Max);
	Tree[rt].Min = min(Tree[l].Min, Tree[r].Min);
	Tree[rt].Sum = Tree[l].Sum + Tree[r].Sum;
	return;
}

void BuildTree(int rt, int l,int r){
	Tree[rt].lson = l;
	Tree[rt].rson = r;
	if(l == r){
		Tree[rt].Min = Tree[rt].Max = Tree[rt].Sum = A[l];
	}else{
		int Mid = mid(l,r);
		BuildTree(lson(rt),l,mid);
		BuildTree(rson(rt),mid+1,r);
		Maintain(rt);
	}
}

void pushDown(int rt){
	if(Tree[rt].add){
		int l = lson(rt);
		int r = rson(rt);
		Tree[l].Min += Tree[rt].add;
		Tree[r].Min += Tree[rt].add;
		Tree[l].Max += Tree[rt].add;
		Tree[r].Max+= Tree[rt].add;
		Tree[l].Sum += Tree[rt].add * (Tree[l].rson-Tree[l].lson+1);
		Tree[r].Sum += Tree[rt].add * (Tree[r].rson-Tree[r].lson+1);
		Tree[rt].add = 0;
	}
}

void PointUpdate(int rt,int pos,int v,bool add){
	if(Tree[rt].l == pos && Tree[rt].rson == pos){
		if(add){
			Tree[rt].Sum += v;
			Tree[rt].Min += v;
			Tree[rt].Max += v;
		}else{
			Tree[rt].Sum = v;
			Tree[rt].Min = v;
			Tree[rt].Max = v;
		}
		return;
	}else{
		int Mid = mid(Tree[rt].lson,Tree[rt].rson);
		if(pos<mid){
			PointUpdate(lson(rt),pos,v);
		}else{
			PointUpdate(rson(rt),pos,v);
		}
		Maintain(rt);
	}
}

void segmentUpdate(int rt,int l,int r,int v){
	if(Tree[rt].l>r || Tree[rt].r<l){
		return;
	}
	if(Tree[rt].l <= l && Tree[rt].r <= r){
		Tree[rt].add = v;;
		Tree[rt].Max += v;
		Tree[rt].Min += v;
		Tree[rt].Sum += v * (Tree[rt].r-Tree[rt].l+1);
	}
	pushDown(rt);
	segmentUpdate(lson(rt),l,r,v);
	segmentUpdate(rson(rt),l,r,v);
	Maintain(rt);
}

int main(){

}