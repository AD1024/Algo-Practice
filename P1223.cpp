#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
  int n;cin>>n;
  int a[1010];
  int order[1010];
  for(int i=1;i<=n;i++){
    order[i]=i;
  }
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(a[i]>a[j]){
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
        t=order[i];
        order[i]=order[j];
        order[j]=t;
      }
    }
  }
  int sum=0;
  for(int i=1;i<=n;i++){
    cout<<order[i]<<" ";
    sum+=a[i]*(n-i);
  }
  cout<<endl;
  printf("%.2f",(float)sum/n);
  return 0;
}
