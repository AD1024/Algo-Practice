#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define Mid(x,y) (x+y)>>1
int N;int t;
struct Node{
	int lson,rson; // Lson rson
	int ly,ry; // L pos , R pos of x aix
	int lap; // Times of Overlap
	int length; // Length of Overlap
}T[100010];
struct Line{
	bool isleft;
	int x;
	int ly,ry;
}L[100010];

int Y[100010];
void BuildTree(int k,int l,int r){
	T[k].lson=l;
	T[k].rson=r;
	T[k].lap=0;
	T[k].length=0;
	T[k].ly=Y[l];
	T[k].ry=Y[r];
	if(l+1==r) return;
	int mid=Mid(l,r);
	BuildTree(lson(k),l,mid);
	BuildTree(rson(k),mid+1,r);
}

void UpdateLength(int k){
	if(T[k].lson+1==T[k].rson){
		T[k].length=0;
	}else if(T[k].lap%2==1){
		T[k].length=T[k].ry-T[k].ly;
	}
}

void insert(int k,Line a){
	if(a.ly==T[k].ly && a.ry==T[k].ry){
		if(a.isleft){
			T[k].lap++;
		}else{
			T[k].lap--;
		}
	}
}

bool cmp(Line a,Line b){
	return a.x<b.x;
}

int main(){
	cin>>N;
	int x1,x2,y1,y2;
	for(int i=1;i<=N;++i){
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		L[t].x=x1;
		L[t].ly=y1;
		L[t].ry=y2;
		L[t].isleft=true;
		Y[t]=y1;
		++t;
		L[t].x=x2;
		L[t].ly=y1;L[t].ry=y2;
		L[t].isleft=false;
		Y[t]=y2;
		++t;
	}
	sort(L+1,L+t,cmp);
	sort(Y+1,Y+t);
	BuildTree(1,1,t-1);

}