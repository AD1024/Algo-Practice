#include<stdio.h>
struct chess
{
    int p[2][4],step;  
}dream,doe,newr,line[10001]={0};

int *cp,*cq;
int kt[40321]={0};
int f=0,r=0,d[8]={0,1,2,6,24,120,720,5040};

int compare()
{
     int i;
     
     cp=&(newr.p[0][0]),cq=&(dream.p[0][0]);
     
     for(i=0;i<8;i++)
      { 
       if(cp[i]!=cq[i])return 0;        
      }
      
      return 1;
}

int discover()
{
     int i,j,k;
     int sum=0;
    
     cp=&(newr.p[0][0]);
     
     for(i=0;i<8;i++)
     {
         k=cp[i]-1;            
         for(j=i-1;j>=0;j--)            
             if(cp[j]<cp[i])k--;
             
         sum+=k*d[8-i-1];            
     }
    
     if(kt[sum]==0){kt[sum]=1;return 1;}
     else                     return 0;
    
}

void stop(){}

void out()
{
     doe=line[f];
     f=(f+1)%10001;
}

void in()
{
     line[r]=newr;
     r=(r+1)%10001;
}
void change(int t);
int BFS()
{
    int i;
    
     while(f!=r)
     {
        out();        
                
        for(i=1;i<=3;i++)        
        {      
            newr=doe;     
            change(i);
             newr.step++;
            
            if(newr.step==17)
               stop();
            
            if(compare())
               return newr.step;
            if(discover())
               in();   
        }
     
     }
     
     return -1;
}


int main()
{
    int i,ans;
    
    freopen("act.in","r",stdin);
    freopen("act.out","w",stdout);
    
    for(i=0;i<4;i++)
        dream.p[0][i]=i+1;
    for(i=0;i<4;i++)
        dream.p[1][i]=8-i;
        
    
    
    cp=&(newr.p[0][0]);    
    for(i=0;i<8;i++)
      scanf("%d",cp++);
    newr.step=0;      
    if(discover())in();
    
    
    if(compare())
    {
       printf("0");          
    }
    else
    {
       ans=BFS();
       if(ans<0)printf("No solution!");
       else     printf("%d",ans); 
    }
    
    
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void change(int t)
{
     int i,e,l;
     cp=&(newr.p[0][0]); 
     
     if(t==1)//向右移动一个单位 
     { 
       e=cp[3],l=cp[7];                         
       for(i=2;i>=0;i--)
         cp[i+1]=cp[i],cp[i+5]=cp[i+4];
       cp[0]=e,cp[4]=l;      
                                
     }
     if(t==2)//上下互换 
     {
       for(i=0;i<4;i++)
          {e=cp[i];cp[i]=cp[i+4];cp[i+4]=e;}                 
     }
     if(t==3)//顺时针旋转
     {
        e=cp[1];
        cp[1]=cp[5];
        cp[5]=cp[6];
        cp[6]=cp[2];
        cp[2]=e;                 
     }
}

