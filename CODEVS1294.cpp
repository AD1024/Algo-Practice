#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;cin>>n;
    int a[15];
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    do{
        for(int i=1;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
    }while(next_permutation(a+1,a+n+1));
    return 0;
}
