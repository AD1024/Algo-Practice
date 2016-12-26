#include<stdio.h>

int n,a[100][100],b[100][100]={0},c[4][2]={{0,1},{1,0},{-1,0},{0,-1}},f=0;
void go(int x,int y)
{
     int i,k1,k2;
     if(x==n&&y==n)
       f=1;
     {
     if((x>0 && x<=n) && (y>0 && y<=n))
        for(i=0;i<4;i++)
           {
               k1=c[i][0];
               k2=c[i][1];
               if(a[x+k1][y+k2]==0&&b[x+k1][y+k2]==0)
                 {
                      b[x+k1][y+k2]=1;
                      go(x+k1,y+k2);               
                 }
           }
     }
}
int main()
{
    int t,j;
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    scanf("%d",&n);
     for(t=0;t<100;t++)
    {
       for(j=0;j<100;j++)
         a[t][j]=1;
    }
    for(t=1;t<=n;t++)
      { 
       for(j=1;j<=n;j++)
       scanf("%d",&a[t][j]);
       }
    for(t=0;t<100;t++)
    {
       for(j=0;j<100;j++)
         b[t][j]=0;                   
    }
   
    go(1,1);
    if(f==0)
      printf("NO");
    else
      printf("YES");
    fclose(stdin);
    fclose(stdout);        
}
