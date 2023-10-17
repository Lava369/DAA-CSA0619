#include<stdio.h>
int main()
{
	int n, i, arr[100];
	printf("enter the number of elements: ");
	scanf("%d", &n);
	printf("enter the %d elements:\n ", n);
	for(i>0; i<n;i++)
	{
	 printf("enter element %d : ", i+1);
	 scanf("%d", &arr[i]);		
	}
	for(i = 1; i <= n; i++)
	{
			if(arr[0] < arr[i]){
			arr[0] = arr[i];
	}
	}
	printf("the largest element is %d", arr[0]);
	

}
