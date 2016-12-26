#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//#define OJ

struct Stuff{
    string name;
    int rank;
    bool operator <(const Stuff b){
        if(rank==b.rank){
            return name[0]<b.name[0];
        }else return rank<b.rank;
    }
};

struct Item{
    vector<Stuff> a;
    int cnt;
    Item(){
        cnt=0;
    }
    void Add(Stuff x){a.push_back(x);}
    string& operator [](const int x){
        return a[x].name;
    }
};

struct Bag{
    int type;
    int price;
    Item item;
};

int cur=0;;
vector<Bag> bags[5];
int N;
int v[1010];

char opp[1010];

bool cmp(Stuff a,Stuff b){
	if(a.name==b.name) return a.rank<b.rank;
    if(a.rank==b.rank){
        int i=0;
        while(a.name[i]!=b.name[i] && i<min(a.name.length(),b.name.length())) ++i;
        return a.name[i]<b.name[i];
    }else return a.rank<b.rank;
}

bool cmp1(Bag a,Bag b){
    return a.price<b.price;
}

inline bool isFront(char x){
    return x=='(' || x=='{' || x=='<' || x=='[';
}
inline bool isRear(char x){
    return x==')' || x=='}' || x=='>' || x==']';
}

inline bool Same(Bag a,Bag b){
    Item t1,t2;
    if(t1.a.size()!=t2.a.size()) return false;
    t1=a.item;t2=b.item;
    for(int i=0;i<t1.a.size();++i){
        if(t1[i]!=t2[i]) return false;
    }
    return true;
}

inline bool ok(string k){
    if(!isFront(k[0])) return false;
    else{
        stack<char> S;
        for(int i=0;i<k.length();++i){
            if(isFront(k[i])){
                S.push(k[i]);
            }else{
                if(k[i]==')'){
                    if(S.top()!='(') return false;
                    else S.pop();
                }else if(k[i]=='}'){
                    if(S.top()!='{') return false;
                    else S.pop();
                }else if(k[i]==']'){
                    if(S.top()!='[') return false;
                    else S.pop();
                }else if(k[i]=='>'){
                    if(S.top()!='<') return false;
                    else S.pop();
                }
                if(isRear(k[i])){
                    if(i<k.length()-1){
                        if(isFront(k[i+1])) return false;
                    }
                }
            }
            if(k[i]==','){
                if(i+2==k.length() || isRear(k[i+1])) return false;
                if(k[i-1]==',' || k[i+1]==',') return false;
                continue;
            }
            if(!isalpha(k[i]) && !isFront(k[i]) && !isRear(k[i])){
                return false;
            }
        }
    }
    return true;
}

void getStuffs(int dep,int& start,string k,Item& it){
    Stuff stuff;
    stuff.rank=dep;
    int i=start;stuff.name+=k[i];
    for(start=start+1;k[start]!=opp[k[i]];++start){
        if(isRear(k[start]) && k[start]!=opp[k[i]]) continue;
        if(k[start]==','){
            if(stuff.name.length()!=1)it.Add(stuff);
            stuff.name=k[i];
            continue;
        }
        if(k[start+1]==opp[k[i]]){
            stuff.name+=k[start];
            it.Add(stuff);
            break;
        }
        if(isFront(k[start])){
            stuff.name=k[start];
            it.Add(stuff);
            getStuffs(dep+1,start,k,it);
            stuff.name=k[i];
        }else{
            stuff.name+=k[start];
        }
    }
}

inline void parseBag(string k,int value){
    if(ok(k)){
        //puts("OK");
        Bag b;
        switch(k[0]){
            case '(':
                b.type=1;
                break;
            case '[':
                b.type=2;
                break;
            case '{':
                b.type=3;
                break;
            case '<':
                b.type=4;
                break;
        }
        Item it;
        getStuffs(1,it.cnt,k,it);
        sort(it.a.begin(),it.a.end(),cmp);
        b.item=it;
        b.price=value;
        int typed=b.type;
        for(int i=0;i<bags[typed].size();++i){
            if(Same(bags[typed][i],b)){
                if(b.price<bags[typed][i].price){
                    bags[typed][i]=b;
                    return;
                }else return;
            }
        }
        bags[b.type].push_back(b);
    }
}

int main(){
#ifdef OJ
    freopen("bag.in","r",stdin);
    freopen("bag.out","w",stdout);
#endif
    opp['(']=')';opp[')']='(';
    opp['[']=']';opp[']']='[';
    opp['{']='}';opp['}']='{';
    opp['<']='>';opp['>']='<';
    
    string k;
    scanf("%d",&N);
    for(int i=1;i<=N;++i){
        scanf("%d",&v[i]);
    }
    for(int i=1;i<=N;++i){
        cin>>k;
        parseBag(k,v[i]);
    }
    int ans=0;
    for(int i=1;i<=4;++i){
        sort(bags[i].begin(),bags[i].end(),cmp1);
        for(int j=0;j<bags[i].size();++j){
            ans+=bags[i][j].price;
        }
    }
    printf("%d",ans);
#ifdef OJ
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}