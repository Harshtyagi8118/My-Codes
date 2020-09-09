#include<stdio.h>
int main()
{
	int add(int);
	int a;
	printf("Enter a number : ");
	scanf("%d",&a);
	printf("sum of digits is %d \n",add(a));

}
int add(int a)
{
	int rem,sum;
	if(a>>0)
	{
	rem = a%10;
	sum = rem + add(a/10);
	
		return sum;
	}
	else 
		return 0;

}