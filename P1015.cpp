#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 10001;
int md;
string k;
int a[MAXN];
int len=0;
void process(){
    for(int i=0;i<k.length();i++){
        if(k[i]<'A'){
            a[i+1]=k[i]-'0';
        }else{
            a[i+1]=k[i]-'A'+10;
        }
    }
}

void init(){
    memset(a,0,sizeof(a));
    cin>>md;
    cin>>k;
    len=k.length();
    process();
}

bool judge(){
    for(int i=1;i<=len/2;i++){
        if(a[i]!=a[len-i+1]) return false;
    }
    return true;
}

void ps(){
    int sum[MAXN];
    memset(sum,0,sizeof(sum));
    int i;
    for(i=1;i<=len;i++){
        sum[i]=a[i]+a[len+1-i]+sum[i];
        sum[i+1]+=sum[i]/md;
        sum[i]%=md;
    }
    if(sum[i]!=0){
        int j=1;
        len=i;
        while(i>0){
            a[j++]=sum[i--];
        }
    }else{
        i-=1;
        len=i;
        int j=1;
        while(i>0){
            a[j++]=sum[i--];
        }
    }
}

void solve(){
    int s=0;
    while(s<=30){
        ps();
        if(judge()){
            cout<<"STEP="<<s+1;
            exit(0);
        }
        s++;
    }
    cout<<"Impossible";
    exit(0);
}

int main(){
    init();
    solve();
    return 0;
}
