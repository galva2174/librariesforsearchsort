#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void ssort(int*,int,int);
void iterativessort(int*,int);
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
 ssort(a,0,n);
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
 iterativessort(a,n);
 clock_gettime(CLOCK_REALTIME,&stop);
 printf("\nAfter sorting...\n");
 for(i=0;i<n;i++)
   printf(" %d",a[i]);
time=(stop.tv_sec-start.tv_sec)+(double)(stop.tv_nsec-start.tv_nsec)/nano;
 printf("\nTime = %lf seconds",time);
}
void ssort(int *a,int i, int n)
{
    if(i==n-1)
    {
        return;
    }
    int pos = i;
    for(int j=i+1;j<n;j++)
    {
            if(a[j]<a[pos])
            {
                pos = j;
            }
            if(pos!=i)
            {
                int temp = a[i];
                a[i] = a[pos];
                a[pos] = temp;
            }
    }
    ssort(a,i+1,n);
}
void iterativessort(int *a,int n)
{
    int flag,pos;
    for(int i =0;i<n-1;i++)
    {  
        for(int j=i+1;j<n;j++)
        {
           if(a[j]<a[pos])
           {
            
            pos =j;
           }
        }
        if(pos!=i)
        {
        int temp = a[i];
        a[i] = a[pos];
        a[pos] = temp;
        }
    }
}
//takes lesser time thatn bubble sort. 
//iterative sort is faster because in recursion, calling return address from stack also takes extra time which is not there in iterative