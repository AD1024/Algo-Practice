/*
ID: ccodera1
LANG: C++
TASK: milk3
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{
	int A,B,C;
	Pos(){}
	Pos(int x,int y,int z){
		A = x;
		B = y;
		C = z;
	}
};
queue<Pos> q;

bool vis[30][30][30];
bool have[50];
vector<int> v; 
int a,b,c;

inline void enqueue(Pos x){
	if(!vis[x.A][x.B][x.C]){
		vis[x.A][x.B][x.C] = true;
		q.push(x);
	}
}

inline void BFS(Pos start){
	enqueue(start);Pos k;
	while(!q.empty()){
		k = q.front();q.pop();
		int ca = k.A;
		int cb = k.B;
		int cc = k.C;
		if(!have[cc] && ca == 0){
			have[cc] = true;
			v.push_back(cc);
		}
		int na,nb,nc;
		if(ca > 0){
			// A -> B
			nc = cc;
			if(cb + ca > b){
				nb = b;
				na = ca - (b - cb);
			}else{
				na = 0;
				nb = cb + ca;
			}
			enqueue(Pos(na,nb,nc));
			// A -> C
			nb = cb;
			if(cc + ca > c){
				nc = c;
				na = ca - (c - cc);
			}else{
				na = 0;
				nc = ca + cc;
			}
			enqueue(Pos(na,nb,nc));
		}
		if(cb > 0){
			// B -> A
			nc = cc;
			if(cb + ca > a){
				na = a;
				nb = cb - (a - ca);
			}else{
				nb = 0;
				na = ca + cb;
			}
			enqueue(Pos(na,nb,nc));
			// B -> C
			na = ca;
			if(cb + cc > c){
				nc = c;
				nb = cb - (c - cc);
			}else{
				nb = 0;
				nc = cc + cb;
			}
			enqueue(Pos(na,nb,nc));
		}
		if(cc > 0){
			// C -> A
			nb = cb;
			if(cc + ca > a){
				na = a;
				nc = cc - (a - ca);
			}else{
				nc = 0;
				na = cc + ca;
			}
			enqueue(Pos(na,nb,nc));
			// C -> B
			na = ca;
			if(cc + cb > b){
				nb = b;
				nc = cc - (b - cb);
			}else{
				nc = 0;
				nb = cc + cb;
			}
			enqueue(Pos(na,nb,nc));
		}
	}
}

int main(){
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	cin>>a>>b>>c;
	BFS(Pos(0,0,c));
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i){
		cout<<v[i];
		if(i+1!=v.size()){
			putchar(' ');
		}
	}
	puts("");
	return 0;
}