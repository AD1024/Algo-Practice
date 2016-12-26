#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define MAXN 500
#define MAAX 50
int queue[MAXN];
int A[MAAX][MAAX];
int T[MAAX][MAAX];
int used[MAAX];
int ok[MAAX];
char W[MAXN][MAXN];
int i,j;
int M,N;
int t;

inline int WORK(){
    int ans=0;
    int k;
    for(i=0;i<M*N;i++){
        t=queue[i];
        j=ok[t]-1;
        do{
            j++;
            for(k=0;k<T[t][used[t]];k++){
                if(W[A[t][used[t]]][j+k]){
                    j=k+j;
                    break;
                }
            }
        }while(W[A[t][used[t]]][j]);
        memset(W[A[t][used[t]]]+j,t+1,T[t][used[t]]);
        if(ans<j+T[t][used[t]]){
            ans=j+T[t][used[t]];
        }
        ok[t]=j+k;
        used[t]++;
    }
    return ans;
}

inline void init(){
    scanf("%d%d",&M,&N);
    for(i=0;i<M*N;i++){
        scanf("%d",&queue[i]);
        queue[i]--;
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&A[i][j]);
            A[i][j]--;
        }
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&T[i][j]);
        }
    }
}

int main(){
    init();
    printf("%d",WORK());
    return 0;
}