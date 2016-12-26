#include<stdio.h>
int n,m;
int f[61][3200]={0};
int kp[100]={0};

struct
{
	int value[4],cost[4];
}th[100]={0};
int th_lence;
//th[i][0]_main
//th[i][1]_main_other1
//th[i][2]_main_other2
//th[i][3]_main_other 1&2


void main_to_other()
{
	int i,j,v,p,q;
	
	
	for(i=1;i<=m;i++)
	{
	   	scanf("%d%d%d",&v,&p,&q);
	   	p=v*p/10;
	   	v/=10;
	   	
		if(q==0)
		{
			for(j=0;j<4;j++)
			 th[i].value[j]+=p,th[i].cost[j]+=v;
	    }
		else
		{
			if(kp[q]==0)
			{
			  th[q].value[1]+=p,th[q].cost[1]+=v;
		      th[q].value[3]+=p,th[q].cost[3]+=v;
			  kp[q]=1;
			}
			else
			{
			  th[q].value[2]+=p,th[q].cost[2]+=v;
		      th[q].value[3]+=p,th[q].cost[3]+=v;
			}
	    }
	}
	
	j=1;
	for(i=1;i<=m;i++)
	{
	    if(th[i].value[0]!=0)
		  th[j++]=th[i];		 
	}
	th_lence=j-1;
	
}

int the_0_1_bag()
{
	int i,j,k,p;
	
	for(i=1;i<=th_lence;i++)
	  for(j=1;j<=n;j++)
	  {
	  	f[i][j]=f[i-1][j];
	  	
	  	
	  	if(j-th[i].cost[0]>=0)
		  { 
		  p=f[i-1][j-th[i].cost[0]]+th[i].value[0];
		  
		  if(p >f[i][j])
	  	   f[i][j]=p;
	      }
	      
	      
	  	   for(k=1;k<4;k++)
	  	   {
	  	    	 if(th[i].value[k])
		    	{	   
			         if(j-th[i].cost[k]>=0)
		     	 { 
		        	 p=f[i-1][j-th[i].cost[k]]+th[i].value[k];
		
		        	 if( p>f[i][j])
	  	   	         f[i][j]=p;
	  	    
		     	  }
		        }
	  	        
				  else break;
	  	   }
	  	
	  }
	
	return f[th_lence][n]*10;
}

int main()
{
	int max;
	
	freopen("budget.in","r",stdin);
    freopen("budget.out","w",stdout); 
    
    scanf("%d%d",&n,&m);
    n/=10;
    
    main_to_other(); 
    
	max=the_0_1_bag();
    
    printf("%d",max);
    
    fclose(stdin); 
    fclose(stdout);
     return 0;
}
