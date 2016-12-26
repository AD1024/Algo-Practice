#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
const int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
const int Pow10[15]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
typedef long long LL;
#define L long

inline int getSum(int x[]){
	int ret=0;
	for(int i=0;i<8;++i){
		ret+=x[i]*Pow10[i];
	}
	return ret;
}
map<int,bool> vis;
bool flag=false;
int tar[9]={1,2,3,8,0,4,7,6,5};
int a[9];
int zzpos;
struct Pos{
	int a[9];
	int step;
	int zero;
	Pos(){}
	Pos(int x[],int s,int z){
		step=s;
		zero=z;
		memcpy(a,x,sizeof(int)*9);
	}
	int& operator[](const int x){
		return a[x];
	}
};

inline bool judge(int a[]){
	for(int i=0;i<9;++i){
		if(a[i]!=tar[i]) return false;
	}
	return true;
}
queue<Pos> q;

inline void BFS(){
	q.push(Pos(a,0,zzpos));
	vis[getSum(a)]=true;
	Pos k;
	while(q.size()){
		k=q.front();q.pop();
		if(judge(k.a)){
			printf("%d",k.step);
			flag=true;
			return;
		}else{
			int zpos=k.zero;
			if(zpos+3<9){
				Pos add=Pos(k.a,k.step+1,zpos+3);
				swap(add[zpos],add[zpos+3]);
				if(!vis[getSum(add.a)]){
					vis[getSum(add.a)]=true;
					q.push(add);
				}
			}
			if(zpos-3>=0){
				Pos add=Pos(k.a,k.step+1,zpos-3);
				swap(add[zpos],add[zpos-3]);
				if(!vis[getSum(add.a)]){
					vis[getSum(add.a)]=true;
					q.push(add);
				}
			}
			if(zpos+1!=3 && zpos+1!=6 && zpos+1<9){
				Pos add=Pos(k.a,k.step+1,zpos+1);
				swap(add[zpos],add[zpos+1]);
				if(!vis[getSum(add.a)]){
					vis[getSum(add.a)]=true;
					q.push(add);
				}
			}
			if((zpos-1!=2 && zpos-1!=5) && zpos-1>=0){
				Pos add=Pos(k.a,k.step+1,zpos-1);
				swap(add[zpos],add[zpos-1]);
				if(!vis[getSum(add.a)]){
					vis[getSum(add.a)]=true;
					q.push(add);
				}
			}
			
		}
	}
}

int main(){
	string s;
	cin>>s;
	for(int i=0;i<9;++i){
		a[i]=s[i]-'0';
		if(a[i]==0) zzpos=i;
	}
	BFS();
	if(!flag){
		puts("-1");
	}
	return 0;
}