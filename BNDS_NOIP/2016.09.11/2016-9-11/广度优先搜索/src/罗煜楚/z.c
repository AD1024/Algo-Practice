#include <stdio.h>
#include <string.h>
/*
         1¡ü
     2 ¡û    ¡ú3
         4¡ý



*/
int s[10000000][10]={0},sj=1;
int c[100000]={0},l[100000]={0};
char ag[876543220]={'\0'};
int answer[10]={0};
int head=0,t=0;
int win[100000]={0};
int anszz=0;


int check(int i,int p)
{
    int j,m,n=0;
    if (i==1)
       if (p>=4)
          n=1; 
    if (i==2)
       if (p%3!=1)
          n=1;
    if (i==3)
       if (p%3!=0)
          n=1;
    if (i==4)
       if (p<=6)
          n=1;
    
    return n;
}



void move(int i,int time,int p)
{
     int j,m,n;
     sj++;
     if (i==1)
     {
        for (i=1;i<=9;i++)
        {
			s[sj][i]=s[time][i];
		}
		m=s[sj][p];
		s[sj][p]=s[sj][p-3];
		s[sj][p-3]=m;
		c[sj]=p-3;
		win[sj]=win[time]+1;
     }
     if (i==2)
     {
        for (i=1;i<=9;i++)
        {
			s[sj][i]=s[time][i];
		}
		m=s[sj][p];
		s[sj][p]=s[sj][p-1];
		s[sj][p-1]=m;
		c[sj]=p-1;
		win[sj]=win[time]+1;
     }
     if (i==3)
     {
        for (i=1;i<=9;i++)
        {
			s[sj][i]=s[time][i];
		}
		m=s[sj][p];
		s[sj][p]=s[sj][p+1];
		s[sj][p+1]=m;
		c[sj]=p+1;
		win[sj]=win[time]+1;
     }
     if (i==4)
     {
        for (i=1;i<=9;i++)
        {
			s[sj][i]=s[time][i];
		}
		m=s[sj][p];
		s[sj][p]=s[sj][p+3];
		s[sj][p+3]=m;
		c[sj]=p+3;
		win[sj]=win[time]+1;
     }
     
}

int f()
{
     int i,j,k=0,n,time;
     if(win[sj]<30)
     {
     time=l[head];
     head++;
     for (i=1;i<=4;i++,k=0)
     {
         if (check(i,c[time]))
         {
            move(i,time,c[time]);
            for (j=1;j<=9;j++)
            {
				k*=10;
				k+=s[sj][j];
			}
			if (ag[k]=='w')
			{
				return sj;
			}
			if (ag[k]==0)
			{
				ag[k]=1;
				l[t]=sj;
				t++;
			}
         }
     }
     }
     else printf("error\n");
     
     return 0;
}

int main()
{
    int i,j,k,pig=0,ans=0;
    freopen("z.in","r",stdin);
    freopen("z.out","w",stdout);
    for (i=1;i<=9;i++)
    {
        scanf("%d",&s[1][i]);
    }
    for (i=1;i<=9;i++)
    {
        scanf("%d",&answer[i]);
    }
    k=0;
    for (j=1;j<=9;j++)
        {
			k*=10;
			k+=answer[j];
		}
	ag[k]='w';
    
    for (i=1;i<=9;i++)
    {
        if (s[1][i]==0)
        c[1]=i;
    }
    l[t]=1;
    ++t;
    
    win[1]=0;
    
    for (;pig==0;)
    {
    pig=f();
    printf("%d ",pig);
	}
    
    printf("%d ",pig);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
