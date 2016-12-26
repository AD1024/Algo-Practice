#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct map
{
   char game[3][3];
   int step;
};

struct map line[100001];int f=0,r=0;
struct map dream;
struct map doe;
char flag[362881]={'\0'};
char way[4][3]={'\0'};
char zero_x,zero_y;
char *cc,*ch;
struct map newr;
int ans=-1;

int check()
{
     int i;
     
     cc=&(newr.game[0][0]);
     ch=&(dream.game[0][0]);
     
     for(i=0;i<9;i++)
     {
       if(cc[i]!=ch[i])return 0; 
     }
     
     
     
     return 1;
     
}
int d(int a);
int rediscover(int y,int x)
{
    int i,j,k,num=0;
    
    cc=&(newr.game[0][0]);
    
    
    
    for(i=0;i<9;i++)
   { 
     k=cc[i];               
      
      for(j=i-1;j>=0;j--)
       if(cc[j]<cc[i]) k--;     
               
                    
      num+=k*d(8-i);
    }
    
    if(flag[num]==0)
      {flag[num]=1;return 0;}
    else
       return 1;  
    
    
}

void scan();
void out();void in();
void make_way();
void BFS()
{
     int i;
     
     while(f!=r)
    { 
       out();make_way();
       
       for(i=0;i<4;i++)
         if(way[i][0]==1)
         {
            int new_y=zero_y+way[i][2],new_x=zero_x+way[i][1];
            
            newr=doe;
            newr.game[zero_y][zero_x]=newr.game[new_y][new_x];
            newr.game[new_y][new_x]=0;
            newr.step++;
            
            
            if(check())
               {f=r;ans=newr.step;break;}
            if(!rediscover(new_y,new_x))
              in();
         }
     
     }
     
     
}

int main()
{
    int i;
    char str[4][6]={"left","up","right","down"};
    
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    way[0][1]=-1,way[0][2]=0;
    way[1][1]=0,way[1][2]=-1;
    way[2][1]=1,way[2][2]=0;
    way[3][1]=0,way[3][2]=1;
    
    
    scan();
    
    newr=line[0];
    if(check())
      printf("0");
    else  
    {
     make_way();     
     rediscover(zero_y,zero_x);
     BFS();
     printf("%d\n",ans);
    }
    

    
    fclose(stdin);
    fclose(stdout);
    return 0;
}


void scan()
{
     int i,a[9]={0};
     
     for(i=0;i<9;i++)
       scanf("%d",&a[i]);
       
     cc=&(line[0].game[0][0]);  
       
     for(i=0;i<9;i++)
       cc[i]=a[i];  
       

     line[0].step=0;
     
     r++;  
     
     
     
     
     for(i=0;i<9;i++)
       scanf("%d",&a[i]);
       
     
     cc=&(dream.game[0][0]);  
       
     for(i=0;i<9;i++)  
       cc[i]=a[i];
       
     
}

void in()
{
     line[r]=newr;
     r=(r+1)%100001;
     
}
void out()
{
     
     doe=line[f];
     f=(f+1)%100001;
       
}


void make_way()
{
     int i,j,x,y;
     
     for(i=0;i<3;i++)
      for(j=0;j<3;j++)
        if(doe.game[i][j]==0)
        { y=i,x=j;break; }
     zero_x=x,zero_y=y;
     
     for(i=0;i<4;i++)
     { 
       way[i][0]=0;
                     
       if(x+way[i][1]>=0 && x+way[i][1]<=2)
         if(y+way[i][2]>=0 && y+way[i][2]<=2)
           way[i][0]=1;
     }
     
}

int d(int a)
{
    int sum=1,i;   
    
    if(a==0)return 0;
    
    for(i=1;i<=a;i++)
       sum*=i;
       
    return sum;   
}
