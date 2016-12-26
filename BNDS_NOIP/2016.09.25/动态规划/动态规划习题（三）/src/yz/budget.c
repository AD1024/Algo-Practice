#include<stdio.h>
int a,b,c,i,j,n,m,f[65][32005]={0},v1[5][65]={0},w1[5][65]={0};
int main()
{   
    freopen("budget.in","r",stdin);
	freopen("budget.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
     scanf("%d %d %d",&a,&b,&c);
     if(c==0)
     {
      v1[1][i]=a*b;
      w1[1][i]=a;
     }
     else
     {
      if(v1[2][c]==0)
      {
       v1[2][c]=a*b;
       w1[2][c]=a;   
      }
      else
      {
       v1[3][c]=a*b;
       w1[3][c]=a;
      }
     }
    }
    for(i=1;i<=n;i++)
     f[0][i]=0;
    for(i=1;i<=m;i++)
    {
	 v1[4][i]+=v1[1][i]+v1[2][i]+v1[3][i];
	 w1[4][i]+=w1[1][i]+w1[2][i]+w1[3][i];
	 v1[2][i]+=v1[1][i];
	 w1[2][i]+=w1[1][i];
	 v1[3][i]+=v1[1][i];
	 w1[3][i]+=w1[1][i];
    } 
    for(i=1;i<=m;i++)
    {
     for(j=1;j<=n;j++)
     {
      f[i][j]=f[i-1][j];
      if(  j-w1[1][i]>=0  )
       if(  f[i-1][j-w1[1][i]]+v1[1][i]>f[i][j]  )
        f[i][j]=f[i-1][j-w1[1][i]]+v1[1][i];
      if(  j-w1[2][i]>=0  )
       if(  f[i-1][j-w1[2][i]]+v1[2][i]>f[i][j]  )
        f[i][j]=f[i-1][j-w1[2][i]]+v1[2][i];
      if(  j-w1[3][i]>=0  )      
       if(  f[i-1][j-w1[3][i]]+v1[3][i]>f[i][j])
        f[i][j]=f[i-1][j-w1[3][i]]+v1[3][i];
      if(  j-w1[4][i]>=0   )
       if(  f[i-1][j-w1[4][i]]+v1[4][i]>f[i][j]  )
        f[i][j]=f[i-1][j-w1[4][i]]+v1[4][i];     
     }
    } 
    printf("%d ",f[m][n]);
   	fclose(stdin);
	fclose(stdout);    
    return 0;
} 
