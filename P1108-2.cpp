#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 10001;

int dp[MAXN];
int a[MAXN];
int cases[MAXN];


int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>a[i];
	}
	int t;
	for(int i=1;i<=N+1;i++){
		cases[i]=1;
		t=1<<30;
		for(int j=i-1;j>=1;j--){
			if(a[j]>a[i]){
				if(dp[i]<=dp[j]){
					t=a[j];
					dp[i]=dp[j]+1;
					cases[i]=cases[j];
				}else if(dp[i]==dp[j]+1 && a[j]<t){
					t=a[j];
					cases[i]+=cases[j];
				}
			}
		}
	}
	int maxn1=-100,maxn2=-100;
	cout<<dp[N+1]<<" "<<cases[N+1];
	return 0;
}