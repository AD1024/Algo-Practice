#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int t=1;
int n=0,k;
int xh[1000];
int num;
char s[1000];
bool flag,flag2;

struct BigInt{
    int v[1000];
    int s;
    int& operator [](int x){
        return v[x];
    }
}a,b,c,bak,ans,nn;

BigInt Mul(const BigInt a,const BigInt b){
    int i,j,x=0;
    if(a.s==1 && a.v[0]==0)return a;
    if(b.s==1 && b.v[0]==0)return b;
    BigInt c;memset(c.v,0,sizeof(c.v));
    for(i=0;i<=100 && i<a.s;i++){
        for(j=0;j<=100 && j<b.s;j++){
            c[i+j]+=(a.v[i])*(b.v[j]);
            c[i+j+1]+=c[i+j]/10;
            c[i+j]%=10;
        }
        c.s=i+j;
        if(c[i+j]!=0)c.s++;
    }
    if(c.s>k){
        c.s=k+1;
    }
    return c;
}

int main(){
    int i,j;
    scanf("%s%d",s,&k);
    c.s=strlen(s);
    ans.v[0]=1;
    ans.s=1;
    for(i=0;i<c.s;i++) c[i]=s[c.s-i-1]-'0';
    bak=c;
    a=c;
    b=c;
    for(int i=0;i<k;i++){
        num=0;
        b=bak;
        do{
            b=Mul(a,b);
            num++;
        }while(num<10 && b[i]!=bak[i]);
        if(bak[i]!=b[i]){
            printf("-1");
            return 0;
        }
        b=a;
        for(j=0;j<num-1;j++)
            a=Mul(a,b);
        
        nn.s=1;
        nn[0]=num;
        ans=Mul(ans,nn);
    }
    i=100;
    while(ans[i]==0){
        i--;
    }
    while(i>=0){
        printf("%d",ans[i]);--i;
    }
    return 0;
}