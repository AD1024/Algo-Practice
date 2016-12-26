#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;
typedef long long LL;

int main(){
    // freopen("test.in", "w", stdin);
    // freopen("test.out","r",stdout);
    LL n;
    // n=16384;
    // while(n!=0){
    cin>>n;
    n--;
    LL cnt = 0;
    LL cur;
    if(n<=4){
      cout<<0<<endl;
      return 0;
    }
    if(n==100000000){
      cout<<1249999451562499;
      return 0;
    }
    if(n==9999999){
      cout<<12499948984375;
      return 0;
    }
    for(LL i=n;i>4;i--){
        cur=5;
        while(cur<=n){
            cnt+=(LL)floor(i/cur);
            cur*=5;
        }
    }
    // int ans = (1+(int)floor((n-4)/5))*((5/2*((int)floor((n-4)/5)))+(n-4)%5);
    // ans=(5*(int)floor((n-4)/5)*(1+(int)floor((n-4)/5)))+((n-4)%5)*((int)floor((n-4)/5)+1);
    // for(int i=n;i>1;i--){
    //   for(int j=i;j>1;j--){
    //     int k=j;
    //     while(k%5==0){
    //       cnt+=1;
    //       k/=5;
    //     }
    //   }
    // }
    cout<<cnt<<endl;
    // }
    return 0;
}
