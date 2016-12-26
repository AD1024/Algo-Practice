#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

//1-red 0-blue
int main(){
  int n;
  cin>>n;
  char s[1000];
  scanf("%s",s);
  char tmp[1000];
  strcpy(tmp, s);
  strcat(s,tmp);
  int right[1000][2];
  int left[1000][2];
  right[2*n][0]=right[2*n][1]=left[0][0]=left[0][1]=0;
  for(int i=1;i<n*2;i++){
    if(s[i-1]=='w'){
      left[i][0]=left[i-1][0]+1;
      left[i][1]=left[i-1][1]+1;
    }else if(s[i-1]=='r'){
      left[i][1]=left[i-1][1]+1;
      left[i][0]=0;
    }else if(s[i-1]=='b'){
      left[i][0]=left[i-1][0]+1;
      left[i][1]=0;
    }
  }
  for(int i=n*2-1;i>=0;i--){
    if(s[i]=='w'){
      right[i][0]=right[i+1][0]+1;
      right[i][1]=right[i+1][1]+1;
    }else if(s[i]=='r'){
      right[i][1]=right[i+1][1]+1;
      right[i][0]=0;
    }else if(s[i]=='b'){
      right[i][0]=right[i+1][0]+1;
      right[i][1]=0;
    }
  }
  int ans=-100;
  for(int i=1;i<=2*n;i++){
    ans=max(ans,max(right[i][0],right[i][1])+max(left[i][0],left[i][1]));
  }
  cout<<(ans>n?n:ans);
  return 0;
}
