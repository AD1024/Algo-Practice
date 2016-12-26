#include <iostream>
#include <queue>
#include <cstdio>
#include <cstdlib>
using namespace std;

deque<int> mem;

int main(){
	int N,M;
	cin>>M>>N;
	int ans=0;
	while(N--){
		int k;cin>>k;
		bool found=false;
		for(int i=0;i<mem.size();++i){
			if(mem[i]==k){
				found=true;break;
			}
		}
		if(found){
			continue;
		}
		else{
			if(mem.size()==M){
				mem.pop_front();
				mem.push_back(k);
				ans++;
			}else{
				ans++;
				mem.push_back(k);
			}
		}
	}
	cout<<ans;
	return 0;
}