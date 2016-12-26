#include <iostream>
using namespace std;
#define MOD 1000000007
int main(){
	freopen("list.txt","w",stdout);
	long long f[2];
	f[0]=7;f[1]=2;
	int pos=1;
	cout<<"{";
	long long p1,p,p2;
	p1=7;p2=2;
	for(int i=3;i<=2000000000;++i){
		p=(2*(p1+p2)+3)%MOD;
		if(i%3000000==3){
			printf("%lld,%lld,",p2,p1);
		}
		p2=p1;p1=p;
	}
	cout<<"}";
	return 0;
}