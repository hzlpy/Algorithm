#include <stdio.h>
#define MAX 100000
int main(void)
{
	int count = 0;
	int number[MAX];
	int x = 0;
	int i = 0;
	int j = 0; 
	int k = 0;
	int sum = 0;
	int max = 0;
	printf("Please enter a number: ");
	scanf("%d",&count);
	printf("Please enter %d number: ",count);
	for (i=0; i<count; ++i)
	{
		scanf("%d",&number[i]);
	}
	for (i=0; i<count; ++i)
	{
		for (j=i; j<count; ++j)
		{
			for (k=i; k<=j; ++k)
			{
				sum = number[k] + sum;
			}
			if (sum > max)
			{
				max = sum;
			}
			sum = 0;
		}
	}
	printf("%d \n",max);
	return 0;
}