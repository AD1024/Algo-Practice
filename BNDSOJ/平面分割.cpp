#include <iostream>
#include <cstdio>
using namespace std;

int N,P,ans;

int main(){
 	scanf("%d %d",&N,&P);
 	ans=(P<<1);
 	for(int i=P+1;i<=N;++i) {
  		ans += i;
 	}
 	printf("%d\n",ans);
 	return 0;
}