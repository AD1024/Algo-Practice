#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(n,i) for(int i=0;i<=n;i++)
typedef long long lovelive;
const lovelive MAXN = 9223372036854775810ll;
lovelive f[30][30][30];

lovelive w(lovelive a,lovelive b,lovelive c){
  if(a<=0 || b<=0 || c<=0) return 1;
  if(a>20 || b>20 || c>20) return w(20,20,20);
  if(f[a][b][c]!=MAXN){
    return f[a][b][c];
  }
  lovelive ans;
  if(a<b && b<c){
    ans = w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
  }else{
    ans = w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
  }
  f[a][b][c]=ans;
  return ans;
}

int main(){
  lovelive a,b,c;
  int i,j,k;
  rep(25,i){
    rep(25, j){
      rep(25, k){
        f[i][j][k]=MAXN;
      }
    }
  }
  for(;;){
    cin>>a>>b>>c;
    if(a==-1 && b==-1 && c==-1){
      break;
    }
    cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c)<<"\n";
  }
  return 0;
}
