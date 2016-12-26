#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

long long f[305][305][305]={0};

int main(){
    int a,b,c;
    int vp,vq;
    int i,j,k;
    int maxn=0;
    long long ans=0;
    
    cin >> a >> b >> c;
    cin >> vp >> vq;
    
    maxn=max(a,b);
    maxn=max(maxn,c);
    
    for(i=2;i<=maxn;i++){
        for(j=1;j<=maxn;j++){
            for(k=0;k<=maxn;k++){
                f[i][j][k]=f[i-2][j-1][k]+vp;
            }
        }
    }
    
    for(i=1;i<=maxn;i++){
        for(j=1;j<=maxn;j++){
            for(k=1;k<=maxn;k++){
                f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]+vq);
            }
        }
    }
    cout << f[a][b][c];
    
    return 0;
}