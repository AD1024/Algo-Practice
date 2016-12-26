#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define DEBUG
const int MAXN = 10001;

//f[i]=max(f[i],f[j]+1) if(a[i]>a[j])

int main(){
	#ifdef DEBUG
	freopen("test.in","w",stdin);
	freopen("test.out","r",stdout);
	#endif
	int a[MAXN];
	int dp1[MAXN];
	int dp2[MAXN];
	int cur=-1;
	while(scanf("%d",&a[++cur])!=EOF);
	cur--;
	for(int i=0;i<=cur;i++){
		dp1[i]=dp2[i]=1;
	}
	//cout<<cur<<endl;
	for(int i=0;i<=cur;i++){
		for(int j=0;j<i;j++){
			if(a[i]<=a[j]&&dp1[i]<dp1[j]+1){
				dp1[i]=dp1[j]+1;
			}
			if(a[j]<a[i] && dp2[i]<dp2[j]+1){
				dp2[i]=dp2[j]+1;
			}
		}
	}
	int ans1=-1000,ans2=-1000;
	for(int i=0;i<=cur;i++){
		ans1=max(ans1,dp1[i]);
		ans2=max(ans2,dp2[i]);
	}
	cout<<ans1<<endl<<ans2;
	return 0;
}
