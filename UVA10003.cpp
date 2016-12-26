#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 0x3f3f3f3f;
int len;
int a[51];
int d[1001][1001];

int main(){
  while(scanf("%d",&len)!=EOF){
    if(len==0){
      break;
    }
    memset(d,0,sizeof(d));
    a[0]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    a[n+1]=len;
    for(int i=n;i>=0;i--){
      for(int j=2+i;j<=n+1;j++){
        int tmp = MAXN;
        for(int k=i+1;k<j;k++){
          // d[i][j]=min(d[i][k]+d[k][j]+a[j]-a[i],d[i][j]);
          tmp=min(tmp,d[i][k]+d[k][j]+a[j]-a[i]);
        }
        d[i][j]=tmp;
      }
    }
    cout<<"The minimum cutting is "<<d[0][n+1]<<"."<<endl;
  }
  return 0;
}
