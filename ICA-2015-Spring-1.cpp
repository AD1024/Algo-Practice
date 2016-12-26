#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    char str[1001];
    scanf("%s",str);
    int len = strlen(str);
    int cur;
    int ans[1001][2];
    int i;
    int count=0;
    for(i=0;i<len;){
        char t= str[i];
        cur=i;
        int cnt=0;
        ans[count][0]=str[i]-'0';
        while(str[cur]==t){
            cnt+=1;
            cur+=1;
        }
        ans[count][1]=cnt;
        i=cur;
        count+=1;
    }
    for(int j=0;j<count;j++){
        cout<<ans[j][1]<<ans[j][0];
    }
    return 0;
}
