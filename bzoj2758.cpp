#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const double INF = 1e20;
const int MAXN = 60010;
double cX;
struct P{
	double x,y;
	void init(double _,double __){
		x=_;
		y=__;
	}
};

//enum TYPE{0,1};
struct Pic{
	int type;
	double x,y;
	double r; //If is circle
	vector<P> U,D;	
	int V;
	pair<double,double> gen(){
		char op[4];
		gets(op);
		if(op[0]=='C'){
			type=0;
			scanf("%lf%lf%lf%d",&x,&y,&r,&V);
			return make_pair(x-r,x+r);
		}else{
			type=1;
			vector<P> v;
			double M=INF,I=-INF;
			int n;
			double xx,yy;
			int mid,iid;
			scanf("%d"&n);
			P p;
			for(int i=0;i<n;++i){
				scanf("%lf%lf",&xx,&yy);
				p.init(xx,yy);
				v.push_back(p);
				if(xx>I){
					I=xx;
					iid=i;
				}
				if(xx<M){
					M=xx;
					mid=i;
				}
			}
			if(iid<mid){
				for(int i=mid;i>=iid;--i){
					D.push_back(v[i]);
				}
				for(int i=mid;i<n;++i){
					U.push_back(v[i]);
				}
				for(int i=0;i<=iid;++i){
					U.push_back(v[i]);
				}
				scanf("%d",&V);
				return make_pair(M,I);
			}
			scanf("%d",&V);
			for(int i=mid;i<=iid;++i){
				U.push_back(v[i]);
			}
			for(int i=mid;i>=0;--i){
				D.push_back(v[i]);
			}
			for(int i=n-1;i>=iid;--i){
				D.push_back(v[i]);
			}
			return make_pair(M,I);
		}
	}


	double Overlap(P L,P R,double x){
		return L.y+(x-L.x)/(R.x-L.x)*(R.y-L.y);
	}
	
	double getArea(double xx,int d){
		if(!type){
			if(fabs(xx-(x-r))<=1e-3 || fabs(xx-(x+r))<=1e-3){
				return y;
			}
			double t,dd;
			t=r*r-(x-xx)*(x-xx);
			dd=sqrt(t);
			if(d){
				return y+dd;
			}else return y-d;
		}
		if(U[0].x==xx || xx==U.back().x){
			double MAX=-INF,MIN=INF;
			for(int i=0;i<U.size();++i){
				if(xx==U[i].x) MAX=max(MAX,U[i].y);
			}
			for(int i=0;i<D.size();++i){
				if(xx==D[i].x) MIN=min(MIN,D[i].y);
			}
			return MAX;
		}
		if(d){
			int s=Find(U,xx);
			return Overlap(U[s],U[s+1],xx);
		}else{
			int s=Find(D,xx);
			return Overlap(D[s],D[s+1],xx);
		}
	}

	int Find(vector<P> v,double x){
		for(int i=0;i<v.size();++i){
			if(v[i].x<=x && x<=v[i+1].x){
				return i;
			}
		}
	}
};


struct Query{
	int T;
	int U,V;	
};

struct SP{
	double x;
	int id,dir;
	
	SP(double _=0,int __=0,int ___=0){
		x=_;
		id=__;
		dir=___;
	}	
};

struct PAIR{
	int id;
	int dir,Fa;
	PAIR(double _,int __,int ___){
		id=_,dir=__;
		Fa=___;
	}

	friend bool operator <(const PAIR& a,const PAIR& b){
		if(a.id==b.id && a.dir!=2 && b.dir!=2) return a.dir<b.dir;
		double X=(a.dir==2?p[a.id].y:G[a.id].getArea(cX,a.dir));
		double Y=(b.dir==2?p[b.id]/y:G[b.id].getArea(cX,b.dir));
		return X<Y;
	}
};

Pic G[N];
SP Q[N];
int QUERY;
Query que[N];
P p[N];
set<PAIR> S;
PAIR L[N],R[N];
int n,m;
vector<int> g[N];
int d[N],son[N],fa[N];
bool CMP(SP a,SP b){
	if(fabs(a.x-b.x)<1e-8) return a.dir<b.dir;
	else return a.x<b.x;
}

inline void AddPt(int x,int y){
	g[x].push_back(y);
}

inline void INIT(){
	sort(Q+1,Q+QUERY+1,CMP);
	int K=n+QUERY+1;
	for(int i=1;i<=QUERY;++i){
		cX=Q[i].x;
		if(Q[i].dir==0){
			PAIR T=PAIR(Q[i].id,1,Q[i].id);
			S.insert(T);
			R[Q[i].id]=T;
			set<PAIR>::iterator it=S.find(T);
			++it;
			int FA=(it==S.end()?K:it->Fa);
			T=PAIR(Q[i].id,0,FA);
			S.insert(T);
			L[Q[i].id]=T;
			addPt(FA,Q[i].id);
		}else if(Q[i].dir==1){
			S.erase(L[Q[i].id]);
			S.erase(R[Q[i]].id);
		}else if(Q[i].dir==2){
			PAIR T=PAIR(Q[i].id,2,0);
			set<PAIR>::itertor it=S.lower_bound(T);
			if(it==S.end()){
				addPt(K,Q[i].id+n);
			}else add(it->Fa,Q[i].id+n);
		}
	}
}
int POOL[N];
int pCNT;
int *Tree[N];
int pos[N],root[N],listL[N],id;

void DFS_1(int u){
	son[u]=1;
	for(int i=0;i<g[u].size();++i){
		fa[g[u][i]]=u;
		DFS_1(g[u][i]);
		son[u]+=son[g[u][i]];
	}
}

void DFS_2(int u,int rt){
	id++;
	root[u]=rt;
	pos[u]=id;
	listL[rt]+=1;
	int start=0;
	for(int i=0;i<g[u].size();++i){
		if(son[g[u][i]]>son[start]) start=g[u][i];
	}
	if(!s) return;
	DFS_2(start,rt);
	for(int i=0;i<g[u].size();++i){
		int V=g[u][i];
		if(V!=start)
			DFS_2(V,V);
	}
}
inline int lowbit(int x){return x&(-x);}

inline void Insert(int rt,int x,int num){
	while(x<=listL[rt]){
		Tree[rt][x]^=num;
		x+=lowbit(x);
	}
}

inline void cal(int t){
	int rtPos=pos[root[t]];
	int x=pos[t]-rtPos+1;
	int rt=root[t];
	int ans=0;
	while(rt){
		while(x){
			ans^=Tree[rt][x];
			x+=lowbit(x);
		}
		t=fa[rt];
		rtpos=pos[root[t]];
		rt=root[t];
	}
}
