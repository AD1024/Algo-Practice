#include <stdio.h>
int n,k;
int face;
int iteration[100001]={0};

int h=0,t=0,time=0;;
int line[100001]={0};
int tt[100001]={0};


int f()
{
     int i,j,num=0,num1;
while (h!=t)
{
     num1=line[h++];
     for (i=0;i<=k;i++)
     {
         if (i<=num1 && (k-i)<=(n-num1))
         {
            num=num1-i;
            num=num+(k-i);
            if (iteration[num]==0)
            {
             	line[t++]=num;
             	iteration[num]=1;
             	tt[num]=tt[num1]+1;
            }
            if (num==0)
            {
               return tt[num];
            }
         }
     }
}
return -1;
}


int main()
{
    int i,j,y;
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    scanf("%d%d%d",&n,&face,&k);
    if (k==0 && face!=0)
    {
		fclose(stdin);
    	fclose(stdout);
    	return 0;
	}
    iteration[face]=1;
    line[t++]=face;
    tt[face]=0;
    y=f();
    if (y!=-1)
    printf("%d\n",y);
    if (y==-1)
    printf("No solution!");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
