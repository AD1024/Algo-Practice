#include <cstdio>
#include <cmath>

using namespace std;

#ifdef WIN32
#define lld "%I64d"
#else
#define lld "%lld"
#endif

int T;
long long g,l;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf(lld lld,&g,&l);
		long long ans_min = (long long)sqrt(l / g) * g;
		long long ans_max = g + l;
		printf(lld " " lld "\n",ans_min*2,ans_max);
	}
}