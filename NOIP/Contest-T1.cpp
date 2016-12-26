#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

#define MAXN 100
int H,N;
int a[MAXN][MAXN];
double t[MAXN][MAXN];
int c[MAXN][MAXN];

#define MAX(a,b) a>b?a:b

int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
    cin>>N>>H;
    int k,sum;
    sum=0;
    double ans=0.0;
    int cnt=0;
    int lsum;
    if(N==1){
    	double kk=0.0;
    	double s=0.0;
    	double k;
    	for(int i=1;i<=H;++i){
    		cin>>k;
    		s+=k;
    		kk=MAX(kk,s/i);
    	}
    	printf("%.4f",kk);
    	return 0;
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=H;++j){
            c[i][j]=1;
            cin>>k;
            a[i][j]=a[i][j-1]+k;
            c[i][j]+=c[i][j-1];
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=H;++j){
            int posx,posy;
            posx=posy=0;
            for(int k=1;k<=H;++k){
                if(t[i][j]<((double)a[i][j]+(double)a[i-1][k])/((double)c[i][j]+(double)c[i-1][k])){
                    t[i][j]=((double)a[i][j]+(double)a[i-1][k])/((double)c[i][j]+(double)c[i-1][k]);
                    //c[i][j]+=c[i-1][k];
                    posx=i-1;posy=k;
                }
            }
            a[i][j]+=a[posx][posy];
            c[i][j]+=c[posx][posy];
        }
    }
    for(int i=1;i<=H;++i){
        ans=MAX(ans,t[N][i]);
    }
    printf("%.4f",ans);
    return 0;
}