#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
using namespace std;

int N;
int M;
int a;
int pos[10001];
map<int,bool> idx;
int main(){
	cin>>N>>M;
	memset(pos,0,sizeof(pos));
	if(N==1){
		puts("0");
		return 0;
	}
	idx[0]=1;
	for(int i=1;i<=M;++i){
		cin>>a;
		if(a==1){
			puts("0");
			return 0;
		}else if(a==5 && N!=5){
			puts("0");
			return 0;
		}
	}
	return 0;
}