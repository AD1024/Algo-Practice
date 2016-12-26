#include <stdio.h>

int quality,ans;

int line[100001]={0},h,t;

int iteration[100001]={0};

int s[100001]={0},si=0;

int step[100001]={0};

int m[6]={1,2,3,5,10,20};
int f()
{
    int i,j,k,kg;
    while (h!=t)
    {
		kg=line[h++];
        for (i=0;i<6;i++)
          {
				if (kg+m[i]<=quality)
				{
					k=kg+m[i];
					if (iteration[k]!=1)
					{
						line[t++]=k;
						step[k]=step[kg]+1;
						iteration[k]=1;
						if (k==quality)
						{
							return step[k];
						}
					}
				}
		  }
    }
    return -1;
}


int main()
{
    freopen("weight.in","r",stdin);
    freopen("weight.out","w",stdout);
    scanf("%d",&quality);
    line[t++]=1;
    line[t++]=2;
    line[t++]=3;
    line[t++]=5;
    line[t++]=10;
    line[t++]=20;
    iteration[0]=1;
    iteration[1]=1;
    iteration[2]=1;
    iteration[3]=1;
    iteration[5]=1;
    iteration[10]=1;
    iteration[20]=1;
    step[1]=1;
    step[2]=1;
    step[3]=1;
    step[5]=1;
    step[10]=1;
    step[20]=1;
    ans=f();
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
