#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct StaticList{
	int a[1001];
	int Next[1001];
	int tot=0;
	StaticList(){
		memset(Next,-1,sizeof(Next));
	}
	void Push(int x){
		Next[tot]=a[x];
	}
};