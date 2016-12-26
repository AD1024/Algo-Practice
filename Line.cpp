#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int step[8][2]={{1,1},{1,0},{0,1},{1,-1}};
int cnt=0;
int g[1001][1001];
int m,n;
void dfs(int px,int py,int x,int y,int idx,int d){
    if(x>m || x<1 || y>n || y<1 || g[x][y]!=g[px][py]){
        return ;
    }
    if(idx==4){
        cnt++;
        return;
    }
    idx++;
    dfs(x,y,x+step[d][0],y+step[d][1],idx,d);
    return;
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    g[0][0]=-10000;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<4;k++){
                dfs(i,j,i,j,1,k);
            }
        }
    }
    cout<<cnt;
    return 0;
}
