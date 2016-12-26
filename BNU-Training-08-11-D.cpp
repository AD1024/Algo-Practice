#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n=0;
int N;
bool used[1001];

int main(){
	cin>>N;
	memset(used,false,sizeof(used));
	int a[10001];
	int last=-1;
	for(int i=0;i<N;++i){
		cin>>a[i];
	}
	sort(a,a+N);
	int tot=N;
	int t;
	while(tot){
		t=0;
		for(int i=0;i<N;++i){
			if(!used[i] && t<=a[i]){
				used[i]=true;
				t++;
				--tot;
			}
		}
		n++;
	}
	cout<<n;
	return 0;
}