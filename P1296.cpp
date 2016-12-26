#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1000010];
int N,D;
int main(){
	cin>>N>>D;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	sort(a,a+N);
	int cnt=0;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(a[j]-a[i]<=D){
				cnt++;
			}else break;
		}
	}
	cout<<cnt;
	return 0;
}