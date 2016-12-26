#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int in[110];

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int N;
    while(cin>>N && N){
        memset(in,0,sizeof(in));
        for(int i=2;i<=N;++i){
            cin>>in[i];
        }
        in[1]=N-1;
        bool ans=true;
        sort(in+1,in+N+1,cmp);
        int loopCnt=0;
        for(int i=1;;){
            if(loopCnt==N) break;
            loopCnt++;
            if(in[i]==0) continue;
            int k=in[i];
            for(int j=i+1;j<=i+k;++j){
                if(in[j]>0){
                    in[j]--;
                    in[i]--;
                }
            }
            if(in[i]!=0){
                cout<<"Lie absolutely\n";
                ans=false;
                break;
            }
            sort(in+1,in+N+1,cmp);
        }
        if(ans){
            cout<<"Maybe truth\n";
        }
    }
}