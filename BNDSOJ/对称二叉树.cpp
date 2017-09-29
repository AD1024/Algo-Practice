#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define lson(x) x<<1
#define rson(x) x<<1|1
#define fa(x) x>>1

#define l(x) tree[x].ch[0]
#define r(x) tree[x].ch[1]

struct Node{
	int ch[2];
};

Node tree[101000];

string x;
int p = 1;

int main(){
	ios::sync_with_stdio(true);
	cin>>x;
	x = '#' + x;
	int n = x.size();
	for(int i=1;i<n;++i){
		if(x[i] == '#') {
			tree[fa(i)].ch[i&1] = 0;
		}else{
			tree[fa(i)].ch[i&1] = 1;
		}
	}
	for(int i=1;i<n;++i) {
		if(l(i) ^ r(i)) {
			cout<<"No";return 0;
		}
	}
	cout<<"Yes";
	return 0;
}