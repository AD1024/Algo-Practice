#include <iostream>
using namespace std;

int a[200];
int b[200];
int A,B;
int lena,lenb;
inline void parse(){
    int cur=0;
    while(A){
        a[++cur]=A%10;
        A/=10;
    }
    lena=cur;
    cur=0;
    while(B){
        b[++cur]=B%10;
        B/=10;
    }
    lenb=cur;
}

int main(){
    while(cin>>A>>B){
    	if(A==B && A==0) break;
        lena=lenb=0;
        parse();
        int addb,adda,t;
        int cnt=0;
        bool flag=false;
        for(int i=1;i<=lena || i<=lenb;i++){
            if(i>lenb) addb=0;
            else addb=b[i];
            if(i>lena) adda=0;
            else adda=a[i];
            t=adda+addb;
            if(flag){
                t+=1;
                flag=false;
            }
            if(t>=10){
                cnt++;
                flag=true;
            }
        }
        if(cnt==0) cout<<"No carry operation."<<endl;
        else if(cnt==1) cout<<"1 carry operation."<<endl;
        else cout<<cnt<<" carry operations."<<endl;
    }
    return 0;
}