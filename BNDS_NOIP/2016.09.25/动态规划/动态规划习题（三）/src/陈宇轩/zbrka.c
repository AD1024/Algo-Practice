#include<stdio.h>

int n,c;
int f[1001][10001]={0};
int a[10001]={0};

int main()
{
	int i,j;
	
	freopen("zbrka.in","r",stdin);
	freopen("zbrka.out","w",stdout);
	
	scanf("%d%d",&n,&c);
	
	
	f[2][0]=1,f[2][1]=1;
	for(i=3;i<=n;i++)
	{
		a[0]=f[i-1][0];
	  for(j=1;j<=c;j++)	
		 {
		 a[j]=( a[j-1] + f[i-1][j] ) % 1000000007;
		 }
		
	  for(j=0;j<=c;j++)
	  {	 
		 //f[i][j]=sum(f[i-1][j-k] | 0<=k<i && j>=k)
         //f[i][j]=f[i-1][j]+f[i-1][j-1]+бн+f[i-1][j-i+1]
		  
		  if(j>=i)
		    {
		     if( a[j]>=a[j-i] )	
			  f[i][j] = a[j]-a[j-i];

			 else
			  f[i][j]=a[j]-a[j-i]+1000000007; 
            }
		  else
            {
			  f[i][j]=a[j];
			}
	  }
	}
	
	printf("%d",f[n][c]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
