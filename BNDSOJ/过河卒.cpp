#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long n,m,x,y;
long long dp[40][40];

inline void init(){
	dp[x][y] = 0;  
    dp[x+2][y+1] = 0;  
    dp[x+1][y+2] = 0;  
    if(x>=1)dp[x-1][y+2] = 0;  
    if(x>=2)dp[x-2][y+1] = 0;  
    if(x>=2&&y>=1)dp[x-2][y-1] = 0;  
    if(x>=1&&y>=2)dp[x-1][y-2] = 0;  
    if(y>=2)dp[x+1][y-2] = 0;  
    if(y>=1)dp[x+2][y-1] = 0;
}

int main(){
    cin>>n>>m;
    for(long long i=0;i<=n;i++)
        for(long long j=0;j<=m;j++)
            dp[i][j]=1;
    cin>>x>>y;
    init();
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<=m;j++){
            if(!dp[i][j]) continue;
            if(i==0 && j==0) continue;
            else if(i==0) 
            	dp[i][j]=dp[i][j-1];
            else if(j==0) 
            	dp[i][j]=dp[i-1][j];
            else 
            	dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][m];
    return 0;
}  
