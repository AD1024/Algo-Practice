#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int a[4];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    if(a[1]+a[2]<=a[3]){
        cout<<"impossible";
    }else if(a[3]-a[1]>=a[2]){
        cout<<"impossible";
    }else if(a[1]==a[2] && a[2]==a[3]){
        cout<<"equilateral triangle";
    }else if(a[1]==a[2] || a[2]==a[3]){
        cout<<"isosceles triangle";
    }else{
        puts("normal triangle");
    }
    return 0;
}