#include <iostream>  
#include <cstdio>  
#include <cmath>  
#include <cstdlib>  
using namespace std;  
  
int main(){  
    int n, i, j;  
    cin>>n;  
    printf("%d\n",(n*n)/2+n%2);  
    for(i=1;i<=n;i++){  
        for(j=1;j<=n;j++){  
            if (i%2==1&&j%2==1||i%2==0&&j%2==0){  
                printf("C");  
            }  
            else{  
                printf(".");  
            }  
        }  
        puts("");
    }  
    return 0;  
}