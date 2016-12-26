#include <stdio.h>
int n,m,q[10001]={0},l=-1,r=0,t=0,b[51][51],p[10001]={0}; 
int flag=0,father[10001]={0};
struct 
{
   int x,y;       
}horse[10001]={0,0},f[4]={{2,1},{2,-1},{1,2},{1,-2}};
/*
void find(i)
{
    if (i<=0) return ;
	find(father[i]);
	printf ("%d %d\n",horse[i].x,horse[i].y);	
}
*/
void BFS()
{
   	int i,x,y;
	while(l<r)
   	{
   	   l++;
	   for (i=0;i<4;i++)
	   {
	   	  x=horse[q[l]].x+f[i].x;
	   	  y=horse[q[l]].y+f[i].y;
	   	  if (b[x][y]==0 && x<=n && y<=m && y>=1)
	   	  {
	   	     r++;
	   	     b[x][y]=1;
			 horse[++t].x=x;
			 horse[t].y=y;
			 q[r]=t;
			 p[r]=p[l]+1;
			 father[r]=l;
			 if (x==n && y==m)
			 {
		        printf ("%d\n",p[r]);
		      //  find(father[r]);
				flag=1;
		        l=r;
		        break;
			 }
	   	  }
	   }	
   	}
}
int main()
{
   freopen("knight.in","r",stdin);
   freopen("knight.out","w",stdout);
   scanf ("%d%d",&n,&m);
   horse[0].x=1;
   horse[0].y=1;
   BFS();
   if (flag==0)
      printf ("No solution!\n");
   fclose(stdin);
   fclose(stdout);
   return 0;   
}
