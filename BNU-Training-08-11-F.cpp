#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

inline int MIN(int x,int y){
	return x>y?y:x;
}
bool x[1000],y[1000];
int main(){
	int N;
	cin>>N;
	memset(x,false,sizeof(x));
	memset(y,false,sizeof(y));
	int x1,y1;
	int ansx=0;
	int ansy=0;
	for(int i=0;i<N;++i){
		cin>>x1>>y1;
		if(!x[x1])
			ansx++;
		if(!y[y1]){
			ansy++;
		}
		x[x1]=y[y1]=true;
	}
	printf("%d\n",MIN(ansx,ansy));
	return 0;
}