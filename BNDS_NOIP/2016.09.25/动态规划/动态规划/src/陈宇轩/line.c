#include<stdio.h>
int main()
{
	int n,s[10001]={0};
	int i,j,f[10001]={0},max=0;
	
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&s[i]);
	
	
	f[1]=1;
	
	for(i=2;i<=n;i++)
	{
	   f[i]=1;	
	
	  for(j=1;j<i;j++)
	 	if(s[i]>=s[j])
			   {
			   	if(f[i]<=f[j])
			        f[i]=f[j]+1;
			   }
    }
    
    for(i=1;i<=n;i++)
      if(f[i]>max)max=f[i];
    
	printf("%d",max); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
