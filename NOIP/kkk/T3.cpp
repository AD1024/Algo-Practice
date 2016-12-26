#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <map>
using namespace std;
const int matches[10]={6,2,5,5,4,5,6,3,7,6};
const char corr[10]=   {0,0,'1','7','4','5','9','8',0,0};
map<int,int> idx;
int N;
int M;

string dp[110];

int main(){
	cin>>N>>M;
	dp[2]="1";dp[3]="7";
	dp[4]="4";dp[5]="5";
	dp[6]="9";dp[7]="8";
	for(int i=N;i>=0;--i){
		for(int j=7;j>=2;--j){
			if(i>=j){
				dp[i]=max(corr[j]+dp[i-j],dp[i-j]+corr[j]);
			}
		}
	}
	cout<<dp[N];
	return 0;
}