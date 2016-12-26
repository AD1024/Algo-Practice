#include <iostream>
#include <cstdio>  
#include <cstring>  
#include <algorithm>  
using namespace std;  
  
char str[100010];  
  
inline bool cmp(int s1,int s2){  
    if(s1+1>s2-s1) return true;  
    else if(s1+1<s2-s1) return false;  
    int i,j;  
    for(i=0,j=s1+1;i<=s1;i++,j++)  {  
        if(str[i]>str[j]) return true;  
        else if(str[i]<str[j]) return false;  
    }  
    return true;  
}  
  
int main(){  
    char op;  
    int k,n;
    int ans=1;  
    scanf("%s",str);  
    n=strlen(str);
    for(int i=0;i<n;i++){  
        if(i+1<n&&str[i+1]=='0') 
            continue;  
        ans=1;  
        k=i;  
        for(int j=k+1;j<n;j++){  
            if(j+1<n && str[j+1]=='0') 
                continue;  
            if(cmp(k,j))  {  
                ans++;  
                k=j;
            }  
            else break;  
        }  
        if(k==n-1) break;  
    }  
    printf("%d\n",ans);  
    return 0;  
}