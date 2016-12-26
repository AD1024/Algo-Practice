#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[10];
int N;
void f(int t){
    if(t==1){
        a[t]=0;
        for(int i=1;i<N;++i){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[N]);
    }else if(t==2){
        if(a[1]==0){
            a[1]=1;
            for(int i=1;i<N;++i){
                printf("%d ",a[i]);
            }
            printf("%d\n",a[N]);
        }
        
        a[2]=1-a[2];
        for(int i=1;i<N;++i){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[N]);
        
        a[1]=0;
        for(int i=1;i<N;++i){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[N]);
    }else{
        if(!a[t-1]) f(t-1);
        for(int i=t-2;i>=1;--i){
            if(a[i]){
                f(i);
            }
        }
        a[t]=1-a[t];
        for(int i=1;i<N;++i){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[N]);
    }
}

int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        a[i]=1;
    }
    f(N);
    return 0;
}