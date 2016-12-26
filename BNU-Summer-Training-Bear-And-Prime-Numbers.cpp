#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std; 
  
const int MAXN = 10000005;  
  
int n,m;
int cnt[MAXN],ans[MAXN];  
bool v[MAXN];

inline void initPrime() {  
    memset(v,0,sizeof(v));  
    memset(cnt,0,sizeof(cnt));  
    memset(ans,0,sizeof(ans));    
    cin>>n;  
    int tmp;
    for (int i=0;i<n;i++) {  
        scanf("%d",&tmp);
        cnt[tmp]+=1;
    }  
    for (int i=2;i<MAXN;i++) {  
        if (!v[i]){
            for (int j=i;j<MAXN;j+=i) {  
                if (cnt[j]) 
                    ans[i]+=cnt[j];  
                v[j]=true;;  
            }
        }
    }
    for (int i=1;i<MAXN;i++) {
        ans[i]+=ans[i-1];
    }
}  
  
void work() {  
    int l,r;  
    cin>>m;  
    while(m--){
        scanf("%d%d",&l,&r);
        if (l>=MAXN) 
            l=MAXN;  
        if (r>=MAXN)
            r=MAXN-1;  
        cout<<ans[r]-ans[l-1]<<"\n";
    }  
}  
  
int main() {  
    initPrime();  
    work();  
    return 0;  
}