#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
#define MID(x,y) (x+y)>>1
inline int read(){    
    char ch;  
    bool flag=false;  
    int a=0;    
    while(!((((ch=getchar())>='0')&&(ch<='9'))||(ch == '-')));    
    if(ch!='-'){  
        a*=10;  
        a+=ch-'0';    
    }
    else{  
        flag=true;  
    }  
    while(((ch=getchar())>='0')&&(ch<='9')){  
        a*=10;  
        a+=ch-'0';  
    }     
    if(flag){  
        a=-a;  
    }  
    return a;    
}    
void write(int a){    
    if(a < 0)  
    {  
        putchar('-');  
        a = -a;  
    }  
    if(a >= 10){  
        write(a/10);  
    }         
    putchar(a%10+'0');    
}

int M,N;
int a[300001];
int b[300001];
map<int, vector<int> > loc;
int t[300001];
int dp[300001];
int k;

int solve(){
    int i,k,l,r,mid,j;
    int z;
    int ans;
    for(i=0,k=0;a[i];++i){
    	z=a[i];
    	for(j=0;j<loc[a[i]].size();++j,++k){
    		t[k]=loc[z][j];
    	}
    }
    dp[1]=t[0];
    dp[0]=-1;
    for(i=1,ans=1;i<k;++i){
    	l=0;r=ans;
    	while(l<=r){
    		mid=MID(l,r);
    		if(dp[mid]>=t[i]){
    			r=mid-1;
    		}else l=mid+1;
    	}
    	if(r==ans){
    		ans++;
    		dp[r+1]=t[i];
    	}else if(dp[r+1]>t[i]){
    		dp[r+1]=t[i];
    	}
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(false);  
	N=read();M=read();
	for(int i=0;i<N;++i){
		a[i]=read();
	}
	for(int i=0;i<M;++i){
		b[i]=read();
	}
	for(int i=M-1;i>=0;--i)
        loc[b[i]].push_back(i);
	write(solve());
	return 0;
}