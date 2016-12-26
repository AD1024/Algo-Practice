#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <map>
using namespace std;

struct Pos{
	int step;
	string a;
	Pos(){}
	Pos(int st,string s){
		step=st;
		a=s;
	}
	char& operator[](const int x){
		return a[x];
	}
};

struct PAIR{
	string s;
	string d;
	PAIR(){}
	PAIR(string a,string b){
		s=a;
		d=b;
	}
};

queue<Pos> q;
map<string,bool> vis;
string start,dest;
vector<PAIR> v;
int cur=0;

inline void BFS(){
	vis[start]=true;
	q.push(Pos(0,start));
	Pos k;
	PAIR z;
	while(q.size()){
		k=q.front();q.pop();
		if(k.a==dest && k.step<=10){
			cout<<k.step;
			return;
		}
		if(k.step>10) break;
		for(int i=0;i<v.size();++i){
			z=v[i];
			int pos=k.a.find(z.s);
			if(pos>=0){
				for(int j=pos;j>=0 && j<=k.a.size()-z.s.size();j=k.a.find(z.s,j+1)){
					Pos add;
					add=k;
					add.step+=1;
					add.a.replace(j,z.s.size(),z.d);
					if(!vis[add.a]){
						vis[add.a]=true;
						q.push(add);
					}
				}
			}
		}
	}
	cout<<"NO ANSWER!\n";
}

int main(){
	freopen("noipg2.in","r",stdin);
	freopen("noipg2.out","w",stdout);
	cin>>start>>dest;
	string k,t;
	while(cin>>k>>t){
		v.push_back(PAIR(k,t));
	}
	BFS();
	return 0;
}