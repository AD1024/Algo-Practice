#include<stdio.h>
#include<stdlib.h>
int x,y,z,hash[101][101],f=1,r=1,s1[100000],s2[100000],step[100000]={0},w=0;
int init()
{
   scanf("%d %d %d",&x,&y,&z);   
   s1[1]=x;
   hash[x][0]=1;
}
int check2(int i,int a,int b)
{
   if(i==1)
   {
      if(a!=0 || b!=y) return 0;
      else
      return 1;         
   } 
   if(i==2)
   {
      if(b!=0 || a!=x) return 0;
      else
      return 1;         
   } 
    if(i==3)
   {
      if(a!=x) return 0;
      else
      return 1;         
   } 
   if(i==4)
   {
      if(b!=y) return 0;
      else
      return 1;         
   } 
   if(i==5)
   {
      if(a!=0) return 0;
      else
      return 1;         
   }  
   if(i==6)
   {
      if(b!=0) return 0;
      else
      return 1;         
   } 
   
}
//int check(int i,int a,int b)
//{
//   if(i==3 && hash[x][b]==0) return 1;
//   if(i==4 && hash[a][y]==0) return 1;
 //  if(i==5 && hash[0][b]==0) return 1;
 //  if(i==6 && hash[a][0]==0) return 1;
 //  if(i==1)
 //  {
  //     if(s1[f]<x) 
  //       if(hash[0][s1[r]]==0) return 1;
    //   else
  //       if(hash[0][y]==0) return 1;       
   //}  
   //if(i==2)
  // {
  //     if(x-s1[f]>=y)
   //      if(hash[x][0]==0) return 1;
  //     else
   //      if(x-s1[f]<y)
  //         if(hash[x][y-(x-s1[f])]==0) return 1;             
  // }          
//   return 0;
//}
int turn(int i)
{
   int k;
   s1[r]=s1[f];s2[r]=s2[f];step[r]=step[f];
   if(i==3)
   {
      s1[r]=x;
   }
   if(i==4)
   {
      s2[r]=y;        
   }       
   if(i==5)
   {
      s1[r]=0;        
   } 
   if(i==6)
   {
      s2[r]=0;        
   } 
   if(i==1)
   {
      k=y-s2[r];
      if(k<=s1[r])
      {
         s1[r]-=k;
         s2[r]=y;            
      }    
      else
      {
         s2[r]+=s1[r];
         s1[r]=0;    
      }
   }
   if(i==2)
   {
       k=x-s1[r];
      if(k<=s2[r])
      {
         s2[r]-=k;
         s1[r]=x;            
      }    
      else
      {
         s1[r]+=s2[r];
         s2[r]=0;    
      }      
   }
   step[r]+=1;
}
int change()
{
   int i;
   while(f<=r)
   {
      for(i=1;i<=6;i++)
      {
         if(check2(i,s1[r],s2[r])==0)
         {
             r++;
             turn(i);
             if(hash[s1[r]][s2[r]]==1) r--;
             else
             if(s2[r]==z) {w=1;printf("%d",step[r]);return;}
             hash[s1[r]][s2[r]]=1;
         }
      }       
      f++;
   }   
}
int main()
{
   freopen("water.in","r",stdin);
   freopen("water.out","w",stdout);
   init();
   change();
   if(w==0) printf("No solution!");      
   fclose(stdin);
   fclose(stdout);
   return 0;    
}   

