#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 10001;
int n;
int data[MAXN],l[MAXN],r[MAXN];

void pre(int n){
  if(data[n]==-1) return;
  cout<<data[n]<<" ";
  pre(l[n]);
  pre(r[n]);
}

void post(int n){
  if(data[n]==-1) return;
  post(l[n]);
  post(r[n]);
  cout<<data[n]<<" ";
}

void mid(int n){
  if(data[n]==-1) return;
  mid(l[n]);
  cout<<data[n]<<" ";
  mid(r[n]);
}

int main(){
  scanf("%d",&n);
  memset(data,-1,sizeof(data));
  for(int i=1;i<=n;i++){
    cin>>l[i]>>r[i];
    data[i]=i;
  }
  pre(1);cout<<endl;
  mid(1);cout<<endl;
  post(1);
  return 0;
}
