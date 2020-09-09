
#include<stdio.h>
int main()
{
	int add(int [],int);
	int n;
	printf("Enter the no of elements in array\n");
	scanf("%d",&n);
	int A[n];
	printf("Enter the elements in array \n");
	for(int i=0;i<n;i++)
	scanf("%d",&A[i]);
	printf("sum of the even element is %d \n",add(A,n-1));
	
}
int add(int A[],int n)
{
	int sum=0,a;
	if(n==0)
	{
		if(A[0]%2==0)
		{
			return A[0];
		}
		else 
			return 0;
	}
	else if(A[n]%2==0)
	{
		sum=A[n]+add(A,n-1);
		return sum;
	}
	else
	{
		a=add(A,n-1);
		return a;
	}

}
