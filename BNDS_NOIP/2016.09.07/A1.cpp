#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
//#define OJ
#define eps 1e-5
int depth;
double target;
double ABS(double x){
	return x>0?x:-x;
}
stack<int> ans;
bool f(int dep,double sum,int idx){
	if(dep==depth){
		if(ABS(target-sum)<eps){
			return true;
		}else return false;
	}else{
		int gap=(depth-dep)/(target-sum);
		while(idx<=gap){
			if(f(dep+1,sum+1.0/idx,idx+1)){
				ans.push(idx);
				return true;
			}
			++idx;
		}
	}
	return false;
}

int main(){
	#ifdef OJ
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	double a,b;
	cin>>a>>b;
	target=a/b;
	depth=1;
	while(!f(0,0.0,(int)(1.0/target)+1)) ++depth;
	while(ans.size()){
		printf("%d ",ans.top());
		ans.pop();
	}
	#ifdef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}