#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

const int biao[5][5]=
{
	{0,0,1,1,0},
 	{1,0,0,1,0},
 	{0,1,0,0,1},
 	{0,0,1,0,1},
 	{1,1,0,0,0}
};
queue<int> a;
queue<int> b;
int main(){
	int N,NA,NB;
	cin>>N>>NA>>NB;
	for(int i=1;i<=NA;++i){
		int t;cin>>t;
		a.push(t);
	}
	for(int i=1;i<=NB;++i){
		int k;cin>>k;
		b.push(k);
	}
	int ansa=0;
	int ansb=0;
	for(int i=1;i<=N;++i){
		int k=a.front();
		a.pop();a.push(k);
		int j=b.front();
		b.pop();b.push(j);
		ansa+=biao[k][j];
		ansb+=biao[j][k];
	}
	cout<<ansa<<" "<<ansb;
	return 0;
}