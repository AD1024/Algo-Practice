#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ULL;

ULL g;
int N;
set<ULL> idx[2];
int x,y;
int randx,randy;
ULL col[510],row[510],dg[3];
int main(){
    cin>>N;
    if(N==1){cout<<1;return 0;}
    int j;
    for(int i=1;i<=N;++i){
        for(j=1;j<=N;++j){
            cin>>g;
            if(g==0){
                x=i;
                y=j;
            }else{
                randx=i;
                randy=j;
            }
            col[j]+=g;
            row[i]+=g;
            if(i==j){
                dg[0]+=g;
            }
            if(N-i+1==j){
                dg[1]+=g;
            }
        }
    }
    int colsum,rowsum;
    for(int i=1;i<=N;++i){
    	if(i!=x){idx[0].insert(row[i]);rowsum=row[i];}
    	if(i!=y){idx[1].insert(col[i]);colsum=col[i];}
    }
    if(idx[0].size()>1 || idx[1].size()>1){
        puts("-1");
        return 0;
    }
    if(rowsum!=colsum){
    	puts("-1");
    	return 0;
    }
    bool dia=false;
    if(x==y || N-x+1==y){
        dia=true;
    }else if(dg[0]!=dg[1]){
        puts("-1");
        return 0;
    }else if(rowsum!=dg[0]){
    	puts("-1");
    	return 0;
    }
    ULL ans;
    ans=row[randx]-row[x];
    if(ans<=0){
    	puts("-1");
    	return 0;
    }
    if(ans!=col[randy]-col[y]){
        puts("-1");
        return 0;
    }
    if(dia){
        if(x==y){
        	if(dg[1]-dg[0]!=ans){
        		puts("-1");
        		return 0;
        	}
        }else if(dg[0]-dg[1]!=ans){
        	puts("-1");
        	return 0;
        }
    }
    cout<<ans;
    return 0;
}