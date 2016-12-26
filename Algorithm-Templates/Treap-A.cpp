#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Node{
	int l,r,w,v,size;
	int fix;
}T[100005];
int _size=0;
int ROOT;

inline void init(){
	srand(19260817); // MOD MOD MOD
}

inline void Update(int k){
	T[k].size=T[T[k].l].size+T[T[k].r].size+T[k].w;
}

inline void left_rot(int &k){
	int t=T[k].r;
	T[k].r=T[t].l;
	T[t].l=k;
	T[t].size=T[k].size;
	Update(k);
	k=t;
}

inline void right_rot(int &k){
	int t=T[k].l;
	T[k].l=T[t].r;
	T[t].r=k;
	T[t].size=T[k].size;
	Update(k);
	k=t;
}

void Insert(int &k,int v){
	if(k==0){
		_size++;
		k=_size;
		T[k].size=T[k].w=1;
		T[k].v=v;
		T[k].fix=rand();
		return;
	}
	T[k].size+=1;
	if(T[k].v==v) T[k].w++;
	else if(T[k].v<v){
		Insert(T[k].r,v);
		if(T[k].fix>T[T[k].r].fix) left_rot(k);
	}else{
		Insert(T[k].l,v);
		if(T[k].fix>T[T[k].l].fix) right_rot(k);
	}
}

void del(int &k,int v){
	if(k==0) return;
	if(T[k].v==v){
		if(T[k].w>1){
			T[k].w--;
			T[k].size--;
			return;
		}
		if(T[k].l*T[k].r==0){
			k=T[k].r+T[k].l;
		}else if(T[T[k].l].fix<T[T[k].r].fix){
			right_rot(k);del(k,v);
		}else{
			left_rot(k);del(k,v);
		}
	}else if(T[k].v>v){
		T[k].size--;
		del(T[k].l,v);
	}else{
		T[k].size--;
		del(T[k].r,v);
	}
}

int Rank(int k,int v){
	if(k==0) return 0;
	if(T[k].v==v) return T[T[k].l].size+1;
	else if(T[k].v<v){
		return T[k].w+T[T[k].l].size+Rank(T[k].r,v);
	}else return Rank(T[k].l,v);
}

int Num(int k,int v){
	if(k==0) return 0;
	if(v<=T[T[k].l].size){
		return Num(T[k].l,v);
	}else if(v>T[T[k].l].size+T[k].w){
		return Num(T[k].r,v-T[T[k].l].size-T[k].w);
	}else return T[k].v;
}
int ans=0;
void query_pre(int k,int v){
	if(k==0) return;
	if(T[k].v<v){
		ans=k;
		query_pre(T[k].r,v);
	}else query_pre(T[k].l,v);
}

void query_son(int k,int v){
	if(k==0) return;
	if(T[k].v>v){
		ans=k;
		query_son(T[k].l,v);
	}else query_son(T[k].r,v);
}

int main(){
	int N;
	cin>>N;
	int op,v;
	while(N--){
		cin>>op>>v;
		switch(op){
			case 1:Insert(ROOT,v);break;
			case 2:del(ROOT,v);break;
			case 3:cout<<Rank(ROOT,v)<<"\n";break;
			case 4:cout<<Num(ROOT,v)<<"\n";break;
			case 5:{
				ans=0;
				query_pre(ROOT,v);cout<<T[ans].v<<"\n";
				break;
			}
			case 6:{
				ans=0;
				query_son(ROOT,v);cout<<T[ans].v<<"\n";
				break;
			}
		}
	}
	return 0;
}