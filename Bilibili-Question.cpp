#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
using namespace std;

int tot=0;

int main(){
    int a,b;
    srand(time(0));
    int CASE=10;
    int type=0;
    int ans,t=0;
    while(CASE--){
        a=rand()%25;
        b=rand()%25;
        type=rand()%2;
        if(type>0){
            printf("%d+%d=",a,b);
            while(cin>>ans){
                if(ans==a+b && t==0){
                    tot+=10;
                    break;
                }else if(ans==a+b && t==1){
                    tot+=7;
                    break;
                }else if(ans==a+b && t==2){
                    tot+=5;
                    break;
                }else if(ans!=a+b){
                    cout<<"WA\n";
                }
                ++t;
                if(t>2) break;
            }
        }else{
            if(a<b){
                a^=b^=a^=b;
            }
            printf("%d-%d=",a,b);
            while(cin>>ans){
                if(ans==a-b && t==0){
                    tot+=10;
                    break;
                }else if(ans==a-b && t==1){
                    tot+=7;
                    break;
                }else if(ans==a-b && t==2){
                    tot+=5;
                    break;
                }else if(ans!=a-b){
                    cout<<"WA\n";
                }
                ++t;
                if(t>2) break;
            }
        }
    }
    if(tot>90)
        cout<<"GREAT"<<endl;
    else if(tot>=80)
        cout<<"GOOD"<<endl;
    else if(tot>=70)
        cout<<"PASS"<<endl;
    else cout<<"TRY AGAIN"<<endl;
    return 0;
}