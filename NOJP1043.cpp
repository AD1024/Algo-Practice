#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;

map<int,bool> idx;

int main(){
	int L,R;
	int k;
	vector<int> ans;
	while(~scanf("%d%d",&L,&R)){
		ans.clear();
		idx.clear();
		for(int i=0;i<L;++i){
			cin>>k;
			if(!idx[k]){
				ans.push_back(k);
				idx[k]=true;
			}
		}
		for(int i=0;i<R;++i){
			cin>>k;
			if(!idx[k]){
				ans.push_back(k);
				idx[k]=true;
			}
		}
		for(int i=0;i<ans.size()-1;++i){
			printf("%d ",ans[i]);
		}
		printf("%d\n",ans.back());
	}
	return 0;
}