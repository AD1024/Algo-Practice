#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int Pow[]={1,10,100,1000,10000};
inline bool ok(int x){
	return x%400==0 || (x%4==0 && x%100!=0);
}

inline int get(int y,int m){
	if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) return 31;
	if(m==2){
		return ok(y)?29:28;
	}else return 30;
}

inline bool val(int y,int m,int d){
    string Y,M,D;
    while(y){
        Y=char((y%10+'0'))+Y;
        y/=10;
    }
    while(m){
        M=char((m%10+'0'))+M;
        m/=10;
    }
    if(M.size()<2) M='0'+M;
    while(d){
        D=char((d%10+'0'))+D;
        d/=10;
    }
    if(D.length()<2) D='0'+D;
    string date=Y+M+D;
    // scout<<date<<endl;
    int len = date.length();
    for(int i=0;i<=len>>1;++i){
        if(date[i]!=date[len-i-1]) return false;
    }
    return true;
}

inline int parse(string x){
	int cur=0;
	int ret=0;
	for(int i=x.length()-1;i>=0;--i){
		ret+=(x[i]-'0')*Pow[cur++];
	}
	return ret;
}

int yy,m1,d1;
int y2,m2,d2;
int y,m,d;

int main(){
	string start,end;
	cin>>start>>end;
	yy=parse(start.substr(0,4));
	m1=parse(start.substr(4,2));
	d1=parse(start.substr(6,2));

	y2=parse(end.substr(0,4));
	m2=parse(end.substr(4,2));
	d2=parse(end.substr(6,2));
	// cout<<yy<<" "<<m1<<" "<<d1<<endl;
	// cout<<y2<<" "<<m2<<" "<<d2<<endl;
	if(yy==y2){
		if(d1==d2 && m1==m2){
			if(val(yy,m1,d1)){
				puts("1");return 0;
			}
		}
	}
	int ans=0;
	for(int i=yy;i<=y2;++i){
		d=i/1000+((i/100)%10)*10;
		m=(i/10)%10+(i%10)*10;
		// cout<<d<<" "<<m<<endl;
		if(m>12 || m<1) continue;
		if(d<1 || d>get(i,m)) continue;
		if(yy==y2){
			if(m<=m2 && d<=d2 && m>=m1 && d>=d1 ){
				puts("1");return 0;
			}
			puts("0");return 0;
		}
		if(i==yy){
			if(m>=m1 && d>=d1) ++ans;
		}else if(i==y2){
			if(m<=m2 && d<=d2) ++ans;
		}else{
			++ans;
		}
	}
	cout<<ans;
	return 0;
}