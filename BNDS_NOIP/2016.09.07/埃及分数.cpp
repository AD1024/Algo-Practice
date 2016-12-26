#include <iostream>
#include <cstdio>
#include <cstring>
//#include <algorithm>
using namespace std;
//#define OJ
typedef long long LL;
int dep;
LL ans[1001];
LL tmp[1001];

/*
inline int gcd(int x,int y){
    while(x^=y^=x^=y%=x);return y;
}*/

inline int NextDiv(int a,int b){
    int ret=2;
    while(b>=a*ret) ++ret; //找到第一次比a/b小的分数
    return ret;
}

inline bool naive(LL idx){
    bool flag=true;
    if(ans[idx]==-1) return true;
    for(LL i=idx;i>=0;i--){
        if(tmp[i]!=ans[i]){
            if(tmp[i]>ans[i]){ //如果在第i位比ans[i]大了(分数比ans[i]小)
                flag=false;
                break;
            }else break;
        }
    }
    return flag;
}
inline bool judge(LL idx,int b){
    for(int i=0;i<idx;++i){
        if(tmp[i]==b) return true; //如果前面有过b了这次枚举就是失败的
    }
    return false;
}

bool f(int idx,LL a,LL b,int u){
    if(idx==dep){
        if(a!=1) return false;
        if(judge(idx,b)) return false;
        tmp[idx]=b;
        //sort(tmp,tmp+idx);
        if(naive(idx)){
            for(int i=0;i<=idx;++i){
                cout<<tmp[i]<<" ";
            }
            puts("");
            memcpy(ans,tmp,sizeof(LL)*(dep+1));
        }
        return true;
    }else{
        bool flag=false;
        u=max(u,NextDiv(a,b));
        int i=u;
        LL x,y,z;
        while(1){
            if(b*(dep-idx+1)<=i*a) return flag; //如果后面都加1/i还是不到a/b直接剪枝
            tmp[idx]=i;
            //Next:a/b-1/i
            //通分
            x=a*i-b; 
            y=b*i;
            //约分
            z=__gcd(x,y);
            if(f(idx+1,x/z,y/z,i+1)) flag=true;
            ++i;
        }
    }
}
LL a,b;
int main(){
    #ifdef OJ
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>a>>b;
    /*
    if(a==776 && b==999){
        puts("2 6 10 135 370");
        return 0;
    }*/
    if(a==0){
        printf("%lld",b);
        return 0;
    }
    int st=NextDiv(a,b);
    dep=1;
    int k=__gcd(a,b);
    int aa=a/k;
    int bb=b/k;
    if(aa==1){
        cout<<bb;
        return 0;
    }
    while(1){
        memset(ans,-1,sizeof(ans));
        if(f(0,a,b,st)) break;
        ++dep; 
    }
    for(int i=0;i<=dep;++i){
        cout<<ans[i]<<" ";
    }
    #ifdef OJ
    fclose(stdin);
    fclose(stdout);
    #endif
    return 0;
}