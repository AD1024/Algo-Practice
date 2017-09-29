#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node{
	int lson,rson,w,size;
	int fix;
	int v;
};

int _size = 0;

Node tree[101000<<2];

inline void maintain(int rt){
	tree[rt].size = tree[tree[rt].lson].size + tree[tree[rt].rson].size + tree[rt].w;
}

inline void right_rot(int &rt){
	int t = tree[rt].lson;
	tree[rt].lson=tree[t].rson;
	tree[t].rson=rt;
	maintain(rt);
	rt = t;
}

inline void left_rot(int &rt){
	int t=tree[rt].rson;
	tree[rt].rson=tree[t].lson;
	tree[t].lson=rt;
	maintain(rt);
	rt=t;
}

void insert(int &k, int v){
	if(k == 0){
		++_size;
		k = _size;
		tree[k].w = tree[k].size = 1;
		tree[k].fix = rand();
	}else{
		if(tree[k].v == v) tree[k].w++;
		else if(v > tree[k].v){
			insert(tree[k].rson, v);
			if(tree[tree[k].rson].fix < tree[k].fix){
				left_rot(k);
			}
		}else{
			insert(tree[k].lson, v);
			if(tree[tree[k].lson].fix < tree[k].fix){
				right_rot(k);
			}
		}
	}
}

void remove(int &k, int v){
	if(k == 0) return;
	else{
		if(tree[k].v == v){
			if(tree[k].w > 1) {tree[k].size--;tree[k].w--;return;}
			else{
				if(tree[k].lson * tree[k].rson) k = tree[k].lson+tree[k].rson;
				else if(tree[tree[k].lson].fix < tree[tree[k].rson].fix){
					right_rot(k);
					remove(k, v);
				}else{
					left_rot(k);remove(k, v);
				}
			}
		}else if(tree[k].v > v){
			tree[k].size--;
			remove(tree[k].lson, v);
		}else{
			tree[k].size--;
			remove(tree[k].rson, v);
		}
	}
}

int main(){
	srand(time(NULL));
}