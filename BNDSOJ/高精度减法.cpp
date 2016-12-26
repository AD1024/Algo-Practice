#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

int a[10001];
int b[10001];
int la,lb;
int res[10001];
int lres;

inline bool gtt(string a,string b){
	if(a.size()!=b.size()) return a.size()>b.size();
	for(int i=0;i<a.size();++i){
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	cout<<0;
	exit(0);
}

inline void parse(string A,string B){
	reverse(A.begin(),A.end());
	reverse(B.begin(),B.end());
    la=A.size()-1;
    lb=B.size()-1;
    for(int i=la;i>=0;--i)
        a[i]=A[i]-'0';
    for(int i=lb;i>=0;--i)
        b[i]=B[i]-'0';
}

inline void calc(){
    int ax,bx,t;
    int cur=0;
    bool flag=false;
    for(int i=0;i<=la || i<=lb;++i){
        if(i>la) ax=0;
        else ax=a[i];
        if(i>lb) bx=0;
        else bx=b[i];
        if(flag){--ax;flag=false;}
        if(ax<bx){
            ax+=10;
            flag=true;
        }
        t=ax-bx;
        res[cur++]=t;
    }
    if(flag) cur-=2;
    else --cur;
    int i;
    for(i=cur;i>=0;i--){
    	if(res[i]!=0) break;
    }
    cur=i;
    lres=cur;
}

int main(){
    string A,B;
    cin>>A>>B;
    bool flag=false;
    if(gtt(B,A))
    {parse(B,A);flag=true;}
    else
        parse(A,B);
    calc();
    int end=0;
    if(flag){
        printf("-");
        for(int i=lres;i>=end;i--){
        	if(res[i]==0 && i==lres) continue;
            printf("%d",res[i]);
        }
    }else{
        for(int i=lres;i>=end;i--){
        	if(res[i]==0 && i==lres) continue;
            printf("%d",res[i]);
        }
    }
    return 0;
}