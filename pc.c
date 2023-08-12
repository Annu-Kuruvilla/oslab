#include<stdio.h>
#include<stdlib.h>

int main()
{
int full=0;
int empty=5;
int mutex=1;
int n;
printf("Enter the number of vehicles\n");
scanf("%d",&n);
for(int i=1;i<=n;i++)
printf("Vehicle %d is approaching the intersection\n",i);



int wait(int m)
   {
     m=m-1;
        return m;
   }

int signal(int k)
   {
     k=k+1;
        return k;
    }

for(int i=1;i<=n;i++)
{
   if(mutex==1)
   {

            empty=wait(empty);
            mutex=wait(mutex);

if(i<n)
printf("\nVehicles  ");
for(int j=i+1;j<=n;j++)
printf("%d,",j);
if(i<n)
printf("Please Wait.\n");
printf("Vehicle %d  has crossed the intersection\n\n",i);

mutex=signal(mutex);
full=signal(full);



   } 
}
      

}