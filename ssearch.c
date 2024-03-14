//first occurence, last occurence, count of occurence of given input
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void recursive(int*,int,int);
#define nano 1000000000L
int main()
{  
 int a[1000000];
 int i,n;
  double time ;
 struct timespec start, stop;
 n=100;
 for(i=0;i<n;i++)
   a[i]=rand()%100;
 printf("Given array..\n");
 for(i=0;i<n;++i)
  printf("%d ",a[i]);
int k = 0;
printf("\nEnter key");
scanf("%d",k);
clock_gettime(CLOCK_REALTIME,&start);
iterative(*a,n,k);
clock_gettime(CLOCK_REALTIME,&stop);
time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano;
printf("\nTime = %lf seconds",time);
}

void iterative(int *a,int n, int key)
{   int s,h,c=0,flag=0;
    for(int i =0;i<n;i++)
    {
        if(a[i] == key)
        {
            h = i;
            if(flag == 0)
            {
                s= i;
                flag = 1;
            }
            c++;
        }
    }
    printf("First occurence=%d ",s);
    printf("last occurence=%d ",h);
    printf("total occurence=%d ",c);
}
 