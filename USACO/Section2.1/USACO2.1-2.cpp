/*
ID: ccodera1
LANG: C++
TASK: frac1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

struct Pair{
	int a,b;
	double value(){
		return double(a)/double(b);
	}
	Pair(){}
	Pair(int x,int y){
		a = x;
		b = y;
	}
};

map<double,bool> idx;

vector<Pair> v;

int N;

inline int gcd(int x,int y){
	while(x^=y^=x^=y%=x);return y;
}

bool cmp(Pair a,Pair b){
	return a.value()<b.value();
}

int main(){
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	scanf("%d",&N);
	puts("0/1");
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			if(i>j) continue;
			if(!idx[Pair(i,j).value()] && gcd(i,j) == 1){
				v.push_back(Pair(i,j));
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();++i){
		cout<<v[i].a<<"/"<<v[i].b<<endl;
	}
	return 0;
}