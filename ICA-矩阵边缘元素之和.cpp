#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  while(n--){
    int x,y;
    cin>>x>>y;
    int sum=0;
    int a[y+10];
    for(int i=1;i<=x;i++){
      for(int j=1;j<=y;j++){
        cin>>a[j];
      }
      if(i==1 || i==x){
        for(int k=1;k<=y;k++){
          sum+=a[k];
        }
      }else{
        sum=sum+a[1]+a[y];
      }
    }
    cout<<sum<<endl;
  }
  return 0;
}
