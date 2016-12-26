#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[100][100];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
int main(){
	int N;
	cin>>N;
	int k;
	int px,py;
	px=py=1;
	int xx=0;
	int lap=0;
	k=1;
	while(k<=N*N){
		for(;py<=N-lap;++py){
			a[px][py]=k;
			++k;
		}
		--py;
		++px;
		for(;px<=N-lap;++px){
			a[px][py]=k;
			++k;
		}
		--px;--py;
		for(;py>=1+lap;--py){
			a[px][py]=k;++k;
		}
		++py;
		--px;
		++lap;
		for(;px>=lap+1;--px){
			a[px][py]=k;++k;
		}
		++px;
		++py;
	}
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			cout<<a[i][j]<<" ";
		}
		puts("");
	}
	return 0;
}