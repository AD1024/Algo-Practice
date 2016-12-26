#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 5010;
struct Person{
    int id;
    int score;
}List[MAXN];

int readInt(){
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n'){
        a *= 10;
        a += ch - '0';
    }
    return a;
}

bool cmp(Person p1,Person p2){
    return p1.score>p2.score;
}

bool cmp1(Person p1,Person p2){
    if(p1.score==p2.score){
        return p1.id<p2.id;
    }else{
        return p1.score>p2.score;
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int id,score;
        id = readInt();
        score = readInt();
        Person p;
        p.id=id;
        p.score=score;
        List[i]=p;
    }
    sort(List,List+m,cmp);
    int pop = n*1.5;
    int minScore=List[pop-1].score;
    int cur = 0,cnt=0;
    while (List[cur].score>=minScore) {
        cnt+=1;
        cur++;
    }
    cout<<minScore<<" "<<cnt<<endl;
    Person ans[MAXN];
    for(int i=0;i<cnt;i++){
        ans[i]=List[i];
    }
    sort(ans,ans+cnt,cmp1);
    for(int i=0;i<cnt;i++){
        cout<<ans[i].id<<" "<<ans[i].score;
        cout<<endl;
    }
    return 0;
}
