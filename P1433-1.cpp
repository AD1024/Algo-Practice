#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
typedef double d;
const double threehalfs = 1.5F; 
double Qsqrt( double number ){  
    long i;  
    double x2, y;  
    x2 = number*0.5F;  
    y  = number;  
    i  = * (long*) & y; 
    i  = 0x5f3759df - ( i >> 1 ); 
    y  = * ( double * ) & i;  
    y  = y * ( threehalfs - ( x2 * y * y ) ); //牛顿迭代-1
    y  = y * ( threehalfs - ( x2 * y * y ) ); //牛顿迭代-2
    y  = y * ( threehalfs - ( x2 * y * y ) ); //牛顿迭代-3
    return 1.0F/y; 
}  

struct P{
	int x,y;
}list[20];

int main(){
	int N;
	cin>>N;
	list[0].x=list[0].y=0;
	for(int i=1;i<=N;i++){
		cin>>list[i].x>>list[i].y;
	}
	d g[20][20];
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(i==j){
				g[i][j]=INF;
			}else{
				g[i][j]=Qsqrt(abs((list[i].x-list[j].x))*abs((list[i].x-list[j].x)))+abs((list[i].y-list[j].y))*abs((list[i].y-list[j].y));
			}
		}
	}
	for(int k=0;k<=N;k++){
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++){
				if(g[i][k]+g[k][j]>g[i][j]){
					g[i][j]=g[i][k]+g[k][j];
				}
			}
		}
	}
	bool vis[20];
	memset(vis,false,sizeof(vis));
	vis[0]=true;
	int last;
	d minm;
	d sum=0.0;
	for(int i=0;i<=N;i++){
		last=19;
		minm=10000.0;
		for(int j=0;j<=N;j++){
			if(g[i][j]<minm && !vis[j] && i!=j){
				vis[last]=false;
				minm=g[i][j];
				vis[j]=true;
			}
		}
		sum+=minm;
	}
	printf("%.2lf",sum);
	return 0;
}