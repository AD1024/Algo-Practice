#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000001;
int a[MAXN],T[MAXN];
int cnt=0;
void mgsort(int l,int r){
  if(r-l>1){
    int mid=l+((r-l)>>1);
    int p,q,i;
    p=l;q=mid;i=l;
    mgsort(l,mid);
    mgsort(mid,r);
    while(p<mid || q<r){
      if(q>=r || (p<mid && a[p]<=a[q])) T[i++]=a[p++];
      else{
        T[i++] =a[q++];cnt+=mid-p;
      }
    }
    for(i=l;i<r;i++){
      a[i]=T[i];
    }
  }
}

int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  mgsort(0,n);
  cout<<cnt;
  return 0;
}
