#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  int n;cin>>n;
  char s[256];
  scanf("%s",s);
  int num[300];
  for(int i=0;i<strlen(s);i++){
    a[i]=s[i]-'0';
  }
  int len = strlen(s);
  for(int i=1;i<=n;i++){
    for(int j=0;j<strlen(s);j++){
      if(a[j]==4 || a[j]==1){
        cout<<" ";
      }else{
        cout<<"-";
      }
      if(j!=strlen(s)-1){
        cout<<" ";
      }
    }
    cout<<endl;
    for(int j=0;)
  }
}
