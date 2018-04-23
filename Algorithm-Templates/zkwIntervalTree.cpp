#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int M,N;
int tree[10100<<1];
#define lson(x) x<<1
#define rson(x) x<<1|1

inline void Maintain(int x) {
	tree[x] = tree[lson(x)] + tree[rson(x)];
}

inline void Build() {
	for(M=1;M<=N;M<<=1);
	for(int i=M;i<M+N;++i) {
		cin>>tree[i];
	}
	for(int i=M-1;i;--i) Maintain(i);
}

inline int query(int l,int r) {
	int ans = 0;
	cout<<"M:"<<M<<endl;
	for(l=l+M-1,r=r+M+1;l^r^1;l>>=1,r>>=1) {
		
		if(~l&1) {
			cout<<"l:"<< l<<endl;
			ans += tree[l^1];
		}
		if(r&1){
			cout<<"r:"<<r<<endl;
			ans += tree[r^1];
		}
	}
	return ans;
}

inline int update(int l,int r,int v) {
	
}

int main(){
	cin>>N;
	Build();
	cout<<query(1, N);
	return 0;
}