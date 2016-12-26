#include<stdio.h>
struct
{
      int a,b;
      int step;
}line[10001]={0},doe,newr;

int f=0,r=0;
int x,y,z,d[101][101]={0};


void in(int a,int b,int t);
void in_();
void out();
void p(int t)
{
     if(t==1)//F->X 
        newr.a=x;
     if(t==2)//F->Y 
        newr.b=y;
     if(t==3)//X->F
        newr.a=0; 
     if(t==4)//Y->F
        newr.b=0;
     if(t==5)//X->Y 
       {
        newr.b+=newr.a;
        if(newr.b>y)
          newr.a=newr.b-y,newr.b=y;
        else
          newr.a=0; 
            
       }
     if(t==6)//Y->X 
       {
        newr.a+=newr.b;
        if(newr.a>x)
          newr.b=newr.a-x,newr.a=x;
        else
          newr.b=0; 
             
       }
}


int BFS()
{
    int i;
    
    while(f!=r)
    {
      out();   
      
      for(i=1;i<=6;i++)
      {
         newr=doe;              
         p(i);
         newr.step++;              
                       
         if(newr.b==z)
           return newr.step;
         
         if(d[newr.a][newr.b]==0)
           {in_(); d[newr.a][newr.b]=1; }            
                       
      } 
       
    }
    
    return -1;
}


int main()
{
    int ans;
    
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    
    scanf("%d%d",&x,&y);
    scanf("%d",&z);
    
    in(x,0,0);
    d[x][0]=1;
    
    if(y==z)
       printf("0");
    else
    {   
        ans=BFS();
        
        if(ans>0)
          printf("%d",ans);
        else
          printf("No solution!");  
     }
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}


void in(int a,int b,int t)
{
     line[r].a=a,line[r].b=b,line[r].step=t;
     
     r=(r+1)%10001;
}

void in_()
{
     line[r]=newr;
     
     r=(r+1)%10001;
}
void out()
{
     doe=line[f];
     
     f=(f+1)%10001;
     
}
