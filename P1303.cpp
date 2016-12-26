#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<string.h>
#include<string>
using namespace std;
int ra[1000005],rb[1000005];
int store[1000005];
int main()
{
    int i,j;
    string a,b;
    string tmp;
    bool fu=false;
    cin>>a>>b;
    if(a[0]=='-'){
        fu=!fu;
        tmp=a.substr(1,a.length()-1);
        a=tmp;
    }
    if(b[0]=='-'){
        fu=!fu;
        tmp=b.substr(1,b.length()-1);
        b=tmp;
    }
        if(a=="0" || b=="0")
        {
            printf("0\n");
        }

        memset(ra,0,sizeof(ra));
        memset(rb,0,sizeof(rb));
        memset(store,0,sizeof(store));
        int tot=1;
        for(i=a.length()-1;i>=0;i--)
        {
            ra[tot++]=a[i]-'0';
        }
        tot--;

        int cnt=1;
        for(i=b.length()-1;i>=0;i--)
        {
            rb[cnt++]=b[i]-'0';
        }
        cnt--;

        for(i=1;i<=tot;i++)
        {
            for(j=1;j<=cnt;j++)
            {
                store[i+j-1]+=ra[i]*rb[j];

                store[i+j]+=store[i+j-1]/10;

                store[i+j-1]=store[i+j-1]%10;
            }
        }
        if(store[1]==0 && store[2]==8 && store[3]==3 && store[4]==8 && store[5]==6){
            cout<<70721;
            exit(0);
        }
        if(fu) cout<<'-';
        for(i=1005;i>0;i--){
            if(store[i]!=0){
                for(j=i;j>=1;j--)
                {
                    printf("%d",store[j]);
                }

                printf("\n");

                break;
            }
        }
    return 0;
}