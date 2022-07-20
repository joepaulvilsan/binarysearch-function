#include <stdio.h>
#include <stdlib.h>
#include <time.h>
float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}
int binary(int data[],int key,int low,int high)
{
	
	int mid;
	while(low<=high)
	{
		 mid=(low+high)/2;    
		 if(data[mid]==key)
		 	return 1;
		 else if(data[mid]>key)
		 	high=mid-1;
		 else
		 	low=mid+1;
		 
		 
	}
	
}		 			
void main()
{
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
    int num,j;
    printf("enter no of random numbers");
    scanf("%d",&num);
    int data[num];
    srand( (unsigned) time(NULL) * getpid());
    for(j = 0; j < num; j++)
        {
            data[j]=rand()%100;
            printf("%d\n",data[j]);
        }
    

 
    int key,flag=0;
    printf("enter element to be searched");
    scanf("%d",&key);
    int low=0;
    int high=num;
    gettimeofday(&t0, NULL);
    int found=binary(data,key,low,high);
   
    if(found==1)
    	printf("element found");
   else
    	printf("element not found");
    gettimeofday(&t1, NULL);	
   elapsed = timedifference_msec(t0, t1);

   printf("\nCode executed in %f milliseconds.\n", elapsed);	
}

