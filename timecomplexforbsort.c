#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void bsort(int*,int);
void iterativebsort(int*,int);
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
 printf("Before sorting..\n");
 for(i=0;i<n;++i)
  printf("%d ",a[i]);
 clock_gettime(CLOCK_REALTIME,&start);
 bsort(a,n);
 clock_gettime(CLOCK_REALTIME,&stop);
 printf("\nAfter sorting...\n");
 for(i=0;i<n;i++)
   printf(" %d",a[i]);
time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano;
 printf("\nTime = %lf seconds",time);



 //for iterative
  for(i=0;i<n;i++)
   a[i]=rand()%100;
 printf("Before sorting..\n");
 for(i=0;i<n;++i)
  printf("%d ",a[i]);
 clock_gettime(CLOCK_REALTIME,&start);
 iterativebsort(a,n);
 clock_gettime(CLOCK_REALTIME,&stop);
 printf("\nAfter sorting...\n");
 for(i=0;i<n;i++)
   printf(" %d",a[i]);
time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano;
 printf("\nTime = %lf seconds..\n",time);
}
void bsort(int *a,int n)
{
    if(n==1)
    {
        return;
    }
    int flag = 0;
    for(int j=0;j<n-1;j++)
    {
        if(a[j]>a[j+1])
        {
            flag = 1;
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
    }
    if(flag==1)
    {
        bsort(a,n-1);
    }
}
void iterativebsort(int *a,int n)
{
    int flag;
    for(int i =0;i<n-1;i++)
    {   flag = 0;
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
        {
            flag = 1;
            int temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
        }
        if(flag ==0)
        {
            break;
        }
    }
    
}
//iterative sort is faster because in recursion, calling return address from stack also takes extra time which is not there in interative