#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* bin(int);
	int a,*b,c,*d,num=0,A[10],B[10];
	printf(" Enter a number a and b:");
	scanf("%d%d",&a,&c);
	b=bin(a);
	for(int i=0;i<10;i++)
	{
		printf("%d",*(b+i));
	
	}
	printf("\n");
	d=bin(c);
	for(int i=0;i<10;i++)
		{
			printf("%d",*(d+i));
			
		}
	printf("\n");
	for (int i=0;i<10;i++)
	{
		if((*(b+i))!=(*(d+i)))
		{		
				num++;
		}
	}
	printf("No of flips required is : %d  ",num);
	printf("\n");
}
int* bin(int a)
{
	int *A;
	A=(int*)malloc(10*sizeof(int));
	for (int i=0;i<10;i++)
			{
				A[9-i]=a%2;
				a/=2;
			}
	return A;
}
