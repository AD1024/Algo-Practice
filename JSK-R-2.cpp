#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

const int INF = 0xffffff;

int wifi[32][32];
int u[32][32],temp;
int main(){
    int n,m,xx,ans=INF,t,a,b,c,d,e;
    scanf("%d%d%d",&n,&m,&xx);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&u[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&wifi[i][j]);
        }
    }
    int amount=n*m;
    if(amount==1){
        for(int i=-xx;i<=xx;i++){
            t=(abs(i+2)^u[1][1])*wifi[1][1];
            if(t<ans)ans=t;
        }
        printf("%d\n",ans);
    }
    else if(amount==2){
        if(n==1){
            for(int i=-xx;i<=xx;i++){
                for(int j=-xx;j<=xx;j++){
                    t=(abs(i+2)^u[1][1])*wifi[1][1]+(abs(j+3)^u[1][2])*wifi[1][2]+abs(i+j);
                    if(t<ans)ans=t;
                }
            }
        }
        else{
            for(int i=-xx;i<=xx;i++){
                for(int j=-xx;j<=xx;j++){
                    t=(abs(i+2)^u[1][1])*wifi[1][1]+(abs(j+3)^u[2][1])*wifi[2][1]+abs(i+j);
                    if(t<ans)ans=t;
                }
            }
            
        }
        printf("%d\n",ans);
    }
    else if(amount==3){
        for(int i=-xx;i<=xx;i++){
            for(int j=-xx;j<=xx;j++){
                for(int k=-xx;k<=xx;k++){
                    t=(abs(i+2)^u[1][1])*wifi[1][1]+(abs(j+3)^u[1][2])*wifi[1][2]+(abs(k+4)^u[1][3])*wifi[1][3]+abs(i+j)+abs(j+k);
                    ans=min(ans,t);
                }
            }
        }
        printf("%d\n",ans);
    }
    else if(amount==4){
        for(int i=-xx;i<=xx;i++){
            for(int j=-xx;j<=xx;j++){
                for(int k=-xx;k<=xx;k++){
                    for(int z=-xx;z<=xx;z++){
                        t=(abs(i+2)^u[1][1])*wifi[1][1]+(abs(j+3)^u[1][2])*wifi[1][2]+(abs(k+3)^u[2][1])*wifi[2][1]+(abs(z+4)^u[2][2])*wifi[2][2]+abs(i+j)+abs(i+k)+abs(k+z)+abs(j+z);
                        if(t<ans)ans=t;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    else if(amount==6){
        int l1,l2,l3,l4,l5,l6;
        l1=xx;
        l2=xx;
        l3=xx;
        l4=xx;
        l5=xx;
        l6=xx;
        t=0;
        for(int i=-l1;i<=l1;i++){
            t=0;
            temp=(abs(i+2)^u[1][1])*wifi[1][1];
            if(temp+t>=ans)continue;
            else{
                t+=temp;
                a=t;
            }
            for(int j=-l2;j<=l2;j++){
                t=a;
                temp=(abs(j+3)^u[1][2])*wifi[1][2];
                if(t+temp>=ans)continue;
                else{
                    t+=temp;
                    b=t;
                }
                for(int k=-l3;k<=l3;k++){
                    t=b;
                    temp=(abs(k+4)^u[1][3])*wifi[1][3];
                    if(temp+t>=ans)continue;
                    else{
                        t+=temp;
                        c=t;
                    }
                    for(int z=-l4;z<=l4;z++){
                        t=c;
                        temp=(abs(z+3)^u[2][1])*wifi[2][1];
                        if(temp+t>=ans)continue;
                        else{
                            t+=temp;
                            d=t;
                        }
                        for(int p=-l5;p<=l5;p++){
                            t=d;
                            temp=(abs(p+4)^u[2][2])*wifi[2][2];
                            if(temp+t>=ans)continue;
                            else {
                                t+=temp;
                                e=t;
                            }
                            for(int q=-l6;q<=l6;q++){
                                t=e;
                                t+=(abs(q+5)^u[2][3])*wifi[2][3]+abs(i+j)+abs(j+k)+abs(z+p)+abs(p+q)+abs(i+z)+abs(j+p)+abs(k+q);
                                if(t<ans)
                                    ans=t;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
    else printf("0\n");
    return 0;
}