#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
using namespace std;

int N,Q;
int main(){
	cin>>N>>Q;
	int a[1001];
	for(int i=1;i<=N;++i){
		cin>>a[i];
	}
	int fl;
	int maxn=-100000000;
	int ans;
	while(Q--){
		int l,r;
		map<int,int> idx;
		ans=10000;
		maxn=-100000000;
		cin>>fl>>l>>r;
		if(fl){
			a[l]=r;
		}else{
			for(int i=l;i<=r;++i){
				idx[a[i]]+=1;
				if(idx[a[i]]>maxn){
					maxn=idx[a[i]];
					ans=a[i];
				}else if(idx[a[i]]==maxn){
					ans=(ans>a[i]?a[i]:ans);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}