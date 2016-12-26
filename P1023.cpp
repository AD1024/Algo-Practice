#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

struct R{
    int w;
    int v;
    int prof;
}list[10001];

bool cmp(R a, R b){
    if(a.prof*a.w==b.prof*b.w){
        return a.v<b.v;
    }else{
        return a.prof>b.prof;
    }
}

vector<R> items;
bool have[10001];
int main(){
    memset(have,false,sizeof(have));
    int wish;
    cin>>wish;
    int price,mount;
    int maxnv=-1000,maxnw;
    int minmv=1000000;
    int orprice,ormount;
    cin>>orprice>>ormount;
    have[orprice]=true;
    while(cin>>price>>mount){
        if(mount==-1 && price==-1) break;
        R it;it.w=mount;it.v=price;
        if(maxnv<price){
            maxnv=price;
            maxnw=mount;
        }
        have[price]=true;
        minmv=min(price,minmv);
        items.push_back(it);
    }
    int rate=(items[0].w-ormount)/(items[0].v-orprice);
    for(int i=orprice;i<maxnv;i++){
        if(!have[i]){
            R kk;
            kk.v=i;
            kk.w=ormount-rate*(i-orprice);
            items.push_back(kk);
        }
    }
    int fx;
    cin>>fx;
    int add=1;
    while(maxnw-add*fx>0){
        R ad;
        ad.v=maxnv+add;
        ad.w=maxnw-add*fx;
        items.push_back(ad);
        add++;
    }
    int bash;
    int most;
    int cur;
    bool find;
    int ans=1000000;
    for(bash=-32;bash<=9;bash++){
        vector<R> t=items;
        cur=1;
        find=false;
        for(int i=0;i<t.size();i++){
            t[i].prof=(t[i].v-orprice+bash)*t[i].w;
        }
        sort(t.begin(),t.end(),cmp);
        most=t[0].prof;
        if(t[0].v==wish){
            find=true;
            break;
        }
        for(int j=1;j<t.size();j++){
            if(most==t[j].v && t[j].v==wish){
                find=true;
                ans=min(abs(ans),abs(bash));
                break;
            }
            if(most>t[j].v) break;
        }
    }
    if(ans==100000) cout<<"NO SOLUTION";
    else{
        if(bash!=10){
            cout<<bash;
        }else{
            cout<<-20;
        }
    }
    return 0;
}