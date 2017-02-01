#include <iostream>  
#include <string>  
#include <cstring>
#include <map>
#include <algotithm>
using namespace std;
struct Line{
	int l,r;
}l[10010];

int p[10000010];

int N,M;

bool cmp(Line a,Line b){
	return a.l<b.l;
}

int main(){
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>l[i].l>>l[i].r;
	}
	sort(l+1,l+N+1,cmp);
	
}