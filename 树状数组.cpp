#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int N;

#define lowbit(x) x&(-x)

int T[5000010];

inline void add(int k,int num){
	while(k<=N){
		T[k]+=num;
		k+=lowbit(k);
	}
}

inline int sum(int x){
	int sum=0;
	while(x>0){
		sum+=T[x];
		x-=lowbit(x);
	}
	return sum;
}

inline int query(int l,int r){
	return sum(r)-sum(l-1);
}

int main(){
	cin>>N;
	int k;
	for(int i=1;i<=N;++i){
		cin>>k;
		add(i,k);
	}
	int q,cmd;
	cin>>q;
	int a,b;
	while(q--){
		scanf("%d%d%d",&cmd,&a,&b);
		if(cmd==1){
			add(a,-b);
		}else{
			printf("%d\n",query(a,b));
		}
	}
	return 0;
}