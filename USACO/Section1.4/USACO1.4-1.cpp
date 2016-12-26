/*
ID: ccodera1
LANG: C++
TASK: ariprog
*/

#define OJ

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;

bool bi[1001000];

int cnt;
int list[1010000];
inline void getBool(){
	for(int i=0;i<=M;++i){
		for(int j=i;j<=M;++j){
			if(!bi[i*i+j*j]){
				bi[i*i+j*j] = true;
				list[++cnt] = i*i+j*j;
			}
		}
	}
}

struct P{
	int a,b;
	P(){}
	P(int aa,int bb){
		a = aa;
		b = bb;
	}
};

vector<P> v;

bool cmp(const P a,const P b){
	if(a.b != b.b) return a.b<b.b;
	else return a.a<b.a;
}

int main(){
	#ifdef OJ
		freopen("ariprog.in","r",stdin);
		freopen("ariprog.out","w",stdout);
	#endif
	cin>>N>>M;
	getBool();
	int upper = (M*M)<<1;
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=upper;++j){
			if(list[i]+(N-1)*j>upper) break;
			else{
				int k;bool f=true;int c=1;
				for(k=1;c<N;++k){
					if(bi[k*j+list[i]]) ++c;
					else{
						break;
					}
				}
				if(c == N){
					v.push_back(P(list[i],j));
				}
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	if(v.size() == 0){
		puts("NONE");return 0;
	}
	for(int i=0;i<v.size();++i){
		cout<<v[i].a<<" "<<v[i].b<<endl;
	}
	return 0;
}