#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int t;
double list[]={28.9,32.7,45.6,78,35,86.2,27.8,43.0,56.0,65.0};

int main(){
	int T;cin>>T;
	double ans;
	while(T--){
		ans=0.0;
		for(int i=0;i<10;++i){
			cin>>t;
			ans+=double(t)*list[i];
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}