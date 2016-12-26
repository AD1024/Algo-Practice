#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void sort(int l,int r,int a[]){
    int x=a[(l+r)>>1];
    int i=l,j=r;
    do{
        while(a[i]<x) ++i;
        while(a[j]>x) --j;
        if(i<=j) swap(a[i++],a[j--]);
    }while(i<j);
    if(i<r) sort(i,r,a);
    if(j>l) sort(l,j,a);
}

int v[300100];
bool used[300100];
int W,N;
int main(){
    cin>>W;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>v[i];
    }
    sort(1,N,v);
    int ans=0;
    for(int i=1;i<=N;++i){
        if(!used[i]){
            int k=v[i];int j;
            bool pa=false;
            for(j=N;j>i;--j){
                if(k+v[j]<=W && !used[j]){
                	pa=true;
                    ans++;
                    break;
                }
            }
            //cout<<i<<" "<<j<<endl;
            if(pa) used[i]=used[j]=true;
        }
    }
    for(int i=1;i<=N;++i){
        if(!used[i]) ++ans;
    }
    cout<<ans;
    return 0;
}