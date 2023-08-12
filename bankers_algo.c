#include<stdio.h>
void main()
{
 int n,r,i,j,alloc[10][10],max[10][10],need[10][10],available[10],work[10],finish[10],k,flag,safesequence[10],id=0;
 printf("Enter the number of processes: ");
 scanf("%d",&n);
 printf("Enter the number of resources: ");
 scanf("%d",&r);
 printf("Enter the allocation matrix\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<r;j++)
  {
   scanf("%d",&alloc[i][j]);
  }
 }
 printf("Enter the max matrix\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<r;j++)
  {
   scanf("%d",&max[i][j]);
  }
 }
 
 printf("Enter the available matrix\n");
 for(i=0;i<r;i++)
 {
  scanf("%d",&available[i]);
  work[i]=available[i];
 }
  
 printf("Need Matrix\n");
  for(i=0;i<n;i++)
 {
  for(j=0;j<r;j++)
  {
   need[i][j]=max[i][j]-alloc[i][j];
   printf("%d ",need[i][j]);
  }
  printf("\n");
 }
 
 for(i=0;i<n;i++)
  finish[i]=0;
  




for(k=0;k<n;k++)//for ensuring every process is getting chance ie there might be cases like  initially the need of P2 is greater than avail but later avail will be sufficient
{
 for(i=0;i<n;i++)//for considering each process
 {
  if(finish[i]==0)
  {
   flag=0;
   for(j=0;j<r;j++)
   {
    
    if(need[i][j]>work[j])
    {
     flag=1;
     break;
    }
   }
   if(flag==0)
   {
    safesequence[id++]=i;

    
    for(j=0;j<r;j++)
    {
     work[j]=work[j]+alloc[i][j];
     finish[i]=1;
    }
   }
  }
  }
 }
 printf("\nFollowing is the SAFE Sequence\n");
 for (i = 0; i <n; i++)
 printf(" P%d ", safesequence[i]);
}














    
    
    
    
    
    
    
    
    
    
    
    
    
    
