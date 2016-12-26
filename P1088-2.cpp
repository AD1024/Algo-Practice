#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};

long encode(int n[],int len){
  int rt = 0;
  int tmp;
  for(int i=1;i<len;i++){
    tmp=0;
    for(int j=i+1;j<=len;j++){
      if(n[i]>n[j])
        tmp+=1;
    }
    rt+=fac[len-i]*tmp;
  }
  return (rt+1);
}

int *uncantor(int x, int k,int add) {
     int res[k+100];
     x+=add;
     int i, j, l, t;
     bool h[k+100]={0};
     for (i = 1; i <= k; i++)
     {
         t = x / fac[k - i];
         x -= t * fac[k - i];
         for (j = 1, l = 0; l <= t; j++)
             if (!h[j])
                 l++;
         j--;
         h[j] = true;
         res[i - 1] = j;
    }
    return res;
 }

int main(){
  int n,add;
  cin>>n>>add;
  int a[n+10];
  for(int i=1;i<=n;i++)
    cin>>a[i];
  long long bit = encode(a,n);
  // cout<<bit;
  int *p = uncantor(bit,n,add);
  for(int i=0;i<n;i++){
    cout<<p[i]<<" ";
  }
  return 0;
}
