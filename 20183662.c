#include <stdio.h>

int rfibo(int n)
{
	if(n==1 || n==2) return 1;
	return rfibo(n-1) + rfibo(n-2);
}

int *sfibo()
{
	static int small = 0, big = 1;
	big += small;
	small = big - small;
	return &small;
}

int main()
{
	int i;
	
	int *fibo = sfibo();
	
	for(i=3; i<=45; i+=2)
	{
		printf("rfibo(%d) = %d",i,rfibo(i));
		sfibo();
		sfibo();
		printf("\nsfibo(%d) = %d\n\n",i,*fibo);
	}
	
	return 0;
}
