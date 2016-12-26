#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	int N;
	cin>>N;
	int a[10001];
	int sum=0;
	for(int i=1;i<=N;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int avg = sum/N;
	sum=0;
	int cnt=0;
	for(int i=1;i<=N;i++){
		a[i]-=avg;
		sum+=a[i];
		if(sum!=0) cnt++;
	}
	cout<<cnt;
	return 0;
}