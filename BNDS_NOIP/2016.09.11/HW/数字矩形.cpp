#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;
map<int,bool> idx;
const int __ans[10]={1,2,3,4,8,7,6,5};
const int Pow10[10]={1,10,100,1000,10000,100000,1000000,10000000};

int a[10];

struct Pos{
	int a[10];
	int step;
	Pos(){}

	Pos(int x[],int s){
		memcpy(a,x,sizeof(int)*8);
		step=s;
	}
	
	int& operator [](const int x){
		return a[x];
	}
};
inline int getNum(int x[]){
	int ret=0;
	for(int i=0;i<8;++i){
		ret+=x[i]*Pow10[i];
	}
	return ret;
}

inline bool judge(int x[]){
	for(int i=0;i<8;++i){
		if(x[i]!=__ans[i]) return false;
	}
	return  true;
}

queue<Pos> q;
void BFS(){
	Pos s = Pos(a,0);
	q.push(s);
	Pos k;
	while(q.size()){
		k=q.front();q.pop();
		if(judge(k.a)){
			cout<<k.step;
			exit(0);
		}
		idx[getNum(k.a)]=true;
		Pos nxt;
		/*Alternation-1*/
		nxt.step=0;
		for(int i=0;i<4;++i){
			nxt[i]=k[i+4];
		}
		for(int i=4;i<8;++i){
			nxt[i]=k[i-4];
		}
		if(!idx[getNum(nxt.a)]){
			idx[getNum(nxt.a)]=true;
			nxt.step=k.step+1;
			q.push(nxt);
		}
		/*Alternation-2*/
		nxt.step=0;
		int m=k[3];
		for(int i=1;i<4;++i){
			nxt[i]=k[i-1];
		}
		nxt[0]=m;
		m=k[7];
		for(int i=5;i<8;++i){
			nxt[i]=k[i-1];
		}
		nxt[4]=m;
		if(!idx[getNum(nxt.a)]){
			idx[getNum(nxt.a)]=true;
			nxt.step=k.step+1;
			q.push(nxt);
		}
		/*Alternation-3*/
		nxt.step=0;
		nxt[0]=k[0];nxt[4]=k[4];nxt[3]=k[3];nxt[7]=k[7];
		nxt[2]=k[1];nxt[6]=k[2];nxt[5]=k[6];nxt[1]=k[5];
		if(!idx[getNum(nxt.a)]){
			idx[getNum(nxt.a)]=true;
			nxt.step=k.step+1;
			q.push(nxt);
		}
	}
}

int main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	for(int i=0;i<8;++i){
		cin>>a[i];
	}
	BFS();
	fclose(stdin);
	fclose(stdout);
	return 0;
}