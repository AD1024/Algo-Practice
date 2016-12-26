#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    int a[15];
    for(int i=1;i<=12;i++){
        cin>>a[i];
    }
    int save = 0;
    int mon=0;
    for(int i=1;i<=12;i++){
        mon+=300;
        if(mon<a[i]){
            cout<<-i;
            return 0;
        }
        while(mon-100>=a[i]){
            mon-=100;
            save+=100;
        }
        mon-=a[i];
    }
    cout<<mon+save*1.2;
    return 0;
}
