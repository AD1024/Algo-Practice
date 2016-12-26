#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
//1542300647@qq.com
#define rep(i) for(i=0;i<3;++i)

int a[10]={1,2,3,4,5,6,7,8,9};
const int Pow10[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

int main(){
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
    int sum;
    bool flag=false;
    cin>>sum;
    int ans=0;
    int op[10];
    memset(op,0,sizeof(op));
    int res;
    rep(op[2]){
        rep(op[3]){
            rep(op[4]){
                rep(op[5]){
                    rep(op[6]){
                        rep(op[7]){
                            rep(op[8]){
                                rep(op[9]){
                                    res=0;
                                    for(int kk=9;kk>=2;--kk){
                                        if(op[kk]==0){
                                            res+=kk;
                                        }else if(op[kk]==1){
                                            res-=kk;
                                        }else{
                                            int cur=0;
                                            int num=0;
                                            while(op[kk]==2){
                                                num+=kk*Pow10[cur++];
                                                --kk;
                                            }
                                            num+=kk*Pow10[cur];
                                            //printf("%d ",num);
                                            if(op[kk]==0){
                                                res+=num;
                                            }else if(op[kk]==1){
                                                res-=num;
                                            }
                                            
                                        }
                                    }
                                    if(op[2]!=2){
                                    	res++;
                                    }
                                    //puts("");
                                    //cout<<"res:"<<res<<'\n';
                                    if(res==sum){
                                        ans++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}