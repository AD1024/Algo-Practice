#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAXN = 120;
const int INF = 0xffffff;
ll g[MAXN][MAXN];
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=1;i<=110;i++){
        g[1][i]=1;
    }
    for(int i=1;i<=110;i++){
        g[i][1]=1;
    }
    for(int i=2;i<=m;i++){
        for(int j=2;j<=n;j++){
            g[i][j]=g[i-1][j]+g[i][j-1];
        }
    }
    printf("%lld",g[m][n]);
    return 0;
}
