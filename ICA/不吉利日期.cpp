#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;



inline int getDay(int m){
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
    else if(m == 2) return 28;
    else return 30;
}

struct Date{
    int month;
    int day;
    int week;
    Date(int wk){
        day = 1;
        month = 1;
        week = wk;
    }
    Date(){}

    bool finish(){
        return month>12;
    }

    void nextMonth(){
        month++;
    }

    void nextDay(){
        if(day+1>getDay(month)){
            day = 1;
            nextMonth();
        }else{
            day++;
        }
        week = week + 1 > 7 ? 1:week+1;
    }
};

int main(){
    int wk;cin>>wk;
    Date d = Date(wk);
    vector<int> ans;
    while(!d.finish()){
        if(d.day == 13 && d.week == 5){
            ans.push_back(d.month);
        }
        d.nextDay();
    }
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<endl;
    }
    return 0;
}