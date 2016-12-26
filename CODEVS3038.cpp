#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int count=0;
    int a;
    bool ufind = false;
    cin>>a;
    int n=a;
    while(a!=1){
      count+=1;
      if(a%2!=0){
        a=3*a+1;
      }else{
        a/=2;
      }
      if(a==n){
        cout<<-1;
        ufind=true;
        break;
      }
    }
    if(!ufind)
      cout<<count<<endl;
  }
  return 0;
}
