#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(){
  int n;
  cin>>n;
  while(n){
    double a,b,c;
    cin>>a>>b>>c;
    double delta = b*b-4*a*c;
    if(delta>0){
      double ans1 = (0-b+sqrt(delta))/2*a;
      double ans2 = (0-b-sqrt(delta))/2*a;
      printf("x1=%.5f;x2=%.5f\n",ans1,ans2);
    }else if(fabs(delta)<1e-8){
      double ans = (0-b+sqrt(delta))/2*a;
      printf("x1=x2=%.5f\n",ans);
    }else{
      double ans1Real = (0-b)/2*a;
      double ans1Void = (sqrt((0-b*b)+4*a*c))/(2*a);
      printf("x1=%.5f+%.5fi;x2=%.5f-%.5fi\n",ans1Real,ans1Void,ans1Real,ans1Void);
    }
    n--;
  }
  return 0;
}
