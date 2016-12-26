#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int ans=0;

int main(){
	string pre;
	string post;
	cin>>pre>>post;
	for(int i=0;i<pre.size();++i){
		for(int j=0;j<post.size();++j){
			if(pre[i]==post[j] && pre[i+1]==post[j-1]){
				ans+=1;
			}
		}
	}
	ans=1<<ans;
	cout<<ans;
	return 0;
}