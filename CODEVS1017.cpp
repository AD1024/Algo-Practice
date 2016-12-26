#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int ans=0;
void DFS(int n,int part,int lastpos){
	if(part==1){
		ans+=1;
		return;
	}
	int i=lastpos;
	while(i<=(n-i)/(part-1)){
		DFS(n-i,part-1,i);
		i++;
	}
}

int main(){
	int n,k;
	cin>>n>>k;
	DFS(n,k,1);
	cout<<ans;
	return 0;
}
