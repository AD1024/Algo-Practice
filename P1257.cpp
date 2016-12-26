#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
double ans=INF;

inline double sqr(double x){
	return x*x;
}

struct Point{
	double x,y;
	Point(){}
	Point(double xx,double yy){x=xx;y=yy;}
	double operator&(const Point b){
		return sqrt((sqr(x-b.x)+sqr(y-b.y)));
	}
}list[10001];
int N;

int main(){
	scanf("%d",&N);
	double x,y;
	Point p;
	for(int i=0;i<N;++i){
		scanf("%lf%lf",&x,&y);
		list[i]=Point(x,y);
	}
	for(int i=0;i<N-1;++i){
		for(int j=i+1;j<N;++j){
			if(i!=j){
				if((list[i]&list[j])<ans){
					ans=(list[i]&list[j]);
				}
			}
		}
	}
	printf("%.4f",ans);
	return 0;
}