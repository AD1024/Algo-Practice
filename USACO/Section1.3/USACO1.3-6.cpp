/*
ID: ccodera1
LANG: C++
TASK: skidesign
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10100];
int N;

#define OJ

int main(){
	#ifdef OJ
		freopen("skidesign.in","r",stdin);
		freopen("skidesign.out","w",stdout);
	#endif
	cin>>N;
	for(int i=1;i<=N;++i) cin>>a[i];
	int ans = 0x3f3f3f;
	int p;int tot;
	for(int i=1;i<=100-17;++i){
		tot = 0;
		for(int j=1;j<=N;++j){
			if(a[j]<i){
				p = a[j]-i;
			}else if(a[j]>i+17){
				p = a[j]-(i+17);
			}else p=0;
			tot += p*p;
		}
		ans = min(ans,tot);
	}
	cout<<ans<<"\n";
	return 0;
}