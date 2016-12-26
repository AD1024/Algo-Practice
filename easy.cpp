#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define newn(n,x) for(int i=1;i<=x;i++) n.a[i]=0;
using namespace std;
const int MAXN = 100001;
int d[MAXN];
int num[MAXN];

struct n{
    int a[10001];
}list[MAXN];


int req[MAXN];
int main(){
    memset(req,0,sizeof(req));
    memset(d,0,sizeof(d));
    int m;cin>>m;
    for(int i=1;i<=m;i++){
        cin>>req[i];
    }
    int cnt;
    cin>>cnt;
    for(int i=1;i<=cnt;i++){
        for(int j=1;j<=m;j++){
            cin>>list[i].a[j];
            d[i]+=req[j]-list[i].a[j];
        }
        num[d[i]]=i;
    }
    sort(d+1,d+cnt+1);
    for(int i=1;i<=m;i++){
        req[i]-=list[num[d[1]]].a[i];
    }
    int ans[MAXN];
    ans[0]=num[d[1]];
    int cans=1;
    bool find = false;
    for(int i=1;i<=cnt;i++){
        if(i==num[d[1]]) continue;
        find = true;
        bool find2=true;
        for(int j=1;j<=m;j++){
            if(req[j]>0){
                find =false;
                break;
            }
        }
        if(!find){
            for(int j=1;j<=m;j++){
                req[j]-=list[i].a[j];
            }
            ans[cans]=i;
            cans++;
            for(int k=1;k<=m;k++){
                if(req[k]>0){
                    find2=false;
                    break;
                }
            }
            if(find2){
                sort(ans,ans+cans);
                cout<<cans<<" ";
                for(int k=0;k<cans;k++){
                    cout<<ans[k]<<" ";
                }
                return 0;
            }
        }else{
            sort(ans,ans+cans);
            cout<<cans<<" ";
            for(int k=0;k<cans;k++){
                cout<<ans[k]<<" ";
            }
            return 0;
        }
    }
    return 0;
}
