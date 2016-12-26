#include <iostream>
using namespace std;

int main(){
	int n;int r;
	cin>>n>>r;
	int x;
	int last;
	int maxn=0;
	cin>>last;
	for(int i=1;i<n;++i){
		cin>>x;
		if(last-x-r>maxn){
			maxn=last-x-r;
		}
		last=x;
	}
	cout<<maxn;
	return 0;
}
